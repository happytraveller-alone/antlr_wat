# generate wasm.js command
python3 generator.py testwasm.js
# format python code
yapf --style pep8 -i generator.py