(type $g 
  (func (param i64 i64 funcref) (result i64))
)          
(func (export "vis") (param i64 i64 funcref) (result i64) 
  local.get 0 
  local.get 1
  local.get 2
  local.get 2
  ref.cast (ref $g)
  return_call_ref $g
)