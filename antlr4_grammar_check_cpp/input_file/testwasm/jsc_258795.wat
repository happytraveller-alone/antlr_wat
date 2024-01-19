;;//@ skip if !$isSIMDPlatform
;;//@ runWebAssemblySuite("--useWebAssemblyTypedFunctionReferences=true", "--useWebAssemblyGC=true")

(module
 (type $0 (func))
 (type $1 (sub (func (param i32 i32 i32) (result i32))))
 (memory $0 16 32)
 (table $0 1 2 funcref)
 (table $1 0 1 eqref)
 (elem $0 (table $0) (i32.const 0) func $0)
 (tag $tag$0)
 (export "main" (func $0))
 (func $0 (param $0 i32) (param $1 i32) (param $2 i32) (result i32)
  (i32.const -114)
 )
)
