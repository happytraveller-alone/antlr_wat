(module
    (type $t1 (func))
    (func $f0 (param funcref i32 i32 i32 i32 i32 i32 i32 i32 i32)
        local.get 0
        ref.cast (ref $t1)
        return_call_ref $t1
    )
    (func $f1 (param i32))
    (elem declare func $f)
    (func $f (param funcref)
        (local i32 i32 i32 i32)
        local.get 0
        i32.const 1
        i32.const 1
        i32.const 1
        i32.const 1
        i32.const 1
        i32.const 1
        i32.const 1
        i32.const 1
        i32.const 1
        return_call $f0
    )
    (func (export "f") (result funcref)
        ref.func $f
    )
)