(module
    (memory (export "mem") 1)
    (func (export "test")
      (v128.store (i32.const 0)
        (i8x16.shuffle 0 1 2 3 4 5 6 7 8 0 1 2 3 4 5 6
                       (v128.load (i32.const 16))
                       (v128.const i32x4 0 0 0 0)))))