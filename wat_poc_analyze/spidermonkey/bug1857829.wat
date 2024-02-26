(module
    (global $i (ref i31) (ref.i31 (i32.const -1)))
    (func (export "f") (result i32)
       (ref.eq (ref.i31 (i32.const -1)) (global.get $i))
    )
 )