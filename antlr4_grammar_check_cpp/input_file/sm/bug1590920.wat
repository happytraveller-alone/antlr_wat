(module
        (func (export "g")
          (drop
            (block (result i32)
              (i32.clz (i32.const 1))
              (if
                (i32.const 1)
                (then (return)))))))