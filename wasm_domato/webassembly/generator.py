from __future__ import print_function
import os
import re
import random
import sys

parent_dir = os.path.abspath(os.path.join(os.path.dirname(__file__), os.pardir))
sys.path.append(parent_dir)
from grammar import Grammar

_N_MAIN_LINES = 1000
_N_EVENTHANDLER_LINES = 500

def GenerateNewSample(wasmgrammar, num_lines):
    """Parses grammar rules from string.

    Args:
      wasmgrammar: Grammar for generating wasm code.

    Returns:
      A string containing sample data.
    """
    result = ''
    result += wasmgrammar._generate_code(num_lines)

    return result



def generate_samples(grammar_dir, outfiles):
    """Generates a set of samples and writes them to the output files.

    Args:
      grammar_dir: directory to load grammar files from.
      outfiles: A list of output filenames.
    """

    wasmgrammar = Grammar()
    err = wasmgrammar.parse_from_file(os.path.join(grammar_dir, 'wasm.txt'))
    if err > 0:
        print('There were errors parsing wasm grammar')
        return

    for outfile in outfiles:
        result = GenerateNewSample(wasmgrammar, 10)
        if result is not None:
            print('Writing a sample to ' + outfile)
            try:
                f = open(outfile, 'w')
                f.write(result)
                f.close()
            except IOError:
                print('Error writing to output')
    return


def main():
    fuzz_dir = os.path.dirname(__file__)

    multiple_samples = False

    if len(sys.argv) > 1:
        outfile = sys.argv[1]
        generate_samples(fuzz_dir, [outfile])
    else:
        print('Arguments missing')
        print("Usage:")
        print("\tpython generator.py <output file>")
        print("\tpython generator.py --output_dir <output directory> --no_of_files <number of output files>")
        # sys.exit(1)

if __name__ == '__main__':
    main()

