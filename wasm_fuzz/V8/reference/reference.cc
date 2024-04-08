void GenerateTestCase(Isolate* isolate, ModuleWireBytes wire_bytes,
                      bool compiles) {
  constexpr bool kVerifyFunctions = false;
  auto enabled_features = WasmFeatures::FromIsolate(isolate);
  ModuleResult module_res = DecodeWasmModule(
      enabled_features, wire_bytes.module_bytes(), kVerifyFunctions,
      ModuleOrigin::kWasmOrigin, kPopulateExplicitRecGroups);
  CHECK_WITH_MSG(module_res.ok(), module_res.error().message().c_str());
  WasmModule* module = module_res.value().get();
  CHECK_NOT_NULL(module);

  AccountingAllocator allocator;
  Zone zone(&allocator, "constant expression zone");

  StdoutStream os;

  tzset();
  time_t current_time = time(nullptr);
  struct tm current_localtime;
#ifdef V8_OS_WIN
  localtime_s(&current_localtime, &current_time);
#else
  localtime_r(&current_time, &current_localtime);
#endif
  int year = 1900 + current_localtime.tm_year;

  os << "// Copyright " << year
     << " the V8 project authors. All rights reserved.\n"
        "// Use of this source code is governed by a BSD-style license that "
        "can be\n"
        "// found in the LICENSE file.\n"
        "\n"
        "// Flags: --wasm-staging\n"
        "\n"
        "d8.file.execute('test/mjsunit/wasm/wasm-module-builder.js');\n"
        "\n"
        "const builder = new WasmModuleBuilder();\n";

  int recursive_group_end = -1;
  for (int i = 0; i < static_cast<int>(module->types.size()); i++) {
    auto rec_group = module->explicit_recursive_type_groups.find(i);
    if (rec_group != module->explicit_recursive_type_groups.end()) {
      os << "builder.startRecGroup();\n";
      recursive_group_end = rec_group->first + rec_group->second - 1;
    }
    if (module->has_struct(i)) {
      const StructType* struct_type = module->types[i].struct_type;
      os << "builder.addStruct([";
      int field_count = struct_type->field_count();
      for (int index = 0; index < field_count; index++) {
        os << "makeField(" << ValueTypeToConstantName(struct_type->field(index))
           << ", " << (struct_type->mutability(index) ? "true" : "false")
           << ")";
        if (index + 1 < field_count) os << ", ";
      }
      os << "], ";
      if (module->types[i].supertype != kNoSuperType) {
        os << module->types[i].supertype;
      } else {
        os << "kNoSuperType";
      }
      os << ", " << (module->types[i].is_final ? "true" : "false") << ");\n";
    } else if (module->has_array(i)) {
      const ArrayType* array_type = module->types[i].array_type;
      os << "builder.addArray("
         << ValueTypeToConstantName(array_type->element_type()) << ", "
         << (array_type->mutability() ? "true" : "false") << ", ";
      if (module->types[i].supertype != kNoSuperType) {
        os << module->types[i].supertype;
      } else {
        os << "kNoSuperType";
      }
      os << ", " << (module->types[i].is_final ? "true" : "false") << ");\n";
    } else {
      DCHECK(module->has_signature(i));
      const FunctionSig* sig = module->types[i].function_sig;
      os << "builder.addType(makeSig(" << PrintParameters(sig) << ", "
         << PrintReturns(sig) << "));\n";
    }

    if (i == recursive_group_end) {
      os << "builder.endRecGroup();\n";
    }
  }

  for (WasmImport imported : module->import_table) {
    // TODO(wasm): Support other imports when needed.
    CHECK_EQ(kExternalFunction, imported.kind);
    auto module_name = PrintName(wire_bytes, imported.module_name);
    auto field_name = PrintName(wire_bytes, imported.field_name);
    int sig_index = module->functions[imported.index].sig_index;
    os << "builder.addImport(" << module_name << ", " << field_name << ", "
       << sig_index << " /* sig */);\n";
  }

  for (const WasmMemory& memory : module->memories) {
    os << "builder.addMemory(" << memory.initial_pages;
    if (memory.has_maximum_pages) {
      os << ", " << memory.maximum_pages;
    } else {
      os << ", undefined";
    }
    if (memory.is_shared) {
      os << ", true";
    }
    os << ");\n";
  }

  for (WasmDataSegment segment : module->data_segments) {
    base::Vector<const uint8_t> data = wire_bytes.module_bytes().SubVector(
        segment.source.offset(), segment.source.end_offset());
    if (segment.active) {
      // TODO(wasm): Add other expressions when needed.
      CHECK_EQ(ConstantExpression::kI32Const, segment.dest_addr.kind());
      os << "builder.addActiveDataSegment(0, ";
      DecodeAndAppendInitExpr(os, &zone, module, wire_bytes, segment.dest_addr,
                              kWasmI32);
      os << ", ";
    } else {
      os << "builder.addPassiveDataSegment(";
    }
    os << "[";
    if (!data.empty()) {
      os << unsigned{data[0]};
      for (unsigned byte : data + 1) os << ", " << byte;
    }
    os << "]";
    if (segment.shared) os << ", true";
    os << ");\n";
  }

  for (WasmGlobal& global : module->globals) {
    os << "builder.addGlobal(" << ValueTypeToConstantName(global.type) << ", "
       << global.mutability << ", " << global.shared << ", ";
    DecodeAndAppendInitExpr(os, &zone, module, wire_bytes, global.init,
                            global.type);
    os << ");\n";
  }

  Zone tmp_zone(isolate->allocator(), ZONE_NAME);

  for (const WasmTable& table : module->tables) {
    os << "builder.addTable(" << ValueTypeToConstantName(table.type) << ", "
       << table.initial_size << ", "
       << (table.has_maximum_size ? std::to_string(table.maximum_size)
                                  : "undefined")
       << ", ";
    if (table.initial_value.is_set()) {
      DecodeAndAppendInitExpr(os, &zone, module, wire_bytes,
                              table.initial_value, table.type);
    } else {
      os << "undefined";
    }
    if (table.shared) os << ", true";
    os << ");\n";
  }
  for (const WasmElemSegment& elem_segment : module->elem_segments) {
    const char* status_str =
        elem_segment.status == WasmElemSegment::kStatusActive
            ? "Active"
            : elem_segment.status == WasmElemSegment::kStatusPassive
                  ? "Passive"
                  : "Declarative";
    os << "builder.add" << status_str << "ElementSegment(";
    if (elem_segment.status == WasmElemSegment::kStatusActive) {
      os << elem_segment.table_index << ", ";
      DecodeAndAppendInitExpr(os, &zone, module, wire_bytes,
                              elem_segment.offset, kWasmI32);
      os << ", ";
    }
    os << "[";
    ModuleDecoderImpl decoder(WasmFeatures::All(),
                              wire_bytes.module_bytes().SubVectorFrom(
                                  elem_segment.elements_wire_bytes_offset),
                              ModuleOrigin::kWasmOrigin);
    for (uint32_t i = 0; i < elem_segment.element_count; i++) {
      ConstantExpression expr =
          decoder.consume_element_segment_entry(module, elem_segment);
      if (elem_segment.element_type == WasmElemSegment::kExpressionElements) {
        DecodeAndAppendInitExpr(os, &zone, module, wire_bytes, expr,
                                elem_segment.type);
      } else {
        os << expr.index();
      }
      if (i < elem_segment.element_count - 1) os << ", ";
    }
    os << "], "
       << (elem_segment.element_type == WasmElemSegment::kExpressionElements
               ? ValueTypeToConstantName(elem_segment.type)
               : "undefined");
    if (elem_segment.shared) os << ", true";
    os << ");\n";
  }

  for (const WasmTag& tag : module->tags) {
    os << "builder.addTag(makeSig(" << PrintParameters(tag.ToFunctionSig())
       << ", []));\n";
  }

  for (const WasmFunction& func : module->functions) {
    if (func.imported) continue;

    base::Vector<const uint8_t> func_code = wire_bytes.GetFunctionBytes(&func);
    os << "// Generate function " << (func.func_index + 1) << " (out of "
       << module->functions.size() << ").\n";

    // Add function.
    os << "builder.addFunction(undefined, " << func.sig_index
       << " /* sig */)\n";

    // Add locals.
    BodyLocalDecls decls;
    DecodeLocalDecls(enabled_features, &decls, func_code.begin(),
                     func_code.end(), &tmp_zone);
    if (decls.num_locals) {
      os << "  ";
      for (size_t pos = 0, count = 1, locals = decls.num_locals; pos < locals;
           pos += count, count = 1) {
        ValueType type = decls.local_types[pos];
        while (pos + count < locals && decls.local_types[pos + count] == type) {
          ++count;
        }
        os << ".addLocals(" << ValueTypeToConstantName(type) << ", " << count
           << ")";
      }
      os << "\n";
    }

    // Add body.
    os << "  .addBodyWithEnd([\n";

    constexpr bool kIsShared = false;  // TODO(14616): Extend this.
    FunctionBody func_body(func.sig, func.code.offset(), func_code.begin(),
                           func_code.end(), kIsShared);
    PrintRawWasmCode(isolate->allocator(), func_body, module, kOmitLocals);
    os << "]);\n";
  }

  for (WasmExport& exp : module->export_table) {
    switch (exp.kind) {
      case kExternalFunction:
        os << "builder.addExport(" << PrintName(wire_bytes, exp.name) << ", "
           << exp.index << ");\n";
        break;
      case kExternalMemory:
        os << "builder.exportMemoryAs(" << PrintName(wire_bytes, exp.name)
           << ", " << exp.index << ");\n";
        break;
      default:
        os << "// Unsupported export of '" << PrintName(wire_bytes, exp.name)
           << "'.\n";
        break;
    }
  }

  if (compiles) {
    os << "let kBuiltins = { builtins: ['js-string', 'text-decoder', "
          "'text-encoder'] };\n"
          "const instance = builder.instantiate({}, kBuiltins);\n"
          "try {\n"
          "  print(instance.exports.main(1, 2, 3));\n"
          "} catch (e) {\n"
          "  print('caught exception', e);\n"
          "}\n";
  } else {
    os << "assertThrows(function() { builder.instantiate(); }, "
          "WebAssembly.CompileError);\n";
  }
}
