(module
    (type $s (struct (field i32) (field i32) (field i32)))

    (func $new (result (ref $s))
        (struct.new $s (i32.const 5) (i32.const 17) (i32.const 0))
    )

    (func (export "get0") (result i32)
        (struct.get $s 0 (call $new))
    )
    (func (export "get1") (result i32)
        (struct.get $s 1 (call $new))
    )
    (func (export "get2") (result i32)
        (struct.get $s 2 (call $new))
    )
)