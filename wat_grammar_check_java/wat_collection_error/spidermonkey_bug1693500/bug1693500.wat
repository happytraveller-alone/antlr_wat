(module
        (memory (export "memory") 1 1)
        (func $t (export "t") (param v128) (result v128)
            local.get 0
            v128.const i64x2 ${n1} ${n2}
            i64x2.mul
        )
        (func $t0 (param v128 v128) (result v128)
            local.get 0
            local.get 1
            i64x2.mul
        )
        (func (export "run") (result i32)
            i32.const 16
            i32.const 0
            v128.load
            call $t
            v128.store

            v128.const i64x2 ${n1} ${n2}
            i32.const 0
            v128.load
            call $t0

            i32.const 16
            v128.load
            i64x2.eq
            i64x2.all_true
        )
    )