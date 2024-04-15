from __future__ import print_function
import os
import sys
from grammar import Grammar
import subprocess

# import re
# import random

_N_MAIN_LINES = 1000
_N_EVENTHANDLER_LINES = 500
"""
Parses grammar rules from string.

Args:
  wasmgrammar: Grammar for generating wasm code.

Returns:
  A string containing sample data.
"""
def GenerateNewSample(wasm_function_body_grammar, \
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
def GenerateSamples(grammar_dir, \
                    output_dir, \
                    outfiles):
    wasm_funtion_body_grammar = parse_grammar(grammar_dir,
                                              'wasmfunctionbody.txt')
    wasm_type_grammar = parse_grammar(grammar_dir, 'wasmtype.txt')

    for outfile in outfiles:
        result = GenerateNewSample(wasm_funtion_body_grammar, \
                                   wasm_type_grammar, \
                                   1)
        if result is not None:
            print('Writing a sample to ' + outfile)
            try:
                f = open(os.path.join(output_dir, outfile), 'w')
                f.write(result)
                f.close()
            except IOError:
                print('Error writing to output')
    return


def get_test_cases_v8_output(output_dir, enable_test):
    if enable_test == 'On':
        print('Test cases are enabled in v8')
        v8_executable = "/home/xyf/v8/v8/out/CVE_2024_2887_debug_tag_12.4.176/d8"
        wasm_file = os.path.join(output_dir, 'merged_wasm.js')
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


"""
Merges the contents of two files into a new file.
Args:
    file_module_builder (str): The path to the first file.
    file_wasm_test (str): The path to the second file.
    file_merged (str): The path to the merged file.
Returns:
    None
"""
def merge_files(file_module_builder, \
                file_wasm_test, \
                file_merged):

    with open(file_module_builder, 'r') as f1, \
         open(file_wasm_test, 'r') as f2, \
         open(file_merged, 'w') as f3:
        f3.write(f1.read())
        f3.write(f2.read())
        f3.close()
    print(
        f"Files {file_module_builder} and {file_wasm_test} have been merged into {file_merged}."
    )
    return

def get_option(option_name):
    for i in range(len(sys.argv)):
        if (sys.argv[i] == option_name) and ((i + 1) < len(sys.argv)):
            return sys.argv[i + 1]
        elif sys.argv[i].startswith(option_name + '='):
            return sys.argv[i][len(option_name) + 1:]
    return None

def main():
    # /home/xyf/antlr_wat/wasm_domato/webassembly
    fuzz_dir = os.path.dirname(__file__)
    # /home/xyf/antlr_wat/wasm_domato/webassembly/grammar
    grammar_dir = os.path.join(fuzz_dir, 'grammar')
    # /home/xyf/antlr_wat/wasm_domato/webassembly/output
    output_dir = os.path.join(fuzz_dir, 'output')
    # /home/xyf/antlr_wat/wasm_domato/webassembly/input
    input_dir = os.path.join(fuzz_dir, 'input')

    # Check if the number of arguments is correct, arguments missing
    if len(sys.argv) == 1:
        print('Arguments missing')
        print("Usage:")
        print("\tpython generator.py <output file>")
        print("\tpython generator.py <output file> <enable_test>")
        sys.exit(1)
    # python3 generator.py testwasm.js
    if len(sys.argv) == 2:
        print('Generating one sample')
        outfile = sys.argv[1]
        GenerateSamples(grammar_dir, output_dir, [outfile])
        merge_files(os.path.join(input_dir, 'wasm-module-builder.js'), \
                os.path.join(output_dir, 'testwasm.js'), \
                os.path.join(output_dir, 'merged_wasm.js'))
    # python3 generator.py testwasm.js --enable_test On/Off
    if len(sys.argv) == 4:
        print('Generating one sample and running the sample in v8')
        outfile = sys.argv[1]
        enable_test = get_option('--enable_test')
        if enable_test == 'On' or enable_test == 'Off':
            GenerateSamples(grammar_dir, output_dir, [outfile])
            merge_files(os.path.join(input_dir, 'wasm-module-builder.js'), \
                os.path.join(output_dir, 'testwasm.js'), \
                os.path.join(output_dir, 'merged_wasm.js'))
            if(enable_test == 'On'):
                get_test_cases_v8_output(output_dir, enable_test)
        else:
            print(
                "Invalid argument for test cases. Please enter 'On' or 'Off' for enable_test commad."
            )
            print("Usage:")
            print("\tpython generator.py <output file> --enable_test <On/Off>")
    # python3 generator.py --output_dir /home/xyf/antlr_wat/wasm_domato/webassembly/output --no_of_files 1
    if len(sys.argv) == 5:
        multiple_samples = False
        for a in sys.argv:
            if a.startswith('--output_dir='):
                multiple_samples = True
        if '--output_dir' in sys.argv:
            multiple_samples = True
        if multiple_samples:
            out_dir = get_option('--output_dir')
            nsamples = int(get_option('--no_of_files'))
            print('Output directory: ' + out_dir)
            print('Number of samples: ' + str(nsamples))
            if not os.path.exists(out_dir):
                os.mkdir(out_dir)
            outfiles = []
            for i in range(nsamples):
                outfiles.append(os.path.join(out_dir, 'fuzz-' + str(i).zfill(5) + '.html'))
            GenerateSamples(grammar_dir, output_dir, outfiles)
if __name__ == '__main__':
    main()


# import sys

# def get_option(option_name):
#     if option_name in sys.argv:
#         return sys.argv[sys.argv.index(option_name) + 1]
#     else:
#         return None

# def GenerateSamples(grammar_dir, output_dir, outfile):
#     pass

# def merge_files(input_file, output_file, merged_file):
#     pass

# def get_test_cases_v8_output(output_dir, enable_test):
#     pass

# if __name__ == "__main__":
#     grammar_dir = None
#     output_dir = None
#     input_dir = None

#     if len(sys.argv) >= 2:
#         outfile = sys.argv[1]
#         GenerateSamples(grammar_dir, output_dir, [outfile])
#         merge_files(os.path.join(input_dir, 'wasm-module-builder.js'), \
#                 os.path.join(output_dir, 'testwasm.js'), \
#                 os.path.join(output_dir, 'merged_wasm.js'))

#     if len(sys.argv) >= 4:
#         enable_test = get_option('--enable_test')
#         if enable_test is None:
#             enable_test = 'Off'
#         if enable_test == 'On' or enable_test == 'Off':
#             if(enable_test == 'On'):
#                 get_test_cases_v8_output(output_dir, enable_test)
#         else:
#             print(
#                 "Invalid argument for test cases. Please enter 'On' or 'Off' for enable_test command."
#             )
#             print("Usage:")
#             print("\tpython generator.py <output file> --enable_test <On/Off>")
