#include <algorithm>
#include <array>
#include <cstdio>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <random>
#include <sstream>
#include <string>
#include <chrono>
#include <thread>
#include <unordered_map>
#include <utility>
#include <exception>

#include "TokenStreamRewriter.h"
#include "src/WatLexer.h"
#include "src/WatParser.h"
#include "src/WatParserBaseVisitor.h"
#include "src/WatParserVisitor.h"
#include "antlr4-runtime.h"

#define ENABLE_DEBUG 0

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
  void fileOpen(){OUTPUTFILE.open(FILENAME, std::ios::out);}
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
    if(OUTPUTFILE.is_open()){
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
    try{
      ERROROUTPUT.fileClose();
      // fprintf(stdout, "CustomErrorListener destructor %s \n", ERROROUTPUT.getFilename().c_str());
    }catch(const std::exception& e){
      // log, use e
      std::string exception_message = std::string(" Exception: ") + e.what() + "\n";
      fprintf(stderr, "Exception: %s\n", e.what());
    }
  }

  // lexer syyntactic error
  void syntaxError(Recognizer *recognizer, Token *offendingSymbol, size_t line,
                   size_t charPositionInLine, const std::string &msg,
                   std::exception_ptr e) override {
    std::ostringstream buffer;
    buffer << "line " << line << ":" << charPositionInLine << "\n" << msg
           << "\n";
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
class CustomWatVisitor : public WatParserBaseVisitor {
private:
  // input stream
  std::string input_filename;
  std::ifstream input_file;
  // char stream
  ANTLRInputStream stream;
  // lexer
  WatLexer lexer;
  // token stream
  CommonTokenStream tokens;
  // paser
  WatParser parser;
  WatParser::ScriptContext *tree;

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
  std::unordered_map<long long, std::function<void(Token *, const std::string &)>> funcMap;

  // 替换array
  static const std::array<std::string, 44> binaryArray;
  static const std::array<std::string, 25> convertArray;
  static const std::array<std::string, 4> constArray;
  static const std::array<std::string, 14> loadArray;
  static const std::array<std::string, 9> storeArray;
  static const std::array<std::string, 32> compareArray;

  // 替换map
  static const std::map<std::string, std::pair<int, int>> dist_map_binary_array;
  static const std::map<std::string, std::pair<int, int>> dist_map_convert_array;
  static const std::map<std::string, std::pair<int, int>> dist_map_const_array;
  static const std::map<std::string, std::pair<int, int>> dist_map_load_array;
  static const std::map<std::string, std::pair<int, int>> dist_map_store_array;
  static const std::map<std::string, std::pair<int, int>> dist_map_compare_array;

  // format output file
  FileHandler format_outputfile;
  // parse tree file
  FileHandler parse_tree_outputfile;
  // custom error listener
  CustomErrorListener LexerErrorListener;
  // custom error listener
  CustomErrorListener ParserErrorListener;

public:
  CustomWatVisitor(std::string input_filename, std::string parent_path)
      : input_filename(input_filename), input_file(input_filename),
        stream(input_file), lexer(&stream), tokens(&lexer), parser(&tokens),
        rewriter_original(&tokens), rewriter_changed(&tokens),
        original_outputfile(parent_path + "/"  + "original_output.txt"),
        rewriter_outputfile(parent_path + "/" + "rewrite_output.txt"),
        format_outputfile(parent_path + "/" + "format_output.txt"),
        parse_tree_outputfile(parent_path + "/" + "parse_tree_output.txt"),
        LexerErrorListener(parent_path + "/"  + "lexer_error_output.txt"),
        ParserErrorListener(parent_path + "/"+ "parser_error_output.txt") {
    
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
    // fprintf(stdout, "add lexer error and parser error file\n starting parse................\n");
    // 解析过程用try catch包裹
    try {
      // 解析
      tree = parser.script();
      // std::cout << "parse success" << std::endl;
      // fprintf(stdout, "parse success\n");
    } catch (const std::exception &e) {
      // log, use e
      std::string exception_message = std::string(" Exception: ") + e.what() + "\n";
      // fprintf(stderr, "parse Exception: %s\n", e.what());
      LexerErrorListener.syntaxError(&lexer, nullptr, 0, 0, exception_message, std::current_exception());
      ParserErrorListener.syntaxError(&parser, nullptr, 0, 0, exception_message, std::current_exception());
      // e.printStackTrace();
    }
    // tree = parser.module();
    funcMap = {
        // {WatLexer::EOF,      [this](Token *token,const std::string& text) {
        // rewriter_changed.replace(token, text); }},
        {WatLexer::BINARY,
         [this](Token *token, const std::string &text) {
           rewriter_changed.replace(token, getRandomBinary(text));
         }},
        {WatLexer::CONVERT,
         [this](Token *token, const std::string &text) {
           rewriter_changed.replace(token, getRandomConvert(text));
         }},
        {WatLexer::CONST,
         [this](Token *token, const std::string &text) {
           rewriter_changed.replace(token, getRandomConst(text));
         }},
        {WatLexer::LOAD,
         [this](Token *token, const std::string &text) {
           rewriter_changed.replace(token, getRandomLoad(text));
         }},
        {WatLexer::STORE,
         [this](Token *token, const std::string &text) {
           rewriter_changed.replace(token, getRandomStore(text));
         }},
        {WatLexer::COMPARE, [this](Token *token, const std::string &text) {
           rewriter_changed.replace(token, getRandomCompare(text));
         }}};

      // std::cout << "init CustomWatVisitor success" << std::endl;
      fprintf(stdout, "init CustomWatVisitor success\n");
  }

  ~CustomWatVisitor() {
    // fprintf(stdout, "CustomWatVisitor destructor\n");
    try{
      original_outputfile.fileClose();
    }catch(const std::exception& original_outputfile_e){
      std::string exception_message = std::string(" Exception: ") + original_outputfile_e.what() + "\n";
      fprintf(stderr, "Exception: %s\n", original_outputfile_e.what());
    }
    try{
      rewriter_outputfile.fileClose();
    }catch(const std::exception& rewriter_outputfile_e){
      std::string exception_message = std::string(" Exception: ") + rewriter_outputfile_e.what() + "\n";
      fprintf(stderr, "Exception: %s\n", rewriter_outputfile_e.what());
    }
    try{
      format_outputfile.fileClose();
    }catch(const std::exception& format_outputfile_e){
      std::string exception_message = std::string(" Exception: ") + format_outputfile_e.what() + "\n";
      fprintf(stderr, "Exception: %s\n", format_outputfile_e.what());
    }
  }

  // 模板替换函数
  template <typename T, size_t N>
  std::string
  getRandom(const std::string &text, const std::array<T, N> &arr,
            const std::map<std::string, std::pair<int, int>> &dist_map) {
    std::string result = text;
    auto it = dist_map.find(text.substr(0, 3));
    if (it->second.first < it->second.second && it != dist_map.end()) {
      dist =
          std::uniform_int_distribution<>(it->second.first, it->second.second);
      do {
        int random = dist(gen);
        result = arr[random];
      } while (result.compare(text) == 0);
      // std::cout << "result: " << result << std::endl;
    }

    return result;
  }
  // 换BINARY指令,已重构
  std::string getRandomBinary(const std::string &text) {
    return getRandom(text, binaryArray, dist_map_binary_array);
  }
  // 换CONVERT指令,已重构
  std::string getRandomConvert(const std::string &text) {
    return getRandom(text, convertArray, dist_map_convert_array);
  }
  // 换CONST指令,已重构
  std::string getRandomConst(const std::string &text) {
    return getRandom(text, constArray, dist_map_const_array);
  }
  // 换LOAD指令,已重构
  std::string getRandomLoad(const std::string &text) {
    return getRandom(text, loadArray, dist_map_load_array);
  }
  // 换STORE指令,已重构
  std::string getRandomStore(const std::string &text) {
    return getRandom(text, storeArray, dist_map_store_array);
  }
  // 换COMPARE指令,已重构
  std::string getRandomCompare(const std::string &text) {
    return getRandom(text, compareArray, dist_map_compare_array);
  }

  // 节点访问换指令
  // antlrcpp::Any visitTerminal(tree::TerminalNode *node) override {
  //   // 输出终端节点的文本
  //   std::string text = node->getText();
  //   // 获取终端节点的类型
  //   auto type = node->getSymbol()->getType();
  //   auto symbol = node->getSymbol();

  //   // 查找对应的函数并执行
  //   auto it = funcMap.find(type);
  //   if (it != funcMap.end()) {
  //     if (type == WatLexer::EOF) {
  //       // funcMap[type](node->getSymbol(), "\r\n");
  //       it->second(symbol, "\r\n");
  //       // 修改rewriter存储
  //       rewriter_changed.insertAfter(symbol, "\r\n");
  //       // 原始rewriter存储
  //       rewriter_original.insertAfter(symbol, "\r\n");
  //       // 缓冲区存储
  //       // buffer += "\r\n";
  //     } else {
  //       // std::cout << "visitTerminal:" << text << " " << type <<std::endl;
  //       // funcMap[type](symbol, node->getText());
  //       it->second(symbol, node->getText());
  //       // 修改rewriter存储
  //       rewriter_changed.insertAfter(symbol, " ");
  //       // 原始rewriter存储
  //       rewriter_original.insertAfter(symbol, " ");
  //       // 缓冲区存储
  //       // buffer += text + " ";
  //     }

  //   } else {
  //     // 修改rewriter存储
  //     rewriter_changed.insertAfter(symbol, " ");
  //     // 原始rewriter存储
  //     rewriter_original.insertAfter(symbol, " ");
  //     // 缓冲区存储
  //     // buffer += text + " ";
  //   }
  //   return antlrcpp::Any();
  // }

  // 获取解析树
  WatParser::ScriptContext *getParseTree() { return tree; }

  // 打印解析树访问
  void printParseTree() {
    // fprintf(stdout, "\nParse tree: \n %s \n\n", getParseTree()->toStringTree(&parser, false).c_str());
    parse_tree_outputfile.writeOutputFile(getParseTree()->toStringTree(&parser, true));
  }

  // 打印原始rewriter
  void printRewriterOriginal() {
    fprintf(stdout, "\nrewriter_original: \n %s \n\n", rewriter_original.getText().c_str());
  }

  // 打印修改rewriter
  void printRewriterChanged() {
    fprintf(stdout, "\nrewriter_changed: \n %s \n\n", rewriter_changed.getText().c_str());
  }
};

const std::map<std::string, std::pair<int, int>>
    CustomWatVisitor::dist_map_binary_array = {{"i32", {0, 14}},
                                               {"i64", {15, 29}},
                                               {"f32", {30, 36}},
                                               {"f64", {37, 43}}};

const std::map<std::string, std::pair<int, int>>
    CustomWatVisitor::dist_map_convert_array = {{"i32", {0, 5}},
                                                {"i64", {6, 12}},
                                                {"f32", {13, 18}},
                                                {"f64", {19, 24}}};

const std::map<std::string, std::pair<int, int>>
    CustomWatVisitor::dist_map_const_array = {
        {"i32", {0, 0}}, {"i64", {1, 1}}, {"f32", {2, 2}}, {"f64", {3, 3}}};

const std::map<std::string, std::pair<int, int>>
    CustomWatVisitor::dist_map_load_array = {{"i32", {0, 4}},
                                             {"i64", {5, 11}},
                                             {"f32", {12, 12}},
                                             {"f64", {13, 13}}};

const std::map<std::string, std::pair<int, int>>
    CustomWatVisitor::dist_map_store_array = {
        {"i32", {0, 2}}, {"i64", {3, 6}}, {"f32", {7, 7}}, {"f64", {8, 8}}};

const std::map<std::string, std::pair<int, int>>
    CustomWatVisitor::dist_map_compare_array = {
        {"i32", {0, 9}},
        {"i64", {10, 19}},
        {"f32", {20, 25}},
        {"f64", {26, 31}},
};

// 替换array初始化
const std::array<std::string, 44> CustomWatVisitor::binaryArray = {
    "i32.add",   "i32.sub",      "i32.mul",   "i32.div_s",   "i32.div_u",
    "i32.rem_s", "i32.rem_u",    "i32.and",   "i32.or",      "i32.xor",
    "i32.shl",   "i32.shr_s",    "i32.shr_u", "i32.rotl",    "i32.rotr",
    "i64.add",   "i64.sub",      "i64.mul",   "i64.div_s",   "i64.div_u",
    "i64.rem_s", "i64.rem_u",    "i64.and",   "i64.or",      "i64.xor",
    "i64.shl",   "i64.shr_s",    "i64.shr_u", "i64.rotl",    "i64.rotr",
    "f32.add",   "f32.sub",      "f32.mul",   "f32.div",     "f32.min",
    "f32.max",   "f32.copysign", "f64.add",   "f64.sub",     "f64.mul",
    "f64.div",   "f64.min",      "f64.max",   "f64.copysign"};
const std::array<std::string, 25> CustomWatVisitor::convertArray = {
    "i32.wrap_i64",        "i32.trunc_f32_s",   "i32.trunc_f32_u",
    "i32.trunc_f64_s",     "i32.trunc_f64_u",   "i32.reinterpret_f32",
    "i64.extend_i32_s",    "i64.extend_i32_u",  "i64.trunc_f32_s",
    "i64.trunc_f32_u",     "i64.trunc_f64_s",   "i64.trunc_f64_u",
    "i64.reinterpret_f64", "f32.convert_i32_s", "f32.convert_i32_u",
    "f32.convert_i64_s",   "f32.convert_i64_u", "f32.demote_f64",
    "f32.reinterpret_i32", "f64.convert_i32_s", "f64.convert_i32_u",
    "f64.convert_i64_s",   "f64.convert_i64_u", "f64.promote_f32",
    "f64.reinterpret_i64"};
const std::array<std::string, 4> CustomWatVisitor::constArray = {
    "i32.const", "i64.const", "f32.const", "f64.const"};
const std::array<std::string, 14> CustomWatVisitor::loadArray = {
    "i32.load",     "i32.load8_s",  "i32.load8_u",  "i32.load16_s",
    "i32.load16_u", "i64.load",     "i64.load8_s",  "i64.load8_u",
    "i64.load16_s", "i64.load16_u", "i64.load32_s", "i64.load32_u",
    "f32.load",     "f64.load"};
const std::array<std::string, 9> CustomWatVisitor::storeArray = {
    "i32.store",   "i32.store8",  "i32.store16", "i64.store", "i64.store8",
    "i64.store16", "i64.store32", "f32.store",   "f64.store",
};
const std::array<std::string, 32> CustomWatVisitor::compareArray = {
    "i32.eq",   "i32.ne",   "i32.lt_s", "i32.lt_u", "i32.gt_s", "i32.gt_u",
    "i32.le_s", "i32.le_u", "i32.ge_s", "i32.ge_u", "i64.eq",   "i64.ne",
    "i64.lt_s", "i64.lt_u", "i64.gt_s", "i64.gt_u", "i64.le_s", "i64.le_u",
    "i64.ge_s", "i64.ge_u", "f32.eq",   "f32.ne",   "f32.lt",   "f32.gt",
    "f32.le",   "f32.ge",   "f64.eq",   "f64.ne",   "f64.lt",   "f64.gt",
    "f64.le",   "f64.ge"};
