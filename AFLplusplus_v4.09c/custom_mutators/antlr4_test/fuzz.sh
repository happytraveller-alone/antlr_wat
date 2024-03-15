AFL_DISABLE_TRIM=1 AFL_NO_STARTUP_CALIBRATION=1 AFL_TESTCACHE_SIZE=100 AFL_CUSTOM_MUTATOR_LIBRARY="/home/xyf/antlr_wat/AFLplusplus_v4.09c/custom_mutators/antlr4_test/antlr_parser/libGrammar_check_shared.so" AFL_CUSTOM_MUTATOR_ONLY=1 /home/xyf/antlr_wat/AFLplusplus_v4.09c/afl-fuzz -a "text" -P 100000  -M "main" -m 2048 -t 1000 -i /home/xyf/antlr_wat/AFLplusplus_v4.09c/custom_mutators/antlr4_test/input -o /home/xyf/antlr_wat/AFLplusplus_v4.09c/custom_mutators/antlr4_test/output /home/xyf/antlr_wat/AFLplusplus_v4.09c/custom_mutators/antlr4_test/vlun/vlun_clang
# AFL_DISABLE_TRIM=1 禁止裁剪测例
# AFL_NO_STARTUP_CALIBRATION=1 禁止启动时校准
# AFL_TESTCACHE_SIZE=50 测试缓存大小
# AFL_CUSTOM_MUTATOR_LIBRARY= 自定义变异器库
# AFL_CUSTOM_MUTATOR_ONLY=1 只使用自定义变异器
# -a "text" 