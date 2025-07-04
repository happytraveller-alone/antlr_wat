(module
    (type $a (array i32))
    (type $s (struct (field (ref $a)) (field (ref $a)) (field (ref $a))))

    (func $new (result (ref $s))
        (struct.new $s (array.new_default $a (i32.const 5))
                        (array.new_default $a (i32.const 17))
                        (array.new_default $a (i32.const 0))
        )
    )

    (func (export "len0") (result i32)
        (struct.get $s 0 (call $new))
        (array.len)
    )
    (func (export "len1") (result i32)
        (struct.get $s 1 (call $new))
        (array.len)
    )
    (func (export "len2") (result i32)
        (struct.get $s 2 (call $new))
        (array.len)
    )
)