let unknown lexbuf = error lexbuf ("unknown operator " ^ Lexing.lexeme lexbuf)

let vec_type = function
  | "v128" -> Types.V128Type
  | _ -> assert false

let v128op s i8x16 i16x8 i32x4 i64x2 f32x4 f64x2 =
  match s with
  | "i8x16" -> i8x16
  | "i16x8" -> i16x8
  | "i32x4" -> i32x4
  | "i64x2" -> i64x2
  | "f32x4" -> f32x4
  | "f64x2" -> f64x2
  | _ -> assert false

let v128intop s i8x16 i16x8 i32x4 i64x2 =
  match s with
  | "i8x16" -> i8x16
  | "i16x8" -> i16x8
  | "i32x4" -> i32x4
  | "i64x2" -> i64x2
  | _ -> assert false

let v128floatop s f32x4 f64x2 =
  match s with
  | "f32x4" -> f32x4
  | "f64x2" -> f64x2
  | _ -> assert false

let v128_shape = function
  | "i8x16" -> V128.I8x16 ()
  | "i16x8" -> V128.I16x8 ()
  | "i32x4" -> V128.I32x4 ()
  | "i64x2" -> V128.I64x2 ()
  | "f32x4" -> V128.F32x4 ()
  | "f64x2" -> V128.F64x2 ()
  | _ -> assert false

let only shapes s lexbuf =
  if not (List.mem s shapes) then
    unknown lexbuf

let except shapes s lexbuf =
  if (List.mem s shapes) then
    unknown lexbuf
}


let v128_int_shape = "i8x16" | "i16x8" | "i32x4" | "i64x2"
let v128_float_shape = "f32x4" | "f64x2"
let v128_shape = v128_int_shape | v128_float_shape

