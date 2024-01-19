(type $a (array funcref))
    (elem $e func $f1 $f2 $f3 $f4)
    (func $f1 )
    (func $f2 )
    (func $f3 )
    (func $f4 )
    (func (export "newElem") (result eqref)
             i32.const 0
             i32.const 4
            array.new_elem $a $e
    )