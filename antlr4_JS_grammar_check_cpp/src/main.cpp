#include "GrammarCheck.h"

int main() {
    std::string output_file_path = "/home/xyf/antlr_wat/antlr4_JS_grammar_check_cpp/outputfile";
    DocumentClear(output_file_path);
    std::string input_file_path = "/home/xyf/antlr_wat/antlr4_JS_grammar_check_cpp/inputfile";
    DocumentCreate(input_file_path, output_file_path, ".js");

    CustomJavaScriptVisitor *custom_javascript_visitor;

    for(auto &p : std::filesystem::directory_iterator(input_file_path)){
        std::string file_name = p.path().filename().string();
        std::string dir_name = file_name.substr(0, file_name.length() - std::string(".js").length());
        std::string input_each_file_path = input_file_path + "/" + file_name;
        std::string output_each_file_path = output_file_path + "/" + dir_name;
        // std::string new_file_path = output_file_path + "/" + file_name;
        custom_javascript_visitor = new CustomJavaScriptVisitor(input_each_file_path, output_each_file_path);
        custom_javascript_visitor->printParseTree();
        delete custom_javascript_visitor;
        custom_javascript_visitor = nullptr;
        // custom_javascript_visitor->customoutput(new_file_path);
    }
    // GrammarCheck grammarCheck;
    // grammarCheck.check();
    cout << "Hello, World!" << endl;
    return 0;
}