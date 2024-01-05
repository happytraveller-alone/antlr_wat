#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <random>
#include <array>
#include <functional>
#include <map>
#include <utility>

#include "WatLexer.h"
#include "WatParser.h"
#include "WatParserBaseVisitor.h"
#include "WatParserVisitor.h"
#include "antlr4-runtime.h"
#include "TokenStreamRewriter.h"


using namespace antlr4;
using namespace std;
using FuncType = std::function<void(Token *,const std::string&)>;
// Path: antlr_wat/antlr4_grammar_check_cpp/Check.h
class CustomWatVisitor : public WatParserBaseVisitor{
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
    // start rule
    WatParser::ModuleContext *tree;
    

    // token rewriter
    TokenStreamRewriter rewriter_original;
    TokenStreamRewriter rewriter_changed;
    // visitor output file
    std::string original_output_filename;
    std::ofstream original_outputfile;
    // rewriter output file
    std::string rewriter_output_filename;
    std::ofstream rewriter_outputfile;
    
    // 随机数生成器
    mt19937 gen;
    // 均匀分布
    uniform_int_distribution<> dist;

    // 替换函数map
    std::unordered_map<long long, std::function<void(Token *,const std::string&)>> funcMap;

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

    // 缓冲区，存储visitTerminal的终端节点文本
    std::string buffer;

    // // lexer error output file
    // std::ofstream lexer_error_outputfile;
    // // parser error output file
    // std::ofstream parser_error_outputfile;
    // format output file
    std::string format_filename;
    std::ofstream format_outputfile;
    

    class CustomErrorListener : public BaseErrorListener {
    private:
        std::ofstream error_output;
        std::string filename;
        CustomWatVisitor* CustomWatVisitor;
    public:
        CustomErrorListener(const string& file): error_output(file),filename(file) {
            if(error_output.is_open()) {
                std::cout << filename << " open file success" << std::endl;
            } else {
                std::cerr << filename << " open file failed" << std::endl;
                exit(1);
            }
        }
        ~CustomErrorListener() {
            if (error_output.is_open()) {
                std::cout << filename << " close file success" << std::endl;
            } else {
                std::cerr << filename << " close file failed" << std::endl;
                exit(1);
            }
        }
        
        // lexer syyntactic error
        void syntaxError(Recognizer *recognizer, Token *offendingSymbol, size_t line, size_t charPositionInLine,
                    const std::string &msg, std::exception_ptr e) override {
            // std::ostringstream oss;
            std::string error_message = "line " + std::to_string(line) + ":" + 
                                        std::to_string(charPositionInLine) + " " + msg;
            error_output << error_message << std::endl;
        }

    };

    // custom error listener
    CustomErrorListener LexerErrorListener;
    // custom error listener
    CustomErrorListener ParserErrorListener;
public:
    
