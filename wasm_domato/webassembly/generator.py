from __future__ import print_function
import os
import sys
from grammar import Grammar
import subprocess
"""
Parses grammar rules from string.

Args:
  wasmgrammar: Grammar for generating wasm code.

Returns:
  A string containing sample data.
"""
def generate_sample_body(wasm_garmmar_set,num_lines):
    result = ''
    result += 'const builder = new WasmModuleBuilder();\n'
    for  wasm_grammar in wasm_garmmar_set:
        result += wasm_grammar._generate_code(num_lines)
        result += '\n'
    result += '\nconst instance = builder.instantiate();\n'
    result += 'instance.exports.main();\n'

    return result


"""
Parses a grammar file and returns a Grammar object.
Args:
    grammar_dir (str): The directory where the grammar file is located.
    file_name (str): The name of the grammar file.
Returns:
    Grammar: The parsed Grammar object.
Raises:
    None
"""
def parse_grammar(grammar_dir, \
                  file_name):

    grammar = Grammar()
    err = grammar.parse_from_file(os.path.join(grammar_dir, file_name))
    if err > 0:
        print(f'There were errors parsing {file_name} grammar')
        return None
    return grammar


"""
Generates a set of samples and writes them to the output files.

Args:
  grammar_dir: directory to load grammar files from.
  outfiles: A list of output filenames.

Returns:
  None
"""
def generate_samples(grammar_dir, \
                    input_dir, \
                    output_merge_dir, \
                    output_orig_dir, \
                    out_files_snippet, \
                    grammar_files):
    
    wasm_garmmar_set = []
    for wasm_grammar in grammar_files:
        wasm_garmmar_part = parse_grammar(grammar_dir, wasm_grammar + '.txt')
        if wasm_garmmar_part is not None:
            wasm_garmmar_set.append(wasm_garmmar_part)
    for outfile in out_files_snippet:
        output_merge_file_path = os.path.join(output_merge_dir, outfile)
        output_orig_file_path = os.path.join(output_orig_dir, outfile)
        result = generate_sample_body(wasm_garmmar_set,1)
        if result is not None:
            print('Writing a sample to ' + output_merge_file_path)
            try:
                f1 = open(output_merge_file_path, 'w')
                f2 = open(os.path.join(input_dir, 'wasm-module-builder.js'),
                          'r')
                f1.write(f2.read())
                f2.close()
                f1.write(result)
                f1.close()
            except IOError:
                print('Error writing to output')
            print('Writing a sample to ' + output_orig_file_path)
            try:
                f3 = open(output_orig_file_path, 'w')
                f3.write(result)
                f3.close()
            except IOError:
                print('Error writing to output')
    return


def get_test_results(dir_path_map, outfiles, develop_shell, base_dir,
                     develop_shell_args):
    outfiles_crash = [
        os.path.join(base_dir, f'fuzz-{i:05d}-record.txt')
        for i in range(len(outfiles))
    ]
    for outfile in outfiles:
        wasm_file = os.path.join(dir_path_map['output_merge_dir'], outfile)
        command = develop_shell + " " + develop_shell_args + "\t" + wasm_file
        result = subprocess.run(command,
                                shell=True,
                                stdout=subprocess.PIPE,
                                stderr=subprocess.PIPE)
        return_code = result.returncode
        with open(outfiles_crash[outfiles.index(outfile)], 'w') as f:
            f.write(f"Command: {command}\n\n")
            f.write(f"Return code: {return_code}\n\n")
            f.write(f"Output: {result.stdout.decode()}\n\n")
            f.write(f"Error: {result.stderr.decode()}\n")
            f.close()

