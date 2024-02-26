(module
    (type (struct (field i32)))
    (type (struct (field (mut (ref null 0)))))
    (func (export "f") (result (ref any))
      (struct.new 1 (ref.null 0)))
  )