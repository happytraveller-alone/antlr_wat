const builder = new WasmModuleBuilder();
builder.startRecGroup();
builder.addType(makeSig([wasmRefNullType(0),kWasmI8,kWasmVoid,kWasmI32,wasmRefType(1),],[wasmRefNullType(kWasmAnyFunc),kWasmVoid,wasmRefType(3),wasmRefNullType(1),wasmRefNullType(1),]));
builder.endRecGroup();
builder.addFunction(undefined, 3).addBodyWithEnd([kExprEnd,]);
builder.addExport('main', 0)
const instance = builder.instantiate()
instance.export.main()
