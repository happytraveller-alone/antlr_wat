#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <random>

#include "WatLexer.h"
#include "WatParser.h"
#include "WatParserBaseVisitor.h"
#include "WatParserVisitor.h"
#include "antlr4-runtime.h"
#include "TokenStreamRewriter.h"

using namespace antlr4;
using namespace std;

class OutputWatVisitor : public WatParserBaseVisitor {
private:
    // 文件输出流
    std::ofstream outputfile;
public:
    OutputWatVisitor(std::string filename) :  outputfile(filename) {
        if(!outputfile.is_open()) {
            std::cerr << "open file failed" << std::endl;
            exit(1);
        }
        else{
            std::cout << "open file success" << std::endl;
        }

    }
    ~OutputWatVisitor() {
        std::cout << "close file" << std::endl;
        outputfile.close();
    
    }
    antlrcpp::Any visitTerminal(tree::TerminalNode* node) override {
        // 输出终端节点的文本
        std::cout << node->getText() << " ";
        outputfile << node->getText() << " ";
        // 如果是<EOF>则换行
        if (node->getSymbol()->getType() == WatLexer::EOF) {
            std::cout << std::endl;
            outputfile << std::endl;
        }
        return antlrcpp::Any();
    }
};

class CustomWatVisitor : public WatParserBaseVisitor {
private:
    TokenStreamRewriter &rewriter;
    std::ofstream outputfile;
    // 随机数生成器
    mt19937 gen;
    // 均匀分布
    uniform_int_distribution<> dist;
public:
    CustomWatVisitor(TokenStreamRewriter &rewriter,std::string filename) : rewriter(rewriter) , outputfile(filename) {
        if(!outputfile.is_open()) {
            std::cerr << "open file failed" << std::endl;
            exit(1);
        }
        else{
            std::cout << "open file success" << std::endl;
        }
        std::random_device rd;
        gen = std::mt19937(rd());
        dist = std::uniform_int_distribution<>(0, 2);
    }

    ~CustomWatVisitor() {
        std::cout << "close file" << std::endl;
        outputfile.close();
    
    }

    // 进行随机替换
    std::string getRandomConstReplacement(int start, int end) {
        dist = std::uniform_int_distribution<>(start, end);
        int random = dist(gen);
        // cout << "random: " << random << endl;
        switch (random) {
            case 0: return "i32.const"; break;
            case 1: return "i64.const"; break;
            case 2: return "f64.const"; break;
            case 3: return "f32.const"; break;
            default: return "f64.const"; break;  // Fallback, should not happen
        }
    }

    // 换BINARY指令
    std::string getRandomBinary(std::string text)
    {
        dist = std::uniform_int_distribution<>(0, 43);
        std::string result = text;
        while (result == text)
        {
            int random = dist(gen);
            switch (random)
            {
            case 0:
                result = "i32.add";
                break;
            case 1:
                result = "i32.sub";
                break;
            case 2:
                result = "i32.mul";
                break;
            case 3:
                result = "i32.div_s";
                break;
            case 4:
                result = "i32.div_u";
                break;
            case 5:
                result = "i32.rem_s";
                break;
            case 6:
                result = "i32.rem_u";
                break;
            case 7:
                result = "i32.and";
                break;
            case 8:
                result = "i32.or";
                break;
            case 9:
                result = "i32.xor";
                break;
            case 10:
                result = "i32.shl";
                break;
            case 11:
                result = "i32.shr_s";
                break;
            case 12:
                result = "i32.shr_u";
                break;
            case 13:
                result = "i32.rotl";
                break;
            case 14:
                result = "i32.rotr";
                break;
            case 15:
                result = "i64.add";
                break;
            case 16:
                result = "i64.sub";
                break;
            case 17:
                result = "i64.mul";
                break;
            case 18:
                result = "i64.div_s";
                break;
            case 19:
                result = "i64.div_u";
                break;
            case 20:
                result = "i64.rem_s";
                break;
            case 21:
                result = "i64.rem_u";
                break;
            case 22:
                result = "i64.and";
                break;
            case 23:
                result = "i64.or";
                break;
            case 24:
                result = "i64.xor";
                break;
            case 25:
                result = "i64.shl";
                break;
            case 26:
                result = "i64.shr_s";
                break;
            case 27:
                result = "i64.shr_u";
                break;
            case 28:
                result = "i64.rotl";
                break;
            case 29:
                result = "i64.rotr";
                break;
            case 30:
                result = "f32.add";
                break;
            case 31:
                result = "f32.sub";
                break;
            case 32:
                result = "f32.mul";
                break;
            case 33:
                result = "f32.div";
                break;
            case 34:
                result = "f32.min";
                break;
            case 35:
                result = "f32.max";
                break;
            case 36:
                result = "f32.copysign";
                break;
            case 37:
                result = "f64.add";
                break;
            case 38:
                result = "f64.sub";
                break;
            case 39:
                result = "f64.mul";
                break;
            case 40:
                result = "f64.div";
                break;
            case 41:
                result = "f64.min";
                break;
            case 42:
                result = "f64.max";
                break;
            case 43:
                result = "f64.copysign";
                break;
            default:
                result = "i32.add";
                break; // Fallback, should not happen
            }
        }
        return result;
    }

