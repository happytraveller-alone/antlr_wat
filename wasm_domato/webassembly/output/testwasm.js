const builder = new WasmModuleBuilder();
builder.addType(makeSig([kWasmF32,wasmRefNullType(1), ,wasmRefNullType(kWasmAnyFunc),wasmRefType(4),],[wasmRefType(4),kWasmI32,]));

builder.addFunction('main', makeSig([], [])).addBodyWithEnd([kExprEnd,]).exportFunc();
const instance = builder.instantiate()
instance.export.main()