rule token = parse
  | "extern" { EXTERN }
  | "externref" { EXTERNREF }
  | vxxx as t { VEC_TYPE (vec_type t) }

  | v128_shape as s { VEC_SHAPE (v128_shape s) }


  | vxxx".const"
    { let open Source in
      VEC_CONST
        (fun shape ss at ->
          let v = V128.of_strings shape (List.map (fun s -> s.it) ss) in
          (v128_const (v @@ at), Values.V128 v))
    }


  | "ref.null" { REF_NULL }
  | "ref.func" { REF_FUNC }
  | "ref.extern" { REF_EXTERN }
  | "ref.is_null" { REF_IS_NULL }

  | "table.get" { TABLE_GET }
  | "table.set" { TABLE_SET }
  | "table.size" { TABLE_SIZE }
  | "table.grow" { TABLE_GROW }
  | "table.fill" { TABLE_FILL }
  | "table.copy" { TABLE_COPY }
  | "table.init" { TABLE_INIT }
  | "elem.drop" { ELEM_DROP }


  | "memory.fill" { MEMORY_FILL }
  | "memory.copy" { MEMORY_COPY }
  | "memory.init" { MEMORY_INIT }
  | "data.drop" { DATA_DROP }


  | "v128.load"
    { VEC_LOAD (fun a o -> (v128_load (opt a 4)) o) }
  | "v128.store"
    { VEC_STORE (fun a o -> (v128_store (opt a 4)) o) }
  | "v128.load8x8_"(sign as s)
    { VEC_LOAD (fun a o -> (ext s v128_load8x8_s v128_load8x8_u (opt a 3)) o) }
  | "v128.load16x4_"(sign as s)
    { VEC_LOAD (fun a o -> (ext s v128_load16x4_s v128_load16x4_u (opt a 3)) o) }
  | "v128.load32x2_"(sign as s)
    { VEC_LOAD (fun a o -> (ext s v128_load32x2_s v128_load32x2_u (opt a 3)) o) }
  | "v128.load8_splat"
    { VEC_LOAD (fun a o -> (v128_load8_splat (opt a 0)) o) }
  | "v128.load16_splat"
    { VEC_LOAD (fun a o -> (v128_load16_splat (opt a 1)) o) }
  | "v128.load32_splat"
    { VEC_LOAD (fun a o -> (v128_load32_splat (opt a 2)) o) }
  | "v128.load64_splat"
    { VEC_LOAD (fun a o -> (v128_load64_splat (opt a 3)) o) }
  | "v128.load32_zero"
    { VEC_LOAD (fun a o -> (v128_load32_zero (opt a 2)) o) }
  | "v128.load64_zero"
    { VEC_LOAD (fun a o -> (v128_load64_zero (opt a 3)) o) }
  | "v128.load8_lane"
    { VEC_LOAD_LANE (fun a o i -> (v128_load8_lane (opt a 0)) o i) }
  | "v128.load16_lane"
    { VEC_LOAD_LANE (fun a o i -> (v128_load16_lane (opt a 1)) o i) }
  | "v128.load32_lane"
    { VEC_LOAD_LANE (fun a o i -> (v128_load32_lane (opt a 2)) o i) }
  | "v128.load64_lane"
    { VEC_LOAD_LANE (fun a o i -> (v128_load64_lane (opt a 3)) o i) }
  | "v128.store8_lane"
    { VEC_STORE_LANE (fun a o i -> (v128_store8_lane (opt a 0)) o i) }
  | "v128.store16_lane"
    { VEC_STORE_LANE (fun a o i -> (v128_store16_lane (opt a 1)) o i) }
  | "v128.store32_lane"
    { VEC_STORE_LANE (fun a o i -> (v128_store32_lane (opt a 2)) o i) }
  | "v128.store64_lane"
    { VEC_STORE_LANE (fun a o i -> (v128_store64_lane (opt a 3)) o i) }


  | (ixx as t)".extend8_s" { UNARY (intop t i32_extend8_s i64_extend8_s) }
  | (ixx as t)".extend16_s" { UNARY (intop t i32_extend16_s i64_extend16_s) }
  | "i64.extend32_s" { UNARY i64_extend32_s }

  | (ixx as t)".trunc_sat_f32_s"
    { CONVERT (intop t i32_trunc_sat_f32_s i64_trunc_sat_f32_s) }
  | (ixx as t)".trunc_sat_f32_u"
    { CONVERT (intop t i32_trunc_sat_f32_u i64_trunc_sat_f32_u) }
  | (ixx as t)".trunc_sat_f64_s"
    { CONVERT (intop t i32_trunc_sat_f64_s i64_trunc_sat_f64_s) }
  | (ixx as t)".trunc_sat_f64_u"
    { CONVERT (intop t i32_trunc_sat_f64_u i64_trunc_sat_f64_u) }

  | vxxx".not" { VEC_UNARY v128_not }
  | vxxx".and" { VEC_UNARY v128_and }
  | vxxx".andnot" { VEC_UNARY v128_andnot }
  | vxxx".or" { VEC_UNARY v128_or }
  | vxxx".xor" { VEC_UNARY v128_xor }
  | vxxx".bitselect" { VEC_TERNARY v128_bitselect }
  | vxxx".any_true" { VEC_TEST (v128_any_true) }

  | (v128_shape as s)".neg"
    { VEC_UNARY
        (v128op s i8x16_neg i16x8_neg i32x4_neg i64x2_neg f32x4_neg f64x2_neg) }
  | (v128_float_shape as s)".sqrt"
    { VEC_UNARY (v128floatop s f32x4_sqrt f64x2_sqrt) }
  | (v128_float_shape as s)".ceil"
    { VEC_UNARY (v128floatop s f32x4_ceil f64x2_ceil) }
  | (v128_float_shape as s)".floor"
    { VEC_UNARY (v128floatop s f32x4_floor f64x2_floor) }
  | (v128_float_shape as s)".trunc"
    { VEC_UNARY (v128floatop s f32x4_trunc f64x2_trunc) }
  | (v128_float_shape as s)".nearest"
    { VEC_UNARY (v128floatop s f32x4_nearest f64x2_nearest) }
  | (v128_shape as s)".abs"
    { VEC_UNARY
        (v128op s i8x16_abs i16x8_abs i32x4_abs i64x2_abs f32x4_abs f64x2_abs) }
  | "i8x16.popcnt" { VEC_UNARY i8x16_popcnt }
  | (v128_int_shape as s)".avgr_u"
    { only ["i8x16"; "i16x8"] s lexbuf;
      VEC_UNARY (v128intop s i8x16_avgr_u i16x8_avgr_u unreachable unreachable) }
  | "i32x4.trunc_sat_f32x4_"(sign as s)
    { VEC_UNARY (ext s i32x4_trunc_sat_f32x4_s i32x4_trunc_sat_f32x4_u) }
  | "i32x4.trunc_sat_f64x2_"(sign as s)"_zero"
    { VEC_UNARY (ext s i32x4_trunc_sat_f64x2_s_zero i32x4_trunc_sat_f64x2_u_zero) }
  | "f64x2.promote_low_f32x4"
    { VEC_UNARY f64x2_promote_low_f32x4 }
  | "f32x4.demote_f64x2_zero"
    { VEC_UNARY f32x4_demote_f64x2_zero }
  | "f32x4.convert_i32x4_"(sign as s)
    { VEC_UNARY (ext s f32x4_convert_i32x4_s f32x4_convert_i32x4_u) }
  | "f64x2.convert_low_i32x4_"(sign as s)
    { VEC_UNARY (ext s f64x2_convert_low_i32x4_s f64x2_convert_low_i32x4_u) }
  | "i16x8.extadd_pairwise_i8x16_"(sign as s)
    { VEC_UNARY (ext s i16x8_extadd_pairwise_i8x16_s i16x8_extadd_pairwise_i8x16_u) }
  | "i32x4.extadd_pairwise_i16x8_"(sign as s)
    { VEC_UNARY (ext s i32x4_extadd_pairwise_i16x8_s i32x4_extadd_pairwise_i16x8_u) }

  | (v128_shape as s)".eq"
    { VEC_BINARY (v128op s i8x16_eq i16x8_eq i32x4_eq i64x2_eq f32x4_eq f64x2_eq) }
  | (v128_shape as s)".ne"
    { VEC_BINARY (v128op s i8x16_ne i16x8_ne i32x4_ne i64x2_ne f32x4_ne f64x2_ne) }
  | (v128_int_shape as s)".lt_s"
    { VEC_BINARY (v128intop s i8x16_lt_s i16x8_lt_s i32x4_lt_s i64x2_lt_s) }
  | (v128_int_shape as s)".lt_u"
    { except ["i64x2"] s lexbuf;
      VEC_BINARY (v128intop s i8x16_lt_u i16x8_lt_u i32x4_lt_u unreachable) }
  | (v128_int_shape as s)".le_s"
    { VEC_BINARY (v128intop s i8x16_le_s i16x8_le_s i32x4_le_s i64x2_le_s) }
  | (v128_int_shape as s)".le_u"
    { except ["i64x2"] s lexbuf;
      VEC_BINARY (v128intop s i8x16_le_u i16x8_le_u i32x4_le_u unreachable) }
  | (v128_int_shape as s)".gt_s"
    { VEC_BINARY (v128intop s i8x16_gt_s i16x8_gt_s i32x4_gt_s i64x2_gt_s) }
  | (v128_int_shape as s)".gt_u"
    { except ["i64x2"] s lexbuf;
      VEC_BINARY (v128intop s i8x16_gt_u i16x8_gt_u i32x4_gt_u unreachable) }
  | (v128_int_shape as s)".ge_s"
    { VEC_BINARY (v128intop s i8x16_ge_s i16x8_ge_s i32x4_ge_s i64x2_ge_s) }
  | (v128_int_shape as s)".ge_u"
    { except ["i64x2"] s lexbuf;
      VEC_BINARY (v128intop s i8x16_ge_u i16x8_ge_u i32x4_ge_u unreachable) }
  | (v128_float_shape as s)".lt" { VEC_BINARY (v128floatop s f32x4_lt f64x2_lt) }
  | (v128_float_shape as s)".le" { VEC_BINARY (v128floatop s f32x4_le f64x2_le) }
  | (v128_float_shape as s)".gt" { VEC_BINARY (v128floatop s f32x4_gt f64x2_gt) }
  | (v128_float_shape as s)".ge" { VEC_BINARY (v128floatop s f32x4_ge f64x2_ge) }
  | "i8x16.swizzle" { VEC_BINARY i8x16_swizzle }

  | (v128_shape as s)".add"
    { VEC_BINARY
        (v128op s i8x16_add i16x8_add i32x4_add i64x2_add f32x4_add f64x2_add) }
  | (v128_shape as s)".sub"
    { VEC_BINARY
        (v128op s i8x16_sub i16x8_sub i32x4_sub i64x2_sub f32x4_sub f64x2_sub) }
  | (v128_shape as s)".min_s"
    { only ["i8x16"; "i16x8"; "i32x4"] s lexbuf;
      VEC_BINARY
        (v128op s i8x16_min_s i16x8_min_s i32x4_min_s unreachable
                  unreachable unreachable) }
  | (v128_shape as s)".min_u"
    { only ["i8x16"; "i16x8"; "i32x4"] s lexbuf;
      VEC_BINARY
        (v128op s i8x16_min_u i16x8_min_u i32x4_min_u unreachable
                  unreachable unreachable) }
  | (v128_shape as s)".max_s"
    { only ["i8x16"; "i16x8"; "i32x4"] s lexbuf;
      VEC_BINARY
        (v128op s i8x16_max_s i16x8_max_s i32x4_max_s unreachable
                  unreachable unreachable) }
  | (v128_shape as s)".max_u"
    { only ["i8x16"; "i16x8"; "i32x4"] s lexbuf;
      VEC_BINARY
        (v128op s i8x16_max_u i16x8_max_u i32x4_max_u unreachable
                  unreachable unreachable) }
  | (v128_shape as s)".mul"
    { only ["i16x8"; "i32x4"; "i64x2"; "f32x4"; "f64x2"] s lexbuf;
      VEC_BINARY
        (v128op s unreachable i16x8_mul i32x4_mul i64x2_mul f32x4_mul f64x2_mul) }
  | (v128_float_shape as s)".div"
    { VEC_BINARY (v128floatop s f32x4_div f64x2_div) }
  | (v128_float_shape as s)".min"
    { VEC_BINARY (v128floatop s f32x4_min f64x2_min) }
  | (v128_float_shape as s)".max"
    { VEC_BINARY (v128floatop s f32x4_max f64x2_max) }
  | (v128_float_shape as s)".pmin"
    { VEC_BINARY (v128floatop s f32x4_pmin f64x2_pmin) }
  | (v128_float_shape as s)".pmax"
    { VEC_BINARY (v128floatop s f32x4_pmax f64x2_pmax) }
  | "i8x16.add_sat_"(sign as s)
    { VEC_BINARY (ext s i8x16_add_sat_s i8x16_add_sat_u) }
  | "i8x16.sub_sat_"(sign as s)
    { VEC_BINARY (ext s i8x16_sub_sat_s i8x16_sub_sat_u) }
  | "i16x8.add_sat_"(sign as s)
    { VEC_BINARY (ext s i16x8_add_sat_s i16x8_add_sat_u) }
  | "i16x8.sub_sat_"(sign as s)
    { VEC_BINARY (ext s i16x8_sub_sat_s i16x8_sub_sat_u) }
  | "i32x4.dot_i16x8_s"
    { VEC_BINARY i32x4_dot_i16x8_s }
  | "i8x16.narrow_i16x8_"(sign as s)
    { VEC_BINARY (ext s i8x16_narrow_i16x8_s i8x16_narrow_i16x8_u) }
  | "i16x8.narrow_i32x4_"(sign as s)
    { VEC_BINARY (ext s i16x8_narrow_i32x4_s i16x8_narrow_i32x4_u) }
  | "i16x8.extend_low_i8x16_"(sign as s)
    { VEC_UNARY (ext s i16x8_extend_low_i8x16_s i16x8_extend_low_i8x16_u) }
  | "i16x8.extend_high_i8x16_"(sign as s)
    { VEC_UNARY (ext s i16x8_extend_high_i8x16_s i16x8_extend_high_i8x16_u) }
  | "i32x4.extend_low_i16x8_"(sign as s)
    { VEC_UNARY (ext s i32x4_extend_low_i16x8_s i32x4_extend_low_i16x8_u) }
  | "i32x4.extend_high_i16x8_"(sign as s)
    { VEC_UNARY (ext s i32x4_extend_high_i16x8_s i32x4_extend_high_i16x8_u) }
  | "i64x2.extend_low_i32x4_"(sign as s)
    { VEC_UNARY (ext s i64x2_extend_low_i32x4_s i64x2_extend_low_i32x4_u) }
  | "i64x2.extend_high_i32x4_"(sign as s)
    { VEC_UNARY (ext s i64x2_extend_high_i32x4_s i64x2_extend_high_i32x4_u) }
  | "i16x8.extmul_low_i8x16_"(sign as s)
    { VEC_BINARY (ext s i16x8_extmul_low_i8x16_s i16x8_extmul_low_i8x16_u) }
  | "i16x8.extmul_high_i8x16_"(sign as s)
    { VEC_BINARY (ext s i16x8_extmul_high_i8x16_s i16x8_extmul_high_i8x16_u) }
  | "i32x4.extmul_low_i16x8_"(sign as s)
    { VEC_BINARY (ext s i32x4_extmul_low_i16x8_s i32x4_extmul_low_i16x8_u) }
  | "i32x4.extmul_high_i16x8_"(sign as s)
    { VEC_BINARY (ext s i32x4_extmul_high_i16x8_s i32x4_extmul_high_i16x8_u) }
  | "i64x2.extmul_low_i32x4_"(sign as s)
    { VEC_BINARY (ext s i64x2_extmul_low_i32x4_s i64x2_extmul_low_i32x4_u) }
  | "i64x2.extmul_high_i32x4_"(sign as s)
    { VEC_BINARY (ext s i64x2_extmul_high_i32x4_s i64x2_extmul_high_i32x4_u) }
  | "i16x8.q15mulr_sat_s"
    { VEC_BINARY i16x8_q15mulr_sat_s }

  | (v128_int_shape as s)".all_true"
    { VEC_TEST
        (v128intop s i8x16_all_true i16x8_all_true i32x4_all_true i64x2_all_true) }
  | (v128_int_shape as s)".bitmask"
    { VEC_BITMASK
        (v128intop s i8x16_bitmask i16x8_bitmask i32x4_bitmask i64x2_bitmask) }
  | (v128_int_shape as s)".shl"
    { VEC_SHIFT (v128intop s i8x16_shl i16x8_shl i32x4_shl i64x2_shl) }
  | (v128_int_shape as s)".shr_s"
    { VEC_SHIFT (v128intop s i8x16_shr_s i16x8_shr_s i32x4_shr_s i64x2_shr_s) }
  | (v128_int_shape as s)".shr_u"
    { VEC_SHIFT (v128intop s i8x16_shr_u i16x8_shr_u i32x4_shr_u i64x2_shr_u) }
  | "i8x16.shuffle" { VEC_SHUFFLE }

  | (v128_shape as s)".splat"
    { VEC_SPLAT (v128op s i8x16_splat i16x8_splat i32x4_splat
                           i64x2_splat f32x4_splat f64x2_splat) }
  | (v128_shape as s)".extract_lane"
    { except ["i8x16"; "i16x8"] s lexbuf;
      VEC_EXTRACT (fun i ->
        v128op s
          (fun _ -> unreachable) (fun _ -> unreachable)
          i32x4_extract_lane i64x2_extract_lane
          f32x4_extract_lane f64x2_extract_lane i) }
  | (("i8x16"|"i16x8") as t)".extract_lane_"(sign as s)
    { VEC_EXTRACT (fun i ->
        if t = "i8x16"
        then ext s i8x16_extract_lane_s i8x16_extract_lane_u i
        else ext s i16x8_extract_lane_s i16x8_extract_lane_u i )}
  | (v128_shape as s)".replace_lane"
    { VEC_REPLACE
        (v128op s i8x16_replace_lane i16x8_replace_lane i32x4_replace_lane
                  i64x2_replace_lane f32x4_replace_lane f64x2_replace_lane) }