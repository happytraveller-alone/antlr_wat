#include <algorithm>
#include <array>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <exception>
#include <filesystem>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <random>
#include <sstream>
#include <string>
#include <thread>
#include <unordered_map>
#include <utility>

#include "TokenStreamRewriter.h"
#include "antlr4-runtime.h"
#include "src/StrLexer.h"
#include "src/StrParser.h"
#include "src/StrParserBaseVisitor.h"
#include "src/StrParserVisitor.h"

#define ENABLE_DEBUG 1

using namespace antlr4;
using namespace std;
using FuncType = std::function<void(Token *, const std::string &)>;

class FileHandler {
private:
  std::ofstream OUTPUTFILE;
  std::string FILENAME;
  std::string FILEPATH;

public:
  FileHandler(const std::string &filename)
      : OUTPUTFILE(filename), FILENAME(filename) {
    if (fileExists(FILENAME)) {
      fileClose(OUTPUTFILE);
      fileRemove(FILENAME);
    }
    fileCreate(FILENAME);
    setAbsolutePath(filename);
  }
  ~FileHandler() { fileClose(OUTPUTFILE); }

  bool fileExists(const std::string &filenamepath) {
    return std::filesystem::exists(filenamepath);
  }
  void fileClose() { OUTPUTFILE.close(); }
  void fileOpen() { OUTPUTFILE.open(FILENAME, std::ios::out); }
  void fileClose(std::ofstream &file) { file.close(); }
  void fileRemove(const std::string &filenamepath) {
    if (!std::filesystem::remove(filenamepath)) {
      throw std::runtime_error("Failed to delete file: " + filenamepath + "\n");
    }
  }
  void fileCreate(const std::string &filenamepath) {
    OUTPUTFILE.open(filenamepath, std::ios::out);
    if (!OUTPUTFILE) {
      OUTPUTFILE.close();
      throw std::runtime_error("Failed to create file: " + filenamepath + "\n");
    }
  }
  void setAbsolutePath(const std::string &filename) {
    if (fileExists(filename)) {
      FILEPATH = std::filesystem::absolute(filename).string();
    }
  }
  void writeOutputFile(std::string_view filestring) {
    if (OUTPUTFILE.is_open()) {
      // fprintf(stderr, "writeOutputFile %s\n", filestring.data());
      OUTPUTFILE.close();
      // OUTPUTFILE << filestring;
    }
    OUTPUTFILE.open(FILENAME, std::ios::app);
    OUTPUTFILE << filestring;
  }
  void checkFileOpen() {
    if (OUTPUTFILE.is_open()) {
      fprintf(stdout, "%s open file successfully.\n", FILENAME.c_str());
    } else {
      throw std::runtime_error(FILENAME + " open file failed\n");
    }
  }
  void checkFileClose() {
    if (OUTPUTFILE.is_open()) {
      throw std::runtime_error(FILENAME + " close file failed\n");
    } else {
      fprintf(stdout, "%s close file successfully.\n", FILENAME.c_str());
    }
  }
  std::string getFilename() { return FILENAME; }
};

class CustomErrorListener : public BaseErrorListener {
private:
  FileHandler ERROROUTPUT;
  // LexerErrorListener LexerError;
public:
  CustomErrorListener(const std::string &file) : ERROROUTPUT(file) {
    ERROROUTPUT.fileOpen();
  }
  ~CustomErrorListener() {
    try {
      ERROROUTPUT.fileClose();
      // fprintf(stdout, "CustomErrorListener destructor %s \n",
      // ERROROUTPUT.getFilename().c_str());
    } catch (const std::exception &e) {
      // log, use e
      std::string exception_message =
          std::string(" Exception: ") + e.what() + "\n";
      fprintf(stderr, "Exception: %s\n", e.what());
    }
  }

  // lexer syyntactic error
  void syntaxError(Recognizer *recognizer, Token *offendingSymbol, size_t line,
                   size_t charPositionInLine, const std::string &msg,
                   std::exception_ptr e) override {
    std::ostringstream buffer;
    buffer << "line " << line << ":" << charPositionInLine << "\n"
           << msg << "\n";
    // 使用 recognizer 和 offendingSymbol 参数
    buffer << "Recognizer: " << recognizer->getGrammarFileName() << "\n";
    buffer << "Offending Symbol: " << offendingSymbol->getText() << "\n";
    std::string error_message = buffer.str();
    ERROROUTPUT.writeOutputFile(error_message);

    // 使用 e 参数
    if (e) {
      try {
        // std::cerr << "Exception:\n";
        // rethrow_exception输出到文件夹中

        std::rethrow_exception(e);
        // ERROROUTPUT.writeOutputFile("Exception:\n");
      } catch (const std::exception &ex) {
        std::string exception_message =
            std::string(" Exception: ") + ex.what() + "\n";
        ERROROUTPUT.writeOutputFile(exception_message);
      }
    }
  }
};

// Path: antlr_wat/antlr4_grammar_check_cpp/Check.h
class CustomStrVisitor : public StrParserBaseVisitor {
private:
  // input stream
  std::string input_filename;
  std::ifstream input_file;
  // char stream
  ANTLRInputStream stream;
  // lexer
  StrLexer lexer;
  // token stream
  CommonTokenStream tokens;
  // paser
  StrParser parser;
  StrParser::ModuleContext *tree;