    CustomWatVisitor(std::string input_filename, std::string visitor_filename, 
                        std::string rewriter_filename, std::string lexer_error_filename,
                        std::string parser_error_filename, std::string format_filename): 
        input_filename(input_filename),
        input_file(input_filename),
        stream(input_file),
        lexer(&stream),
        tokens(&lexer),
        parser(&tokens),
        rewriter_original(&tokens),
        rewriter_changed(&tokens),
        original_output_filename(visitor_filename),
        original_outputfile(visitor_filename) ,
        rewriter_output_filename(rewriter_filename),
        rewriter_outputfile(rewriter_filename),
        format_filename(format_filename),
        format_outputfile(format_filename),
        LexerErrorListener(lexer_error_filename),
        ParserErrorListener(parser_error_filename) {
        // file check
        check_file_open(original_outputfile, original_output_filename);
        check_file_open(rewriter_outputfile, rewriter_output_filename);
        // check_file_open(lexer_error_outputfile, "lexer_error_outputfile");
        // check_file_open(parser_error_outputfile, "parser_error_outputfile");
        check_file_open(format_outputfile, format_filename);
        
        // 随机数生成器
        std::random_device rd;
        gen = std::mt19937(rd());

        // Create lexer error listener
        // CustomErrorListener LexerListener(lexer_error_filename);
        lexer.removeErrorListeners();
        lexer.addErrorListener(&LexerErrorListener);
        // Create parser error listener
        // CustomErrorListener ParserListener(parser_error_filename);
        parser.removeErrorListeners();
        parser.addErrorListener(&ParserErrorListener);
        tree = parser.module();
        funcMap = {
            // {WatLexer::EOF,      [this](Token *token,const std::string& text) { rewriter_changed.replace(token, text); }},
            {WatLexer::BINARY,   [this](Token *token,const std::string& text) { rewriter_changed.replace(token, getRandomBinary(text)); }},
            {WatLexer::CONVERT,  [this](Token *token,const std::string& text) { rewriter_changed.replace(token, getRandomConvert(text)); }},
            {WatLexer::CONST,    [this](Token *token,const std::string& text) { rewriter_changed.replace(token, getRandomConst(text)); }},
            {WatLexer::LOAD,     [this](Token *token,const std::string& text) { rewriter_changed.replace(token, getRandomLoad(text)); }},
            {WatLexer::STORE,    [this](Token *token,const std::string& text) { rewriter_changed.replace(token, getRandomStore(text)); }},
            {WatLexer::COMPARE,  [this](Token *token,const std::string& text) { rewriter_changed.replace(token, getRandomCompare(text)); }}
        };
    }

    ~CustomWatVisitor() {
        check_file_close(original_outputfile, original_output_filename);
        check_file_close(rewriter_outputfile, rewriter_output_filename);
        check_file_close(format_outputfile, format_filename);
    }

    // 检查文件关闭
    void check_file_close(std::ofstream& file, const std::string& filename) {
        if (file.is_open()) {
            std::cout << filename << " close file success" << std::endl;
        } else {
            std::cerr << filename << " close file failed" << std::endl;
            exit(1);
        }
    }
    // 检查文件打开
    void check_file_open(std::ofstream& file, const std::string& filename) {
        if (!file.is_open()) {
            std::cerr << filename << " open file failed" << std::endl;
            exit(1);
        } else {
            std::cout << filename << " open file success" << std::endl;
    }
}
    
    // 模板替换函数
    template <typename T, size_t N>
    std::string getRandom(const std::string& text, const std::array<T, N>& arr, const std::map<std::string, std::pair<int, int>>& dist_map){
        // std::uniform_int_distribution<> dist;
        // std::cout << "process: " << text << std::endl;
        std::string result = text;
        auto it = dist_map.find(text.substr(0, 3));
        if (it->second.first < it->second.second && it != dist_map.end()) {
            dist = std::uniform_int_distribution<>(it->second.first, it->second.second);
            do {
                int random = dist(gen);
                result = arr[random];
            } while(result.compare(text) == 0);
            // std::cout << "result: " << result << std::endl;
        }
        
        return result;
    }
    // 换BINARY指令,已重构
    std::string getRandomBinary(const std::string& text){return getRandom(text, binaryArray, dist_map_binary_array);}
    // 换CONVERT指令,已重构
    std::string getRandomConvert(const std::string& text){return getRandom(text, convertArray, dist_map_convert_array);}
    // 换CONST指令,已重构
    std::string getRandomConst(const std::string& text){return getRandom(text, constArray, dist_map_const_array);}
    // 换LOAD指令,已重构
    std::string getRandomLoad(const std::string& text){return getRandom(text, loadArray, dist_map_load_array);}
    // 换STORE指令,已重构
    std::string getRandomStore(const std::string& text){return getRandom(text, storeArray, dist_map_store_array);}
    // 换COMPARE指令,已重构
    std::string getRandomCompare(const std::string& text){return getRandom(text, compareArray, dist_map_compare_array);}


