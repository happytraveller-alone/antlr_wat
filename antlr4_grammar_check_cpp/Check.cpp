#include "Check.h"

void CheckDirectory(const std::string_view document_check_path, const std::string_view js_enginee_name) {
  // 检查待拷贝的文件夹是否存在同时检查文件夹内.wat尾缀的文件个数，个数为0报错
  // 检查
  if (std::filesystem::is_directory(document_check_path) &&
      std::filesystem::exists(document_check_path)) {
    std::cout << js_enginee_name <<"文件夹存在" << std::endl;
    int wat_file_num = 0;
    for (auto &p : std::filesystem::directory_iterator(document_check_path)) {
      if (p.path().extension() == ".wat") {
        wat_file_num++;
      }
    }
    if (wat_file_num == 0) {
      std::cout << js_enginee_name<<"文件夹下没有.wat文件" << std::endl;
      // return 0;
    } else {
      std::cout << js_enginee_name <<"内wat文件个数：" << wat_file_num << std::endl;
    }
  }
}

void FileCopyAndRename(const std::string_view document_check_path, const std::string_view new_copy_path, const std::string_view js_enginee_name) {
  // 批量进行分析，查看当前语法的问题
  int valid_file_count = 0;
  for (auto &p : std::filesystem::directory_iterator(document_check_path)) {
    
    if (p.path().extension() == ".wat") {
      std::string file_name = p.path().filename().string();
      std::string new_file_name = std::string(js_enginee_name) + "_" + file_name;
      std::string new_file_path = std::string(new_copy_path) + "/" + new_file_name;
      std::string old_file_path = std::string(document_check_path) + "/" + file_name;
      std::filesystem::copy_file(old_file_path, new_file_path);
      valid_file_count++;
    }
  }
  fprintf(stdout, "%s valid_file_count: %d\n", js_enginee_name.data(), valid_file_count);
}

void DocumentClear(const std::string_view document_check_path) {
  // 清空文件夹,删除所有文件和文件夹
  for (auto &p : std::filesystem::directory_iterator(document_check_path)) {
    std::filesystem::remove_all(p.path());
  }
  // 延时3s
  // std::this_thread::sleep_for(std::chrono::seconds(3));
}

void DocumentCreate(const std::string_view input_file_path, const std::string_view output_file_path) {
  // 创建文件夹
  for (auto &p : std::filesystem::directory_iterator(input_file_path)) {
    std::string file_name = p.path().filename().string();
    // 去除尾缀.wat
    file_name = file_name.substr(0, file_name.length() - 4);
    std::string new_file_path = std::string(output_file_path) + "/" + file_name;
    std::filesystem::create_directory(new_file_path);
  }
}
int main() {
  // 删除文件的<EOF>
  // system("sed -i 's/<EOF>//g' test2_output.txt");
  // // wat-desugar进行格式化
  // system("wat-desugar test2_output.txt --enable-all
  // --output=test2_output.wat"); customVisitor.visit(tree);
  // customVisitor.customoutput();

  // 批量文件的拷贝，将文件拷贝到input_file/testwasm文件夹下
  /*
    1. 给定指定文件夹路径（检索路径是否存在，检查路径下是否存在文件，不存在路径或者文件不存在则报错）
    2. 遍历文件夹下所有文件，获取所有文件名称，在获取的文件名称前添加父目录名称+‘-’名字构成新文件名称
    3. 将原文件拷贝到新文件中
    4. 用新名称替换拷贝后的文件名称
  */
  // 检查待拷贝的文件夹是否存在同时检查文件夹内.wat尾缀的文件个数，个数为0报错
  std::string document_check_path_v8 = "/home/xyf/antlr_wat/antlr4_grammar_check_cpp/input_file/v8";
  std::string document_check_path_sm = "/home/xyf/antlr_wat/antlr4_grammar_check_cpp/input_file/sm";
  std::string document_check_path_jsc = "/home/xyf/antlr_wat/antlr4_grammar_check_cpp/input_file/jsc";
  // 检查
  CheckDirectory(document_check_path_v8, "v8");
  CheckDirectory(document_check_path_sm, "spidermonkey");
  CheckDirectory(document_check_path_jsc, "jsc");
  // 获取文件夹下所有.wat文件名称并统一添加指定前缀，建立各个引擎的poc名称库
  std::string test_check_path_all =  "/home/xyf/antlr_wat/antlr4_grammar_check_cpp/input_file/testwasm";
  DocumentClear(test_check_path_all);
  FileCopyAndRename(document_check_path_v8, test_check_path_all, "v8");
  FileCopyAndRename(document_check_path_sm, test_check_path_all, "spidermonkey");
  FileCopyAndRename(document_check_path_jsc, test_check_path_all, "jsc");
  // 批量进行分析，查看当前语法的问题
  std::string output_file_path = "/home/xyf/antlr_wat/antlr4_grammar_check_cpp/output_file";
  DocumentClear(output_file_path);
  // 根据testwasm文件夹下的每个文件在output_file文件夹下生成对应的文件夹，文件夹名称为testwasm文件夹下的文件名称
  DocumentCreate(test_check_path_all,output_file_path);
  // 遍历output_file文件夹下的所有文件夹名称，调用输入文件构建类分析
  CustomWatVisitor *custom_wat_visitor;
  for (auto &p : std::filesystem::directory_iterator(test_check_path_all)) {
    std::string file_name = p.path().filename().string();
    std::string dir_name = file_name.substr(0, file_name.length() - 4);
    std::string input_file_path = std::string(test_check_path_all) + "/" + file_name;
    std::string output_each_file_path = std::string(output_file_path) + "/" + dir_name;
    fprintf(stdout, "\n\ninput_file_path: %s\n", input_file_path.c_str());
    fprintf(stdout, "output_file_path: %s\n", output_each_file_path.c_str());
    custom_wat_visitor = new CustomWatVisitor(input_file_path,output_each_file_path);
    custom_wat_visitor->printParseTree();
    custom_wat_visitor->visit(custom_wat_visitor->getParseTree());
    delete custom_wat_visitor;
    custom_wat_visitor = nullptr;
  }


  // CustomWatVisitor custom_wat_visitor(
  //     "../input_file/testfile/test2.wat", "../output_file/test2_original_output.txt",
  //     "../output_file/test2_rewrite_output.txt",
  //     "../output_file/test2_lexer_error_output.txt",
  //     "../output_file/test2_parser_error_output.txt",
  //     "../output_file/test2_format_output.wat");
  // custom_wat_visitor.printParseTree();
  // custom_wat_visitor.visit(custom_wat_visitor.getParseTree());
  // custom_wat_visitor.printRewriterOriginal();
  // custom_wat_visitor.printRewriterChanged();
  return 0;
}
