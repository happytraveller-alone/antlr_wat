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
def generate_sample_body(wasm_function_body_grammar, \
                      wasm_type_grammar, \
                      num_lines):
    result = ''
    result += 'const builder = new WasmModuleBuilder();\n'
    # result += wasm_type_grammar._generate_code(num_lines)
    # result += '\n'
    result += wasm_function_body_grammar._generate_code(num_lines)
    # result += '\nbuilder.addExport(\'main\', 0)\n'
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
                    outfiles):
    wasm_funtion_body_grammar = parse_grammar(grammar_dir,
                                              'wasmfunctionbody.txt')
    wasm_type_grammar = parse_grammar(grammar_dir, 'wasmtype.txt')

    for outfile in outfiles:
        result = generate_sample_body(wasm_funtion_body_grammar, \
                                   wasm_type_grammar, \
                                   1)
        if result is not None:
            print('Writing a sample to ' + outfile)
            try:
                f1 = open(os.path.join(output_merge_dir, outfile), 'w')
                f2 = open(os.path.join(input_dir, 'wasm-module-builder.js'), 'r')
                f1.write(f2.read())
                f2.close()
                f1.write(result)
                f1.close()
                
            except IOError:
                print('Error writing to output')
    return


def get_test_cases_v8_output(output_dir, enable_test, outfiles):
    if enable_test == 'On':
        print('Test cases are enabled in v8')
        v8_executable = "/home/xyf/v8/v8/out/CVE_2024_2887_debug_tag_12.4.176/d8"
        for outfile in outfiles:
            wasm_file = os.path.join(output_dir, outfile)
            command = v8_executable + "\t"  + wasm_file
            result = subprocess.run(command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
            # Get the return code
            return_code = result.returncode
            if(return_code == 11):
                print('Segmentation fault')
                # with open
            # Get the output
            output = result.stdout.decode()
            # Get the error message (if any)
            error = result.stderr.decode()
            # Print the return code, output, and error message
            print(f"Return code: {return_code}")
            print(f"Output: {output}")
            print(f"Error: {error}")
    if enable_test == 'Off':
        print('Test cases are disabled in v8')


def print_usage():
    print("Usage:")
    # print("\tpython generator.py <output file>")
    # print("\tpython generator.py <output file> --enable_test <On/Off>")
    print("\tpython generator.py --output_dir <dir> --no_of_files <count>")
    print("\tpython generator.py --output_dir <dir> --no_of_files <count> --enable_test <On/Off>")
    sys.exit(1)

def validate_enable_test_option(option):
    if option not in ["On", "Off"]:
        print("Invalid argument for test cases. Please enter 'On' or 'Off' for enable_test command.")
        print_usage()
        sys.exit(2)



def generate_samples_name(dir_path_map, out_dir, file_count, enable_test):

    outfiles = [os.path.join(out_dir, f'fuzz-{i:05d}.js') for i in range(file_count)]

    generate_samples(dir_path_map['grammar_dir'], dir_path_map['input_dir'], out_dir, outfiles)
    
    if enable_test == 'On':
        get_test_cases_v8_output(out_dir, enable_test, outfiles)

def check_arguments(dir_path_map, arg_map):
    if '--help' in sys.argv:
        print_usage()
        sys.exit(0)
    for key, value in arg_map.items():
        if key in sys.argv:
            index = sys.argv.index(key)
            try:
                arg_map[key] = sys.argv[index + 1]
            except IndexError:
                print(f"Missing value for {key}")
                print_usage()
    if '--enable_test' in sys.argv:
        validate_enable_test_option(arg_map['--enable_test'])
        print('enable_test is set to ' + arg_map['--enable_test'])
    else:
        print('enable_test is not set, default to Off')
    if '--no_of_files' in sys.argv:
        arg_map['--no_of_files'] = int(arg_map['--no_of_files'])
        print('no_of_files is set to ' + str(arg_map['--no_of_files']))
    else:
        print('no_of_files is not set, default to 1')
    if '--output_dir' in sys.argv:
        if not os.path.isabs(arg_map['--output_dir']):
            arg_map['--output_dir'] = os.path.join(dir_path_map['fuzz_dir'], arg_map['--output_dir'])
        if not os.path.exists(arg_map['--output_dir']):
            os.makedirs(arg_map['--output_dir'])
        print('output_dir is set to ' + arg_map['--output_dir'])
    else:
        print('output_dir is not set, default to output_merge')
        # arg_map['--output_dir'] = dir_path_map['output_merge_dir']
    

def main():
    fuzz_dir = os.path.dirname(__file__)
    # 以上路径整理在map中
    dir_path_map = {
        'fuzz_dir': fuzz_dir,
        'grammar_dir': os.path.join(fuzz_dir, 'grammar'),
        'output_orig_dir': os.path.join(fuzz_dir, 'output_orig'),
        'input_dir': os.path.join(fuzz_dir, 'input'),
        'output_merge_dir': os.path.join(fuzz_dir, 'output_merge')
    }
    # 参数map
    arg_map = {
        '--output_dir': dir_path_map['output_merge_dir'],
        '--no_of_files': 1,
        '--enable_test': 'Off',
        '--help': False
    }
    # 参数填充
    check_arguments(dir_path_map, arg_map)
    # 生成样本
    generate_samples_name(dir_path_map, arg_map['--output_dir'], arg_map['--no_of_files'], arg_map['--enable_test'])

    

if __name__ == '__main__':
    main()


# """
# Merges the contents of two files into a new file.
# Args:
#     file_module_builder (str): The path to the first file.
#     file_wasm_test (str): The path to the second file.
#     file_merged (str): The path to the merged file.
# Returns:
#     None
# """
# def merge_files(file_module_builder, \
#                 file_wasm_test, \
#                 file_merged):

#     with open(file_module_builder, 'r') as f1, \
#          open(file_wasm_test, 'r') as f2, \
#          open(file_merged, 'w') as f3:
#         f3.write(f1.read())
#         f3.write(f2.read())
#         f3.close()
#     print(
#         f"Files {file_module_builder} and {file_wasm_test} have been merged into {file_merged}."
#     )
#     return

# """
# Retrieves the value of the specified command line option.
# Args:
#     option_name (str): The name of the option to retrieve.
# Returns:
#     str or None: The value of the option if found, or None if the option is not present.
# """
# def get_option(option_name):
#     if option_name in sys.argv:
#         index = sys.argv.index(option_name)
#         try:
#             return sys.argv[index + 1]
#         except IndexError:
#             print(f"Missing value for {option_name}")
#             print_usage()
#     return None
