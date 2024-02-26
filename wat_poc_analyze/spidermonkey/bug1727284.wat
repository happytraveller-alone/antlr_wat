(module
      (global $g (mut externref) (ref.null extern))
      (func (export "set") (param externref) local.get 0 global.set $g)
    )