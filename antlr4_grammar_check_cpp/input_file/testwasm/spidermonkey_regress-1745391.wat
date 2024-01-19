(module (type $a (array (mut i32)))
    (func (export "createDefault") (param i32) (result eqref)
      local.get 0
      array.new_default $a
    )
  )