def print_usage():
    print("Usage:")
    print("\tpython generator.py --output_dir <dir> --no_of_files <count>")
    print(
        "\tpython generator.py --output_dir <dir> --no_of_files <count> --enable_test <On/False>"
    )
    print("build v8 command:")
    print("\tgn gen out/example --args='is_clang=true is_debug=false is_component_build=false v8_enable_webassembly=true v8_enable_i18n_support=false symbol_level=0")  
    print("\tstrip_debug_info=true   target_cpu=\"x64\" v8_static_library=true is_component_build=false v8_monolithic=false v8_use_external_startup_data=false") 
    print("\tuse_custom_libcxx=false use_custom_libcxx_for_host=false")
    print("\n\tninja -j 20 -C out/example d8")
    print("build jsc command:")
    print("\tTools/Scripts/build-jsc --jsc-only  --build-dir=example --makeargs=-j18")
    print("\t--cmakeargs='-DCMAKE_CXX_COMPILER=/usr/bin/clang++ -DCMAKE_C_COMPILER=/usr/bin/clang -DENABLE_STATIC_JSC=ON'")
    print("build sm command:")
    print("\t../configure CC=/usr/bin/clang CXX=/usr/bin/clang++ --enable-fuzzing --disable-jemalloc --enable-debug --enable-optimize --disable-shared-js")
    sys.exit(1)

def generate_samples_name(dir_path_map, out_dir, out_orig_dir, file_count, grammar_files):
    out_files_snippet = [(f'fuzz-{i:05d}.js') for i in range(file_count)]
    generate_samples(dir_path_map['grammar_dir'], dir_path_map['input_dir'],
                     out_dir, out_orig_dir, out_files_snippet, grammar_files)

def check_arguments(dir_path_map, arg_map):
    help_arg = ['--help', '-h', '--help_build_v8', '--help_build_jsc', '--help_build_sm']
    for arg in help_arg:
        if arg in sys.argv:
            print_usage()
            sys.exit(1)
    if '--enable_test' in sys.argv:
        # validate_enable_test_option(arg_map['--enable_test'])
        arg_map['--enable_test'] = True
        print('enable_test is set to ' + str(arg_map['--enable_test']))
        arg_map['--enable_test_v8'] = True
        arg_map['--enable_test_jsc'] = True
        arg_map['--enable_test_sm'] = True
    else:
        print('enable_test is not set, default to False')
        if '--enable_test_v8' in sys.argv:
            arg_map['--enable_test_v8'] = True
            print('enable_test_v8 is set to ' + str(arg_map['--enable_test_v8']))
        else:
            print('enable_test_v8 is not set, default to False')
        if '--enable_test_jsc' in sys.argv:
            arg_map['--enable_test_jsc'] = True
            print('enable_test_jsc is set to ' + str(arg_map['--enable_test_jsc']))
        else:
            print('enable_test_jsc is not set, default to False')
        if '--enable_test_sm' in sys.argv:
            arg_map['--enable_test_sm'] = True
            print('enable_test_sm is set to ' + str(arg_map['--enable_test_sm']))
        else:
            print('enable_test_sm is not set, default to False')
    if '--no_of_files' in sys.argv:
        arg_map['--no_of_files'] = int( sys.argv[sys.argv.index('--no_of_files') + 1])
        print('no_of_files is set to ' + str(arg_map['--no_of_files']))
    else:
        print('no_of_files is not set, default to 1')
    if '--output_dir' in sys.argv:
        arg_map['--output_dir'] = sys.argv[sys.argv.index('--output_dir') + 1]
        if not os.path.isabs(arg_map['--output_dir']):
            arg_map['--output_dir'] = os.path.join(dir_path_map['fuzz_dir'],
                                                   arg_map['--output_dir'])
        if not os.path.exists(arg_map['--output_dir']):
            os.makedirs(arg_map['--output_dir'])
        print('output_dir is set to ' + arg_map['--output_dir'])
    else:
        print('output_dir is not set, default to output_merge')

