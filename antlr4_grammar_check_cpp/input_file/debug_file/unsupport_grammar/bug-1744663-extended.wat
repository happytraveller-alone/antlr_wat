(module
       (type $exnType (func (param i32 i64 f32 f64 externref  v128)))
       (type $indirectFunctype (func (param i32 i64 f32 f64 externref  v128)
                                     (result i32 i64 f32 f64 externref  v128)))
       (tag $exn (export "exn") (type $exnType))
       (tag $emptyExn (export "emptyExn"))
       (func $throwExn (export "throwExn") (param i32 i64 f32 f64 externref  v128)
                                           (result i32 i64 f32 f64 externref  v128)
                                           (local $ifPredicate i32)
         (local.get 0) ;; i32
         (local.get 1) ;; i64
         (local.get 2) ;; f32
         (local.get 3) ;; f64
         (local.get 4) ;; ref
         (local.get 5) ;; v128 or i32
         (try (param i32 i64 f32 f64 externref  v128)
           (do
             (if (param i32 i64 f32 f64 externref  v128)
               (local.get $ifPredicate)
               (then (throw $exn))
               (else (throw $exn))))
           (catch $exn
              (try (param i32 i64 f32 f64 externref  v128)
                (do (throw $exn))
                (catch_all (rethrow 1))))
           (catch_all))
           unreachable)
         (func $throwEmptyExn (export "throwEmptyExn")
                              (param i32 i64 f32 f64 externref  v128)
                              (result i32 i64 f32 f64 externref  v128)
           (throw $emptyExn)
           unreachable)
         (func $returnArgs (export "returnArgs")
                           (param i32 i64 f32 f64 externref  v128)
                           (result i32 i64 f32 f64 externref  v128)
           (local.get 0)  ;; i32
           (local.get 1)  ;; i64
           (local.get 2)  ;; f32
           (local.get 3)  ;; f64
           (local.get 4)  ;; ref
           (local.get 5))
         (table (export "tab") funcref (elem $throwExn       ;; 0
                                             $throwEmptyExn  ;; 1
                                             $returnArgs))   ;; 2
         )