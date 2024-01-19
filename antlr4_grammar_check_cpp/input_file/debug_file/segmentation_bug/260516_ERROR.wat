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
            (loop $label$1 (result (ref null $0))
                (ref.cast (ref null $0)
                    (table.get $0
                        (block $label$2 (result i32)
                            (select
                                (i32.const 487924244)
                                (i32.const -306468332)
                                (i32.const -69)
                            )
                        )
                    )
                )
            )
        )
    )
)
