(module
    (type (;0;) (func (param f64 f64) (result f64)))
    (func (;0;) ;; entry 
        (local f64 f64 i32) 
        f64.const 5.43231e-31 
        f64.const 1.0 
        f64.mul 
        local.set 1 
        loop ;; label = @1 
            local.get 1 
            local.get 0 
            f64.add 
            local.set 0 
            local.get 2 
            i32.const 1 
            i32.add 
            local.tee 2 ;; i ++ 
            i32.const 31250000 
            i32.ne ;; i <= 31250000 
            br_if 0 (; @1 ;) 
        end 
    )
    (memory (;0;) 1 1)
)