def clean_dir(dir_path_map):
    if os.path.exists(dir_path_map['output_merge_dir']):
        for file in os.listdir(dir_path_map['output_merge_dir']):
            os.remove(os.path.join(dir_path_map['output_merge_dir'], file))
    else:
        os.makedirs(dir_path_map['output_merge_dir'])
    if os.path.exists(dir_path_map['output_orig_dir']):
        for file in os.listdir(dir_path_map['output_orig_dir']):
            os.remove(os.path.join(dir_path_map['output_orig_dir'], file))
    else:
        os.makedirs(dir_path_map['output_orig_dir'])
    if os.path.exists(dir_path_map['useful_crash_v8']):
        for file in os.listdir(dir_path_map['useful_crash_v8']):
            os.remove(os.path.join(dir_path_map['useful_crash_v8'], file))
    else:
        os.makedirs(dir_path_map['useful_crash_v8'])
    if os.path.exists(dir_path_map['useful_crash_jsc']):
        for file in os.listdir(dir_path_map['useful_crash_jsc']):
            os.remove(os.path.join(dir_path_map['useful_crash_jsc'], file))
    else:
        os.makedirs(dir_path_map['useful_crash_jsc'])
    if os.path.exists(dir_path_map['useful_crash_sm']):
        for file in os.listdir(dir_path_map['useful_crash_sm']):
            os.remove(os.path.join(dir_path_map['useful_crash_sm'], file))
    else:
        os.makedirs(dir_path_map['useful_crash_sm'])

def test_samples(dir_path_map, args_map, develop_shell_map,
                 develop_shell_args_map):
    if args_map['--enable_test'] == True:
        get_test_results(dir_path_map,
                         os.listdir(dir_path_map['output_merge_dir']),
                         develop_shell_map['develop_shell_v8'],
                         dir_path_map['useful_crash_v8'],
                         develop_shell_args_map['develop_shell_v8'])
        get_test_results(dir_path_map,
                         os.listdir(dir_path_map['output_merge_dir']),
                         develop_shell_map['develop_shell_jsc'],
                         dir_path_map['useful_crash_jsc'],
                         develop_shell_args_map['develop_shell_jsc'])
        get_test_results(dir_path_map,
                         os.listdir(dir_path_map['output_merge_dir']),
                         develop_shell_map['develop_shell_sm'],
                         dir_path_map['useful_crash_sm'],
                         develop_shell_args_map['develop_shell_sm'])
    if args_map['--enable_test'] == False:
        if args_map['--enable_test_v8'] == True:
            get_test_results(dir_path_map,
                             os.listdir(dir_path_map['output_merge_dir']),
                             develop_shell_map['develop_shell_v8'],
                             dir_path_map['useful_crash_v8'],
                             develop_shell_args_map['develop_shell_v8'])
        if args_map['--enable_test_jsc'] == True:
            get_test_results(dir_path_map,
                             os.listdir(dir_path_map['output_merge_dir']),
                             develop_shell_map['develop_shell_jsc'],
                             dir_path_map['useful_crash_jsc'],
                             develop_shell_args_map['develop_shell_jsc'])
        if args_map['--enable_test_sm'] == True:
            get_test_results(dir_path_map,
                             os.listdir(dir_path_map['output_merge_dir']),
                             develop_shell_map['develop_shell_sm'],
                             dir_path_map['useful_crash_sm'],
                             develop_shell_args_map['develop_shell_sm'])

