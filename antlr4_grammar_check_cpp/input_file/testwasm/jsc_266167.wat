;;//@ runWebAssemblySuite("--useWebAssemblyTypedFunctionReferences=true", "--useWebAssemblyGC=true")

  (module
    (type (struct (field i32)))
    (func (export "f")
      (block
        (struct.new 0 (i32.const 42))
        (br_on_null 0)
        (struct.get 0 0)
        drop
        ))
  )