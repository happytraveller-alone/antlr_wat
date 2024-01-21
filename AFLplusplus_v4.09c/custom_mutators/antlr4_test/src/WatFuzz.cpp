#include "WatFuzz.h"
#include "StrOverrideVisitor.h"
int main() {
  std::string_view file_path = "/home/xyf/antlr_wat/AFLplusplus_v4.09c/"
                               "custom_mutators/antlr4_test/input/seed2.txt";
  fprintf(stdout, "starting to check seed file %s\n\n", file_path.data());
  std::ifstream input_file(file_path.data());
  // char stream
  ANTLRInputStream stream(input_file);
  // lexer
  StrLexer lexer(&stream);
  // token stream
  CommonTokenStream tokens(&lexer);
  // paser
  StrParser parser(&tokens);
  StrParser::ModuleContext *tree;
  tree = parser.module();
  std::cout << tree->toStringTree(&parser) << std::endl;
  // visit
  // StrOverrideVisitor visitor;
  StrOverrideVisitor *visitor = new StrOverrideVisitor();
  visitor->visit(tree);
  return 0;
}