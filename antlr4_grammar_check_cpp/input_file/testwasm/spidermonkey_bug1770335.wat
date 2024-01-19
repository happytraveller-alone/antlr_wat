(module
    (memory (export "memory") 1 1)
    (func $test (param v128) (result v128)
        local.get 0
        v128.const i32x4 0x00000000 0x00000000 0x00000000 0x00000000
        i8x16.shuffle 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23
        v128.const i32x4 0x00000000 0x00000000 0x00000000 0x00000000
        local.get 0
        i8x16.shuffle 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23
        v128.xor
    )
    (func (export "run")
        i32.const 16
        i32.const 0
        v128.load
        call $test
        v128.store
    )
)