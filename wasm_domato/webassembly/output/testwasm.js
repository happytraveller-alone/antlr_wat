const builder = new WasmModuleBuilder();
builder.addFunction('main', makeSig([], [])).addBodyWithEnd([kExprEnd,]).exportFunc();
const instance = builder.instantiate();
instance.exports.main();
