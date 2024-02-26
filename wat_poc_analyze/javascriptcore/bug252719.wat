
(module
    (type $s (struct (field i32) (field i32)))

    (func $new (export "new") (result (ref $s))
        (struct.new $s (i32.const 1) (i32.const 5)))

    (func (export "len0") (result i32)
        (struct.get $s 0 (call $new))
    )
    (func (export "len1") (result i32)
        (struct.get $s 1 (call $new))
    )
)