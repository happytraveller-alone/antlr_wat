(module
    (type $bvec (array i8))
    (type $inner (struct (field i32) (field (ref $bvec))))
    (type $outer (struct (field (ref $inner)) (field (ref $inner))))

    (func $new (export "new") (result (ref $outer))
    (local i32)
    (local.set 0 (i32.const 42))
    (struct.new $outer (struct.new $inner (i32.const 3) (array.new_default $bvec (i32.const 1)))
                       (struct.new $inner (local.get 0) (array.new_default $bvec (i32.const 6))))
    )
    (func (export "get_field0_0") (result i32)
        (call $new)
        (struct.get $inner 0 (struct.get $outer 0))
    )

    (func (export "get_field0_len1") (result i32)
        (call $new)
        (array.len (struct.get $inner 1 (struct.get $outer 0)))
    )

    (func (export "get_field1_0") (result i32)
        (call $new)
        (struct.get $inner 0 (struct.get $outer 1))
    )

    (func (export "get_field1_len1") (result i32)
        (call $new)
        (array.len (struct.get $inner 1 (struct.get $outer 1)))
    )
)