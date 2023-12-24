#include <iostream>
#include <fstream>

int main() {
    // 打开文件以写入
    std::ofstream outputFile("output.txt");

    // 检查文件是否成功打开
    if (!outputFile.is_open()) {
        std::cerr << "Error: Failed to open output file." << std::endl;
        return 1;
    }

    // 写入文本到文件
    outputFile << "Hello, World!" << std::endl;
    outputFile << "This is a sample text." << std::endl;

    // 关闭文件
    outputFile.close();

    std::cout << "File write completed." << std::endl;

    return 0;
}
