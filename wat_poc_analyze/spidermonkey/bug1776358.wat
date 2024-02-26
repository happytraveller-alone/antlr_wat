(module
    (func
        (param f64) (param f64) (param f64) (param f64) (param f64)
        (param f64) (param f64) (param f64) (param f64)
    )
    (func
        (param i32)
        (result i32)
        ;; Call in a dead branch.
        (if (i32.const 0) (then
          (call 0
            (f64.const 0) (f64.const 0) (f64.const 0) (f64.const 0) (f64.const 0)
            (f64.const 0) (f64.const 0) (f64.const 0) (f64.const 0)
          )
        ))
        ;; Division to trigger a trap.
        (i32.div_s (local.get 0) (local.get 0))
    )
    (export "" (func 1))
)