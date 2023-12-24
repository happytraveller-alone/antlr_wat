(module
  (type (;0;) (func (result i32)))
  (type (;1;) (func (param i32 i32 i32 i32 i32 i32) (result i32)))
  (type (;2;) (func (param i32) (result i32)))
  (type (;3;) (func (param i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32) (result i32)))
  (import "js" "mem" (memory (;0;) 1))
  (func (;0;) (type 0) (result i32)
    i32.const 1)
  (func (;1;) (type 1) (param i32 i32 i32 i32 i32 i32) (result i32)
    local.get 0
    i32.const 1
    i32.add)
  (func (;2;) (type 0) (result i32)
    call 0)
  (func (;3;) (type 2) (param i32) (result i32)
    i32.const 128
    i32.load
    i32.const 0
    i32.ne
    if  ;; label = @1
      i32.const 4
      return
    end
    i32.const 128
    i32.const 4096
    i32.store
    i32.const 1
    i32.const 1
    i32.const 1
    i32.const 1
    local.get 0
    i32.const 1
    call 1)
  (func (;4;) (type 3) (param i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32) (result i32)
    i32.const 0
    local.get 0
    i32.store
    i32.const 4
    local.get 1
    i32.store
    i32.const 8
    local.get 2
    i32.store
    i32.const 12
    local.get 3
    i32.store
    i32.const 16
    local.get 4
    i32.store
    i32.const 20
    local.get 5
    i32.store
    i32.const 24
    local.get 6
    i32.store
    i32.const 28
    local.get 7
    i32.store
    i32.const 32
    local.get 8
    i32.store
    i32.const 36
    local.get 9
    i32.store
    i32.const 40
    local.get 10
    i32.store
    i32.const 44
    local.get 11
    i32.store
    i32.const 48
    local.get 12
    i32.store
    i32.const 52
    local.get 13
    i32.store
    i32.const 56
    local.get 14
    i32.store
    i32.const 60
    local.get 15
    i32.store
    i32.const 64
    local.get 16
    i32.store
    i32.const 68
    local.get 17
    i32.store
    i32.const 72
    local.get 18
    i32.store
    i32.const 76
    local.get 19
    i32.store
    i32.const 80
    local.get 20
    i32.store
    i32.const 84
    local.get 21
    i32.store
    i32.const 88
    local.get 22
    i32.store
    i32.const 92
    local.get 23
    i32.store
    i32.const 0)
  (export "l" (func 2))
  (export "g" (func 3)))
