from __future__ import print_function
import os
import sys
from grammar import Grammar

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
    result += wasm_type_grammar._generate_code(num_lines)
    result += '\n'
    result += wasm_function_body_grammar._generate_code(num_lines)
    # result += '\nbuilder.addExport(\'main\', 0)\n'
    result += '\nconst instance = builder.instantiate()\n'
    result += 'instance.export.main()\n'

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
    if enable_test == 'True':
        print('Test cases are enabled in v8')
    else :
        print('Test cases are disabled in v8')


def merge_files(file_module_builder, file_wasm_test, file_merged):
    with open(file_module_builder, 'r') as f1, open(file_wasm_test, 'r') as f2, open(file_merged, 'w') as f3:
        f3.write(f1.read())
        f3.write(f2.read())
        f3.close()
    print(f"Files {file_module_builder} and {file_wasm_test} have been merged into {file_merged}.")
    return


def main():
    # /home/xyf/antlr_wat/wasm_domato/webassembly
    fuzz_dir = os.path.dirname(__file__)
    # /home/xyf/antlr_wat/wasm_domato/webassembly/grammar
    grammar_dir = os.path.join(fuzz_dir, 'grammar')
    # /home/xyf/antlr_wat/wasm_domato/webassembly/output
    output_dir = os.path.join(fuzz_dir, 'output')
    # /home/xyf/antlr_wat/wasm_domato/webassembly/input
    input_dir = os.path.join(fuzz_dir, 'input')

    if len(sys.argv) == 1:
        print('Arguments missing')
        print("Usage:")
        print("\tpython generator.py <output file>")
        # print(
        #     "\tpython generator.py --output_dir <output directory> --no_of_files <number of output files>"
        # )
        # sys.exit(1)
    if len(sys.argv) == 2:
        outfile = sys.argv[1]
        GenerateSamples(grammar_dir, output_dir, [outfile])
        merge_files(os.path.join(input_dir, 'wasm-module-builder.js'), \
                os.path.join(output_dir, 'testwasm.js'), \
                os.path.join(output_dir, 'merged_wasm.js'))
    
    if len(sys.argv) == 3:
        outfile = sys.argv[1]
        enable_test = sys.argv[2]
        if enable_test == 'True' or enable_test == 'False':
            GenerateSamples(grammar_dir, output_dir, [outfile])
            merge_files(os.path.join(input_dir, 'wasm-module-builder.js'), \
                os.path.join(output_dir, 'testwasm.js'), \
                os.path.join(output_dir, 'merged_wasm.js'))
            get_test_cases_v8_output(output_dir, enable_test)
        else:
            print("Invalid argument for test cases. Please enter 'True' or 'False' for enable_test commad.")
            print("Usage:")
            print("\tpython generator.py <output file> <enable_test>")

if __name__ == '__main__':
    main()
