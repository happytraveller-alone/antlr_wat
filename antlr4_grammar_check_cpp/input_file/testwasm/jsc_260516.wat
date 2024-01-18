(;//@ runWebAssemblySuite("--useWebAssemblyTypedFunctionReferences=true", "--useWebAssemblyGC=true");)

(module
 (type $0 (sub (func (param i32 i32 i32) (result i32))))
 (type $1 (func))
 (memory $0 16 32)
 (table $0 1 1 funcref)
 (elem $0 (i32.const 0) $0)
 (tag $tag$0)
 (export "" (func $0))
 (func $0 (param $0 i32) (param $1 i32) (param $2 i32) (result i32)
  (drop
   (call $0
    (i32.const 697894484)
    (i32.const -157833023)
    (i32.const -434794502)
   )
  )
  (drop
   (call $0
    (i32.const 769991768)
    (i32.const 631785841)
    (i32.const 1294656724)
   )
  )
  (drop
   (block $label$3 (type 8)
    (ref.func $0)
   )
  )
  (block $label$4 (type 9)
   (i32.const 1855060810)
  )
 )
)
