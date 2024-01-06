#include "Check.h"

int main() {
  // 删除文件的<EOF>
  // system("sed -i 's/<EOF>//g' test2_output.txt");
  // // wat-desugar进行格式化
  // system("wat-desugar test2_output.txt --enable-all
  // --output=test2_output.wat"); customVisitor.visit(tree);
  // customVisitor.customoutput();
  CustomWatVisitor custom_wat_visitor(
      "../input_file/test1.wat", "../output_file/test2_original_output.txt",
      "../output_file/test2_rewrite_output.txt",
      "../output_file/test2_lexer_error_output.txt",
      "../output_file/test2_parser_error_output.txt",
      "../output_file/test2_format_output.wat");
  custom_wat_visitor.printParseTree();
  // custom_wat_visitor.customoutput();
  custom_wat_visitor.visit(custom_wat_visitor.getParseTree());
  custom_wat_visitor.printBuffer();
  custom_wat_visitor.printRewriterOriginal();
  custom_wat_visitor.printRewriterChanged();
  return 0;
}
