(module
       (tag $exn (export "exn"))
       (func $throwExn (export "throwExn")
         ;; Note that this does not fail if this function body is a plain (throw $exn).
         (try
           (do (throw $exn)))))