    // 换CONVERT指令
    std::string getRandomConvert(std::string text){
        dist = std::uniform_int_distribution<>(0, 24);
        std::string result = text;
        while(result == text){int random = dist(gen);
        // cout << "random: " << random << endl;
        switch (random) {
            case 0: result = "i32.wrap_i64"; break;
            case 1: result = "i32.trunc_f32_s"; break;
            case 2: result = "i32.trunc_f32_u"; break;
            case 3: result = "i32.trunc_f64_s"; break;
            case 4: result = "i32.trunc_f64_u"; break;
            case 5: result = "i64.extend_i32_s"; break;
            case 6: result = "i64.extend_i32_u"; break;
            case 7: result = "i64.trunc_f32_s"; break;
            case 8: result = "i64.trunc_f32_u"; break;
            case 9: result = "i64.trunc_f64_s"; break;
            case 10: result = "i64.trunc_f64_u"; break;
            case 11: result = "f32.convert_i32_s"; break;
            case 12: result = "f32.convert_i32_u"; break;
            case 13: result = "f32.convert_i64_s"; break;
            case 14: result = "f32.convert_i64_u"; break;
            case 15: result = "f32.demote_f64"; break;
            case 16: result = "f64.convert_i32_s"; break;
            case 17: result = "f64.convert_i32_u"; break;
            case 18: result = "f64.convert_i64_s"; break;
            case 19: result = "f64.convert_i64_u"; break;
            case 20: result = "f64.promote_f32"; break;
            case 21: result = "i32.reinterpret_f32"; break;
            case 22: result = "i64.reinterpret_f64"; break;
            case 23: result = "f32.reinterpret_i32"; break;
            case 24: result = "f64.reinterpret_i64"; break;
            default: result = "i32.wrap_i64"; break;  // Fallback, should not happen
        }}
        return result;
    }
    
    // 换CONST指令
    std::string getRandomConst(std::string text){
        dist = std::uniform_int_distribution<>(0, 3);
        std::string result = text;
        while(result == text){int random = dist(gen);
        // cout << "random: " << random << endl;
        switch (random) {
            case 0: result = "i32.const"; break;
            case 1: result = "i64.const"; break;
            case 2: result = "f32.const"; break;
            case 3: result = "f64.const"; break;
            default: result = "i32.const"; break;  // Fallback, should not happen
        }}
        return result;
    }
    
    // 换LOAD指令
    std::string getRandomLoad(std::string text){
        dist = std::uniform_int_distribution<>(0, 5);
        std::string result = text;
        while(result == text){int random = dist(gen);
        // cout << "random: " << random << endl;
        switch (random) {
            case 0: result = "i32.load"; break;
            case 1: result = "i64.load"; break;
            case 2: result = "f32.load"; break;
            case 3: result = "f64.load"; break;
            case 4: result = "i32.load8_s"; break;
            case 5: result = "i32.load8_u"; break;
            case 6: result = "i32.load16_s"; break;
            case 7: result = "i32.load16_u"; break;
            case 8: result = "i64.load8_s"; break;
            case 9: result = "i64.load8_u"; break;
            case 10: result = "i64.load16_s"; break;
            case 11: result = "i64.load16_u"; break;
            case 12: result = "i64.load32_s"; break;
            case 13: result = "i64.load32_u"; break;
            default: result = "i32.load"; break;  // Fallback, should not happen
        }}
        return result;
    }
    
    // 换STORE指令
    std::string getRandomStore(std::string text){
        dist = std::uniform_int_distribution<>(0, 5);
        std::string result = text;
        while(result == text){int random = dist(gen);
        // cout << "random: " << random << endl;
        switch (random) {
            case 0: result = "i32.store"; break;
            case 1: result = "i64.store"; break;
            case 2: result = "f32.store"; break;
            case 3: result = "f64.store"; break;
            case 4: result = "i32.store8"; break;
            case 5: result = "i32.store16"; break;
            case 6: result = "i64.store8"; break;
            case 7: result = "i64.store16"; break;
            case 8: result = "i64.store32"; break;
            default: result = "i32.store"; break;  // Fallback, should not happen
        }}
        return result;
    }
    
