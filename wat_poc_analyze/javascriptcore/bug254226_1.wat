(module
    (type $inner (struct (field i32) (field i32)))
    (type $outer (struct (field (ref $inner)) (field (ref $inner))))

    (func $new (export "new") (result (ref $outer))
        (struct.new $outer (struct.new $inner (i32.const 41) (i32.const 42))
                        (struct.new $inner (i32.const 43) (i32.const 45))
        )
    )

    (func (export "get_field0_0") (result i32)
        (call $new)
        (struct.get $inner 0 (struct.get $outer 0))
    )

    (func (export "get_field0_1") (result i32)
        (call $new)
        (struct.get $inner 1 (struct.get $outer 0))
    )

    (func (export "get_field1_0") (result i32)
        (call $new)
        (struct.get $inner 0 (struct.get $outer 1))
    )

    (func (export "get_field1_1") (result i32)
        (call $new)
        (struct.get $inner 1 (struct.get $outer 1))
    )
)