  // token rewriter
  TokenStreamRewriter rewriter_original;
  TokenStreamRewriter rewriter_changed;
  // visitor output file
  FileHandler original_outputfile;
  // rewriter output file
  FileHandler rewriter_outputfile;

  // 随机数生成器
  mt19937 gen;
  // 均匀分布
  uniform_int_distribution<> dist;

  // 替换函数map
  //   std::unordered_map<long long,
  //                      std::function<void(Token *, const std::string &)>>
  //       funcMap;

  //   // 替换array
  //   static const std::array<std::string, 44> binaryArray;
  //   static const std::array<std::string, 25> convertArray;
  //   static const std::array<std::string, 4> constArray;
  //   static const std::array<std::string, 14> loadArray;
  //   static const std::array<std::string, 9> storeArray;
  //   static const std::array<std::string, 32> compareArray;

  //   // 替换map
  //   static const std::map<std::string, std::pair<int, int>>
  //   dist_map_binary_array; static const std::map<std::string, std::pair<int,
  //   int>>
  //       dist_map_convert_array;
  //   static const std::map<std::string, std::pair<int, int>>
  //   dist_map_const_array; static const std::map<std::string, std::pair<int,
  //   int>> dist_map_load_array; static const std::map<std::string,
  //   std::pair<int, int>> dist_map_store_array; static const
  //   std::map<std::string, std::pair<int, int>>
  //       dist_map_compare_array;

  // format output file
  FileHandler format_outputfile;
  // parse tree file
  FileHandler parse_tree_outputfile;
  // custom error listener
  CustomErrorListener LexerErrorListener;
  // custom error listener
  CustomErrorListener ParserErrorListener;

public:
  CustomStrVisitor(std::string input_filename, std::string parent_path)
      : input_filename(input_filename), input_file(input_filename),
        stream(input_file), lexer(&stream), tokens(&lexer), parser(&tokens),
        rewriter_original(&tokens), rewriter_changed(&tokens),
        original_outputfile(parent_path + "/" + "original_output.txt"),
        rewriter_outputfile(parent_path + "/" + "rewrite_output.txt"),
        format_outputfile(parent_path + "/" + "format_output.txt"),
        parse_tree_outputfile(parent_path + "/" + "parse_tree_output.txt"),
        LexerErrorListener(parent_path + "/" + "lexer_error_output.txt"),
        ParserErrorListener(parent_path + "/" + "parser_error_output.txt") {

    // fprintf(stdout, "second constructor\n");
    // file check
    original_outputfile.fileOpen();
    rewriter_outputfile.fileOpen();
    format_outputfile.fileOpen();
    // original_outputfile.checkFileOpen();
    // rewriter_outputfile.checkFileOpen();
    // format_outputfile.checkFileOpen();

    // 随机数生成器
    std::random_device rd;
    gen = std::mt19937(rd());

    // Create lexer error listener
    lexer.removeErrorListeners();
    lexer.addErrorListener(&LexerErrorListener);
    // Create parser error listener
    parser.removeErrorListeners();
    parser.addErrorListener(&ParserErrorListener);
    // fprintf(stdout, "add lexer error and parser error file\n starting
    // parse................\n"); 解析过程用try catch包裹
    try {
      // 解析
      tree = parser.module();
      // fprintf(stdout, "parse success\n");
    } catch (const std::exception &e) {
      // log, use e
      std::string exception_message =
          std::string(" Exception: ") + e.what() + "\n";
      // fprintf(stderr, "parse Exception: %s\n", e.what());
      LexerErrorListener.syntaxError(&lexer, nullptr, 0, 0, exception_message,
                                     std::current_exception());
      ParserErrorListener.syntaxError(&parser, nullptr, 0, 0, exception_message,
                                      std::current_exception());
    }
    fprintf(stdout, "init CustomStrVisitor success\n");
  }

  ~CustomStrVisitor() {
    // fprintf(stdout, "CustomWatVisitor destructor\n");
    try {
      original_outputfile.fileClose();
    } catch (const std::exception &original_outputfile_e) {
      std::string exception_message =
          std::string(" Exception: ") + original_outputfile_e.what() + "\n";
      fprintf(stderr, "Exception: %s\n", original_outputfile_e.what());
    }
    try {
      rewriter_outputfile.fileClose();
    } catch (const std::exception &rewriter_outputfile_e) {
      std::string exception_message =
          std::string(" Exception: ") + rewriter_outputfile_e.what() + "\n";
      fprintf(stderr, "Exception: %s\n", rewriter_outputfile_e.what());
    }
    try {
      format_outputfile.fileClose();
    } catch (const std::exception &format_outputfile_e) {
      std::string exception_message =
          std::string(" Exception: ") + format_outputfile_e.what() + "\n";
      fprintf(stderr, "Exception: %s\n", format_outputfile_e.what());
    }
  }

  // 获取解析树
  StrParser::ModuleContext *getParseTree() { return tree; }

  // 打印解析树访问
  void printParseTree() {
    // fprintf(stdout, "\nParse tree: \n %s \n\n",
    // getParseTree()->toStringTree(&parser, false).c_str());
    parse_tree_outputfile.writeOutputFile(
        getParseTree()->toStringTree(&parser, true));
  }
};
