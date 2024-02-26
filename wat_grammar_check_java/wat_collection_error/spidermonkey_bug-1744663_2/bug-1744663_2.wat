(module
       (tag $exn (export "exn"))
       (func $throwExn (export "throwExn")
         (try
           (do (throw $exn))
           (catch_all
             (try
               (do (throw $exn))
               (catch_all (rethrow 1)))))))