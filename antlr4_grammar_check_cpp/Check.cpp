#include "Check.h"

int main() {
    // Create an input stream from the file
    ifstream input("../input_file/test2.wat");
    // Create a CharStream that reads from standard input
    ANTLRInputStream stream(input);
    // Create a lexer and parser
    WatLexer lexer(&stream);
    // Create a token stream
    CommonTokenStream tokens(&lexer);
    // Create a parser that feeds off the token stream
    WatParser parser(&tokens);
    // Start parsing from the root rule
    // tree::ParseTree *tree = parser.module();
    WatParser::ModuleContext *tree = parser.module();
    // Print the parse tree (LISP-style)
    cout << "Parse tree: " << tree->toStringTree(&parser,false) << endl;
    
    // 设置错误处理
    parser.removeErrorListeners();
    parser.addErrorListener(new BaseErrorListener());
    // 使用命令对输出文件进行整理
    // 删除文件的<EOF>
    // system("sed -i 's/<EOF>//g' test2_output.txt");
    // // wat-desugar进行格式化
    // system("wat-desugar test2_output.txt --enable-all --output=test2_output.wat");


    // 设置Rewriter
    TokenStreamRewriter rewriter(&tokens);
    // 输出重写后的内容
    std::cout << std::endl << "rewriter output: " << std::endl;
    // 使用Visitor遍历AST并输出重写后的内容
    CustomWatVisitor customVisitor(rewriter,"../output_file/test2_original_output.txt",
        "../output_file/test2_rewrite_output.txt");
    customVisitor.visit(tree);
    customVisitor.customoutput();


    return 0;
}
