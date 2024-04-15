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
    result += '\nbuilder.addExport(\'main\', 0)\n'
    result += 'const instance = builder.instantiate()\n'
    result += 'instance.export.main()\n'

    return result


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
    wasm_funtion_body_grammar = Grammar()
    err_functionbody = wasm_funtion_body_grammar.parse_from_file(
        os.path.join(grammar_dir, 'wasmfunctionbody.txt'))
    if err_functionbody > 0:
        print('There were errors parsing wasm function body grammar')
        return

    wasm_type_grammar = Grammar()
    err_type = wasm_type_grammar.parse_from_file(
        os.path.join(grammar_dir, 'wasmtype.txt'))
    if err_type > 0:
        print('There were errors parsing wasm type grammar')
        return

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


def main():
    # /home/xyf/antlr_wat/wasm_domato/webassembly
    fuzz_dir = os.path.dirname(__file__)
    # /home/xyf/antlr_wat/wasm_domato/webassembly/grammar
    grammar_dir = os.path.join(fuzz_dir, 'grammar')
    # /home/xyf/antlr_wat/wasm_domato/webassembly/output
    output_dir = os.path.join(fuzz_dir, 'output')

    if len(sys.argv) > 1:
        outfile = sys.argv[1]
        GenerateSamples(grammar_dir, output_dir, [outfile])
    else:
        print('Arguments missing')
        print("Usage:")
        print("\tpython generator.py <output file>")
        print(
            "\tpython generator.py --output_dir <output directory> --no_of_files <number of output files>"
        )
        # sys.exit(1)


if __name__ == '__main__':
    main()
