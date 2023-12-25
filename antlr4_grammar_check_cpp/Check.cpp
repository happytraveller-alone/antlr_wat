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

#include "WatLexer.h"
#include "WatParser.h"
#include "WatParserBaseVisitor.h"
#include "WatParserVisitor.h"
#include "antlr4-runtime.h"
#include "TokenStreamRewriter.h"

using namespace antlr4;
using namespace std;



class CustomWatVisitor : public WatParserBaseVisitor {
private:
    // token rewriter
    TokenStreamRewriter &rewriter;
    // visitor output file
    std::ofstream original_outputfile;
    // rewriter output file
    std::ofstream rewriter_outputfile;
    // 随机数生成器
    mt19937 gen;
    // 均匀分布
    uniform_int_distribution<> dist;

    // 替换array
    static const std::array<std::string, 44> binaryArray;
    static const std::array<std::string, 25> convertArray;
    static const std::array<std::string, 4> constArray;
    static const std::array<std::string, 14> loadArray;
    static const std::array<std::string, 9> storeArray;
    static const std::array<std::string, 32> compareArray;
public:
    CustomWatVisitor(TokenStreamRewriter &rewriter,std::string visitor_filename, std::string rewriter_filename): 
        rewriter(rewriter) , 
        original_outputfile(visitor_filename) ,
        rewriter_outputfile(rewriter_filename) {
        // file check
        if(!original_outputfile.is_open()) {
            std::cerr << "original_outputfile open file failed" << std::endl;
            exit(1);
        }
        else{std::cout << "original_outputfile open file success" << std::endl;}
        if(!rewriter_outputfile.is_open()) {
            std::cerr << "rewriter_outputfile open file failed" << std::endl;
            exit(1);
        }
        else{std::cout << "rewriter_outputfile open file success" << std::endl;}
        
        // 随机数生成器
        std::random_device rd;
        gen = std::mt19937(rd());

        // 替换array初始化
    }

    ~CustomWatVisitor() {
        std::cout << "close files original_outputfile and rewriter_outputfile" << std::endl;
        original_outputfile.close();
        rewriter_outputfile.close();
    }


    // 模板替换函数
    template <typename T, size_t N>
    std::string getRandom(const std::string& text, const std::array<T, N>& arr){
        std::uniform_int_distribution<> dist(0, arr.size() - 1);
        std::string result = text;
        do {
            int random = dist(gen);
            result = arr[random];
        } while(result.compare(0, text.size(), text) == 0);
        return result;
    }
    // 换BINARY指令,已重构
    std::string getRandomBinary(const std::string& text){return getRandom(text, binaryArray);}
    // 换CONVERT指令,已重构
    std::string getRandomConvert(const std::string& text){return getRandom(text, convertArray);}
    // 换CONST指令,已重构
    std::string getRandomConst(const std::string& text){return getRandom(text, constArray);}
    // 换LOAD指令,已重构
    std::string getRandomLoad(const std::string& text){return getRandom(text, loadArray);}
    // 换STORE指令,已重构
    std::string getRandomStore(const std::string& text){return getRandom(text, storeArray);}
    // 换COMPARE指令,已重构
    std::string getRandomCompare(const std::string& text){return getRandom(text, compareArray);}

    // 换值
    antlrcpp::Any visitLiteral(WatParser::LiteralContext *ctx) override {
        // // 获取终端节点的文本
        // std::string text = ctx->getText();
        // // 获取终端节点的类型
        // auto type = ctx->getStart()->getType();
        // 替换，i换i，f换f
        // 定义浮点数范围（例如，非常小的数）
        double double_min = -1e-3;
        double double_max = 1e+3;

        // 浮点数分布
        std::uniform_real_distribution<> double_dist(double_min, double_max);

        // 生成随机浮点数
        double random_double = double_dist(gen);
        rewriter.replace(ctx->getStart(), std::to_string(random_double));
        //  插入空格
        rewriter.insertAfter(ctx->getStart(), " ");
        return antlrcpp::Any();
        
    }

    // 节点访问换指令
    antlrcpp::Any visitTerminal(tree::TerminalNode* node) override {
        // 定义函数指针类型
        using FuncType = std::function<void(Token *,const std::string&)>;

        // 创建一个映射表，将类型映射到对应的函数
        std::unordered_map<int, FuncType> funcMap;
        // 初始化
        funcMap = {
            {WatLexer::EOF,      [this](Token *token,const std::string& text) { rewriter.replace(token, text); }},
            {WatLexer::BINARY,   [this](Token *token,const std::string& text) { rewriter.replace(token, getRandomBinary(text)); }},
            {WatLexer::CONVERT,  [this](Token *token,const std::string& text) { rewriter.replace(token, getRandomConvert(text)); }},
            {WatLexer::CONST,    [this](Token *token,const std::string& text) { rewriter.replace(token, getRandomConst(text)); }},
            {WatLexer::LOAD,     [this](Token *token,const std::string& text) { rewriter.replace(token, getRandomLoad(text)); }},
            {WatLexer::STORE,    [this](Token *token,const std::string& text) { rewriter.replace(token, getRandomStore(text)); }},
            {WatLexer::COMPARE,  [this](Token *token,const std::string& text) { rewriter.replace(token, getRandomCompare(text)); }}
        };

        // 输出终端节点的文本
        std::string text = node->getText();
        // 获取终端节点的类型
        auto type = node->getSymbol()->getType();
        // 获取终端节点的符号
        auto symbol = node->getSymbol();

        // 查找对应的函数并执行
        if(funcMap.count(type) > 0) {
            if(type == WatLexer::EOF){
                funcMap[type](symbol, "\r\n");
            }
            else{
                funcMap[type](symbol, text);
                // 插入空格
                rewriter.insertAfter(symbol, " ");
            }
            
        }
        return antlrcpp::Any();
    }

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
    "i32.trunc_f64_u", "i64.extend_i32_s", "i64.extend_i32_u", "i64.trunc_f32_s",
    "i64.trunc_f32_u", "i64.trunc_f64_s", "i64.trunc_f64_u", "f32.convert_i32_s",
    "f32.convert_i32_u", "f32.convert_i64_s", "f32.convert_i64_u", "f32.demote_f64",
    "f64.convert_i32_s", "f64.convert_i32_u", "f64.convert_i64_s", "f64.convert_i64_u",
    "f64.promote_f32", "i32.reinterpret_f32", "i64.reinterpret_f64", "f32.reinterpret_i32",
    "f64.reinterpret_i64"
};
const std::array<std::string, 4> CustomWatVisitor::constArray = {
    "i32.const", "i64.const", "f32.const", "f64.const"
};
const std::array<std::string, 14> CustomWatVisitor::loadArray = {
    "i32.load", "i64.load", "f32.load", "f64.load",
    "i32.load8_s", "i32.load8_u", "i32.load16_s", "i32.load16_u",
    "i64.load8_s", "i64.load8_u", "i64.load16_s", "i64.load16_u",
    "i64.load32_s", "i64.load32_u"
};
const std::array<std::string, 9> CustomWatVisitor::storeArray = {
    "i32.store", "i64.store", "f32.store", "f64.store",
    "i32.store8", "i32.store16", "i64.store8", "i64.store16",
    "i64.store32"
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
    // 输出重写后的内容
    // std::cout << customVisitor.customoutput("default") << std::endl;
    // rewrite输出到文件，确保每个token之间有空格
    // rewriter转成watparser

    cout << rewriter.getText() << endl;


    return 0;
}
