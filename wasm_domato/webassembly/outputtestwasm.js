const builder = new WasmModuleBuilder();

builder.addFunction(undefined, 5).addBodyWithEnd([kExprEnd,]);
builder.addExport('main', 0)
const instance = builder.instantiate()
instance.export.main()
