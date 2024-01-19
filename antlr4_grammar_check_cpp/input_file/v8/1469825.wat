(module
  (global $g (import "js" "global") (mut i64))
  (func (export "getGlobal") (result i64)
    (global.get $g))
  (func (export "setGlobal") (param $v i64)
    (global.set $g (local.get $v)))
)