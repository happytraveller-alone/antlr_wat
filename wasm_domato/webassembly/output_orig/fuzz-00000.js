const builder = new WasmModuleBuilder();
builder.addType(makeSig([],[kWasmF32,kWasmVoid,]));

/* newvar{memory_simple_001:element} */ var memory_simple_001 = builder.addMemory(16, 32, false);
builder.addFunction('main', makeSig([kWasmI64, kWasmI32, kWasmI32], [])).addBodyWithEnd([kExprEnd,]).exportFunc();

const instance = builder.instantiate();
instance.exports.main();
