(module
    (type $Point (struct (field $x (mut i64))))
    (func $doTest (param $p (ref $Point)) (result i64)
        (struct.set $Point $x
            (local.get $p)
            (i64.const 37)
        )
        (struct.get $Point $x
            (local.get $p)
        )
    )
    (func (export "main") (result i64)
        (call $doTest
            (struct.new $Point (i64.const 0))
        )
    )
)