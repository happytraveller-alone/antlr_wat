;;//@ runWebAssemblySuite("--useWebAssemblyTypedFunctionReferences=true", "--useWebAssemblyGC=true")

    (module
      (type (struct (field i32)))
      (func (export "f") (result i32)
        (block (result i32)
          (i32.const -1)
          (ref.i31 (i32.const 42))
          (br_on_null 0)
          (br 0 (i31.get_u))))
    )