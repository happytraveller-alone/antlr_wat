(module
    (type $f (func (result i32)))
    (func (export "test") (type $f)
      ref.null $f
      ref.test (ref null $f)
    )
)