def main():
    fuzz_dir = os.path.dirname(__file__)
    # 路径整理
    dir_path_map = {
        'fuzz_dir': fuzz_dir,
        'grammar_dir': os.path.join(fuzz_dir, 'grammar'),
        'useful_crash_v8': os.path.join(fuzz_dir, 'useful_crash_v8'),
        'useful_crash_jsc': os.path.join(fuzz_dir, 'useful_crash_jsc'),
        'useful_crash_sm': os.path.join(fuzz_dir, 'useful_crash_sm'),
        'input_dir': os.path.join(fuzz_dir, 'input'),
        'output_merge_dir': os.path.join(fuzz_dir, 'output_merge'),
        'output_orig_dir': os.path.join(fuzz_dir, 'output_orig'),
    }

    # 参数map
    arg_map = {
        '--output_dir': dir_path_map['output_merge_dir'],
        '--output_orig_dir': dir_path_map['output_orig_dir'],
        '--no_of_files': 1,
        '--enable_test': False,
        '--enable_test_v8': False,
        '--enable_test_jsc': False,
        '--enable_test_sm': False,
        '--help': False,
        '--help_build_v8': False,
        '--help_build_jsc': False,
        '--help_build_sm': False,
    }
    # 语法文件填充,在grammar路径下，os.list遍历
    grammar_files = [
        'wasm_type',
        'wasm_memory',
        'wasm_function_body',
    ]
    # 参数填充
    check_arguments(dir_path_map, arg_map)
    # 清空文件夹
    clean_dir(dir_path_map)
    # 生成样本
    generate_samples_name(dir_path_map, arg_map['--output_dir'], arg_map['--output_orig_dir'],
                          arg_map['--no_of_files'], grammar_files)
    # 测试样本
    develop_shell_map = {
        'develop_shell_v8':
        "/home/xyf/v8/v8/out/v8_12.5.169/d8",
        'develop_shell_jsc':
        "/home/xyf/WebKit/20240416_fuzz_commit_939e7000670a9204a8b03f31f9ebd252d7486a1f/JSCOnly/Release/bin/jsc",
        'develop_shell_sm':
        "/home/xyf/spidermonkey/js/src/20240416_fuzz_commit_23ad6bdb310c9a46e6f37885b0d88ec5da3c00f7/dist/bin/js",
    }
    # 测试样本参数
    develop_shell_args_map = {
        'develop_shell_v8':
        "--turboshaft-wasm \
            --allow-natives-syntax \
            --turboshaft-wasm-load-elimination \
            --turboshaft-wasm-instruction-selection-experimental \
            --turboshaft-wasm-instruction-selection-staged \
            --wasm-deopt \
            --experimental-wasm-compilation-hints \
            --experimental-wasm-instruction-tracing \
            --experimental-wasm-assume-ref-cast-succeeds \
            --experimental-wasm-ref-cast-nop \
            --experimental-wasm-branch-hinting \
            --experimental-wasm-stack-switching \
            --experimental-wasm-jspi \
            --experimental-wasm-shared \
            --experimental-wasm-type-reflection \
            --experimental-wasm-memory64 \
            --experimental-wasm-stringref \
            --experimental-wasm-imported-strings \
            --experimental-wasm-inlining \
            --experimental-wasm-exnref \
            --experimental-wasm-multi-memory \
            --experimental-wasm-legacy-eh \
            --wasm-staging \
            --experimental-wasm-revectorize",
        'develop_shell_jsc':
        "--useWebAssemblyThreading=true \
            --useWebAssemblyTypedFunctionReferences=true \
            --useWebAssemblyGC=true \
            --useWebAssemblySIMD=true \
            --useWebAssemblyRelaxedSIMD=true \
            --useWebAssemblyTailCalls=true \
            --useWebAssemblyExtendedConstantExpressions=true \
            --useWasmLLInt=true \
            --useWebAssembly=true \
            --wasmLLIntTiersUpToBBQ=true",
        'develop_shell_sm':
        "--wasm-compiler=baseline+optimizing \
            --setpref=wasm_exnref=true \
            --setpref=wasm_gc=true \
            --setpref=wasm_js_string_builtins=true \
            --setpref=wasm_memory_control=true \
            --setpref=wasm_moz_intgemm=true \
            --setpref=wasm_multi_memory=true \
            --setpref=wasm_relaxed_simd=true \
            --setpref=wasm_tail_calls=true \
            --setpref=wasm_test_serialization=true",
    }
    test_samples(dir_path_map, arg_map, develop_shell_map,
                 develop_shell_args_map)


if __name__ == '__main__':
    main()