    // antlrcpp::Any visitPlain_instr(WatParser::Plain_instrContext *ctx) override {
    //     // 缓冲区存储
    //     // buffer += ctx->getText() + " ";
    //     // 输出
    //     std::cout << "visitPlain_instr: " << ctx->getText() << std::endl;
    //     // 插入空格
    //     // rewriter_changed.insertAfter(ctx->getStop(), "changed");
    //     return visitChildren(ctx);
    //     // visitChildren(ctx);
    // }
    
    // 输出rewriter_changed
    std::string getRewriterChanged(){
        return rewriter_changed.getText();
    }

    // 节点访问换指令
    antlrcpp::Any visitTerminal(tree::TerminalNode* node) override {
        // 输出终端节点的文本
        std::string text = node->getText();
        // 获取终端节点的类型
        auto type = node->getSymbol()->getType();
        auto symbol = node->getSymbol();
        
        // 查找对应的函数并执行
        if(funcMap.count(type) > 0) {
            if(type == WatLexer::EOF){
                funcMap[type](node->getSymbol(), "\r\n");
                // 修改rewriter存储
                rewriter_changed.insertAfter(symbol, " ");
                // 原始rewriter存储
                rewriter_original.insertAfter(symbol, "\r\n");
                // 缓冲区存储
                buffer += "\r\n";
            }
            else{
                // std::cout << "visitTerminal:" << text << " " << type <<std::endl;
                funcMap[type](symbol, node->getText());
                // 修改rewriter存储
                rewriter_changed.insertAfter(symbol, " ");
                // 原始rewriter存储
                rewriter_original.insertAfter(symbol, " ");
                // 缓冲区存储
                buffer += text + " ";
            }
            
        }
        else{
            // 修改rewriter存储
            rewriter_changed.insertAfter(symbol, " ");
            // 原始rewriter存储
            rewriter_original.insertAfter(symbol, " ");
            // 缓冲区存储
            buffer += text + " ";
        }
        return antlrcpp::Any();
    }

    // 获取解析树
    WatParser::ModuleContext* getParseTree(){
        return tree;
    }

    // 打印解析树访问
    void printParseTree(){
        // WatParser::ModuleContext *tree = parser.module();
        // Print the parse tree (LISP-style)
        std::cout << std::endl <<"Parse tree: " << std::endl <<
            tree->toStringTree(&parser,false) << std::endl << std::endl;
    }

    // 打印buffer
    void printBuffer(){
        std::cout << std::endl << "buffer: " << std::endl << buffer << std::endl << std::endl;
    }

    // 打印原始rewriter
    void printRewriterOriginal(){
        std::cout << std::endl << "rewriter_original: " << std::endl << rewriter_original.getText() << std::endl << std::endl;
    }

    // 打印修改rewriter
    void printRewriterChanged(){
        std::cout << std::endl << "rewriter_changed: " << std::endl << rewriter_changed.getText() << std::endl << std::endl;
    }
};

const std::map<std::string, std::pair<int, int>> CustomWatVisitor::dist_map_binary_array = {
    {"i32", {0, 14}},
    {"i64", {15, 29}},
    {"f32", {30, 36}},
    {"f64", {37, 43}}
};

const std::map<std::string, std::pair<int, int>> CustomWatVisitor::dist_map_convert_array = {
    {"i32", {0, 5}},
    {"i64", {6, 12}},
    {"f32", {13, 18}},
    {"f64", {19, 24}}
};

const std::map<std::string, std::pair<int, int>> CustomWatVisitor::dist_map_const_array = {
    {"i32", {0, 0}},
    {"i64", {1, 1}},
    {"f32", {2, 2}},
    {"f64", {3, 3}}
};

const std::map<std::string, std::pair<int, int>> CustomWatVisitor::dist_map_load_array = {
    {"i32", {0, 4}},
    {"i64", {5, 11}},
    {"f32", {12, 12}},
    {"f64", {13, 13}}
};

const std::map<std::string, std::pair<int, int>> CustomWatVisitor::dist_map_store_array = {
    {"i32", {0, 2}},
    {"i64", {3, 6}},
    {"f32", {7, 7}},
    {"f64", {8, 8}}
};

