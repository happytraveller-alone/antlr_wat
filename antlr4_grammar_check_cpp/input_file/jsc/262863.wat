;;//@ runWebAssemblySuite("--useWebAssemblyTypedFunctionReferences=true", "--useWebAssemblyGC=true")


 (module
  (type $0 (sub (array (mut i32))))
  (type $1 (func (param (ref null $0))))
  (type $2 (sub (func (param i32 i32 i32) (result i32))))
  (memory $0 16 32)
  (table $0 1 1 funcref)
  (elem $0 (i32.const 0) $0)
  (tag $tag$0 (param (ref null $0)))
  (export "main" (func $0))
  (func $0 (param $0 i32) (param $1 i32) (param $2 i32) (result i32)
   (throw $tag$0
    (block $label$1 (result (ref null $0))
     (block $label$2 (result (ref null $0))
      (ref.null none)
     )
    )
   )
  )
 )
   