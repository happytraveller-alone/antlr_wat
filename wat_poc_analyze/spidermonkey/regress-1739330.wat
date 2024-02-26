(type $e (struct))
      (func (export "newStruct")
        (result eqref)
        struct.new $e
      )