const std::map<std::string, std::pair<int, int>> CustomWatVisitor::dist_map_compare_array = {
    {"i32", {0, 9}},
    {"i64", {10, 19}},
    {"f32", {20, 25}},
    {"f64", {26, 31}},
};

// 替换array初始化
const std::array<std::string, 44> CustomWatVisitor::binaryArray = {
    "i32.add", "i32.sub", "i32.mul", "i32.div_s", "i32.div_u", "i32.rem_s", "i32.rem_u", "i32.and", "i32.or",
    "i32.xor", "i32.shl", "i32.shr_s", "i32.shr_u", "i32.rotl", "i32.rotr", "i64.add", "i64.sub", "i64.mul",
    "i64.div_s", "i64.div_u", "i64.rem_s", "i64.rem_u", "i64.and", "i64.or", "i64.xor", "i64.shl", "i64.shr_s",
    "i64.shr_u", "i64.rotl", "i64.rotr", "f32.add", "f32.sub", "f32.mul", "f32.div", "f32.min", "f32.max",
    "f32.copysign", "f64.add", "f64.sub", "f64.mul", "f64.div", "f64.min", "f64.max", "f64.copysign"
};
const std::array<std::string, 25> CustomWatVisitor::convertArray = {
    "i32.wrap_i64", "i32.trunc_f32_s", "i32.trunc_f32_u", "i32.trunc_f64_s",
    "i32.trunc_f64_u", "i32.reinterpret_f32", "i64.extend_i32_s", "i64.extend_i32_u", 
    "i64.trunc_f32_s", "i64.trunc_f32_u", "i64.trunc_f64_s", "i64.trunc_f64_u", "i64.reinterpret_f64",
    "f32.convert_i32_s", "f32.convert_i32_u", "f32.convert_i64_s", "f32.convert_i64_u", 
    "f32.demote_f64", "f32.reinterpret_i32", "f64.convert_i32_s", "f64.convert_i32_u", 
    "f64.convert_i64_s", "f64.convert_i64_u", "f64.promote_f32",  "f64.reinterpret_i64"
};
const std::array<std::string, 4> CustomWatVisitor::constArray = {
    "i32.const", "i64.const", "f32.const", "f64.const"
};
const std::array<std::string, 14> CustomWatVisitor::loadArray = {
    "i32.load", "i32.load8_s", "i32.load8_u", "i32.load16_s", "i32.load16_u",
    "i64.load", "i64.load8_s", "i64.load8_u", "i64.load16_s", "i64.load16_u",
    "i64.load32_s", "i64.load32_u", "f32.load", "f64.load"
};
const std::array<std::string, 9> CustomWatVisitor::storeArray = {
    "i32.store", "i32.store8", "i32.store16",
    "i64.store", "i64.store8", "i64.store16","i64.store32",
    "f32.store", "f64.store",
};
const std::array<std::string, 32> CustomWatVisitor::compareArray = {
    "i32.eq", "i32.ne", "i32.lt_s", "i32.lt_u",
    "i32.gt_s", "i32.gt_u", "i32.le_s", "i32.le_u",
    "i32.ge_s", "i32.ge_u", "i64.eq", "i64.ne",
    "i64.lt_s", "i64.lt_u", "i64.gt_s", "i64.gt_u",
    "i64.le_s", "i64.le_u", "i64.ge_s", "i64.ge_u",
    "f32.eq", "f32.ne", "f32.lt", "f32.gt",
    "f32.le", "f32.ge", "f64.eq", "f64.ne",
    "f64.lt", "f64.gt", "f64.le", "f64.ge"
};


// class GrammarCheck: public Error {
// private:
//     // lexer error output file
//     std::ofstream lexer_error_outputfile;
//     // parser error output file
//     std::ofstream parser_error_outputfile;
//     // visitor output file
// public:
//     void SpecificationGrammarCheck() {}
// };