    // 换COMPARE指令
    std::string getRandomCompare(std::string text){
        dist = std::uniform_int_distribution<>(0, 11);
        std::string result = text;
        while(result == text){int random = dist(gen);
        // cout << "random: " << random << endl;
        switch (random) {
            case 0: result = "i32.eq"; break;
            case 1: result = "i32.ne"; break;
            case 2: result = "i32.lt_s"; break;
            case 3: result = "i32.lt_u"; break;
            case 4: result = "i32.gt_s"; break;
            case 5: result = "i32.gt_u"; break;
            case 6: result = "i32.le_s"; break;
            case 7: result = "i32.le_u"; break;
            case 8: result = "i32.ge_s"; break;
            case 9: result = "i32.ge_u"; break;
            case 10: result = "i64.eq"; break;
            case 11: result = "i64.ne"; break;
            case 12: result = "i64.lt_s"; break;
            case 13: result = "i64.lt_u"; break;
            case 14: result = "i64.gt_s"; break;
            case 15: result = "i64.gt_u"; break;
            case 16: result = "i64.le_s"; break;
            case 17: result = "i64.le_u"; break;
            case 18: result = "i64.ge_s"; break;
            case 19: result = "i64.ge_u"; break;
            case 20: result = "f32.eq"; break;
            case 21: result = "f32.ne"; break;
            case 22: result = "f32.lt"; break;
            case 23: result = "f32.gt"; break;
            case 24: result = "f32.le"; break;
            case 25: result = "f32.ge"; break;
            case 26: result = "f64.eq"; break;
            case 27: result = "f64.ne"; break;
            case 28: result = "f64.lt"; break;
            case 29: result = "f64.gt"; break;
            case 30: result = "f64.le"; break;
            case 31: result = "f64.ge"; break;
            default: result = "i32.eq"; break;  // Fallback, should not happen
        }}
        return result;
    }
    
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


    antlrcpp::Any visitTerminal(tree::TerminalNode* node) override {
        // 输出终端节点的文本
        std::string text = node->getText();
        // 获取终端节点的类型
        auto type = node->getSymbol()->getType();
        // 如果是<EOF>则换行
        if (type == WatLexer::EOF) {
            rewriter.replace(node->getSymbol(), "\r\n");
            return antlrcpp::Any();
        }
        
        // 替换
        switch(type){
            case WatLexer::BINARY:{
                rewriter.replace(node->getSymbol(), getRandomBinary(text));
                break;
            }
            case WatLexer::CONVERT:{
                rewriter.replace(node->getSymbol(), getRandomConvert(text));
                break;
            }
            case WatLexer::CONST:{
                rewriter.replace(node->getSymbol(), getRandomConst(text));
                break;
            }
            case WatLexer::LOAD:{
                rewriter.replace(node->getSymbol(), getRandomLoad(text));
                break;
            }
            case WatLexer::STORE:{
                rewriter.replace(node->getSymbol(), getRandomStore(text));
                break;
            }
            case WatLexer::COMPARE:{
                rewriter.replace(node->getSymbol(), getRandomCompare(text));
                break;
            }
        }
        
        //  插入空格
        rewriter.insertAfter(node->getSymbol(), " ");
        
        return antlrcpp::Any();
    }

};

int main() {
    // Create an input stream from the file
    ifstream input("../test_file/test1.wat");
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
    std::cout << std::endl << "custom outputfile: " << std::endl;
    // CustomWatVisitor visitor(); 
    OutputWatVisitor visitor("test2_output.txt");
    // 使用Visitor遍历AST并输出原始内容
    visitor.visit(tree);
    visitor.~OutputWatVisitor();
    // 使用命令对输出文件进行整理
    // 删除文件的<EOF>
    system("sed -i 's/<EOF>//g' test2_output.txt");
    // wat-desugar进行格式化
    system("wat-desugar test2_output.txt --enable-all --output=test2_output.wat");


    // 设置Rewriter
    TokenStreamRewriter rewriter(&tokens);
    // 输出重写后的内容
    std::cout << std::endl << "rewriter output: " << std::endl;
    // 使用Visitor遍历AST并输出重写后的内容
    CustomWatVisitor customVisitor(rewriter,"test2_rewrite_output.txt");
    customVisitor.visit(tree);
    // 输出重写后的内容
    // std::cout << customVisitor.customoutput("default") << std::endl;
    // rewrite输出到文件，确保每个token之间有空格
    // rewriter转成watparser

    cout << rewriter.getText() << endl;


    return 0;
}
