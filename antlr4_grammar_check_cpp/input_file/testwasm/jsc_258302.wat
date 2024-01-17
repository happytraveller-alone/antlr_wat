(module
  (func $bad (export "bad") (result i64)
        (local $l41 v128)
        (local.set $l41
        (v128.const i32x4 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF))
          (if (result i64)
            (i32.eqz
              (v128.any_true
                (local.get $l41)))
            (then (i64.const 1))
            (else
              (i64x2.extract_lane 1
                  (v128.const i32x4 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF))
            )
          )
      )
)


;;// https://github.com/WebKit/WebKit/commit/f9a3a2147af0a89a67c74b9da7a291387c6cb39c#diff-a0848dcce0a6a2eca22d190fb218430cf7ec255ea98a8198d409da4bbf7474ec
;;// https://bugs.webkit.org/show_bug.cgi?id=258302