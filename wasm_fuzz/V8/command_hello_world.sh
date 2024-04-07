clang++ -I. -Iinclude samples/hello-world.cc -o hello_world -fno-rtti \
        -lv8_monolith -lv8_libbase -lv8_libplatform -ldl -L/home/xyf/antlr_wat/wasm_fuzz/static_library \
        -pthread -std=c++17 -DV8_COMPRESS_POINTERS -DV8_ENABLE_SANDBOX