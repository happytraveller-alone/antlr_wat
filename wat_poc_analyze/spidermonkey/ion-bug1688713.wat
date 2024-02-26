(module
    (memory 1)
    (func $f (export "f") (param i32) (param i32) (param i32) (param i32) (param i32) (result v128)
      (i32x4.add (v128.load8x8_s (local.get 4)) (v128.load8x8_s (local.get 2)) )
    )
  )
)