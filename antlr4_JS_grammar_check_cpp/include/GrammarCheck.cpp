#include "GrammarCheck.h"

void CheckDirectory(const std::string_view document_check_path, const std::string_view js_enginee_name) {
    // 检查待拷贝的文件夹是否存在同时检查文件夹内.wat尾缀的文件个数，个数为0报错
    // 检查
    if (std::filesystem::is_directory(document_check_path) &&
        std::filesystem::exists(document_check_path)) {
        std::cout << js_enginee_name << "folder exist" << std::endl;
        int wat_file_num = 0;
        for (auto &p : std::filesystem::directory_iterator(document_check_path)) {
            if (p.path().extension() == ".js") {
                wat_file_num++;
            }
        }
        if (wat_file_num == 0) {
            std::cout << js_enginee_name << "folder doesn't have js file" << std::endl;
            // return 0;
        } else {
            std::cout << js_enginee_name << "js file number: " << wat_file_num << std::endl;
        }
    }
}

void FileCopyAndRename(const std::string_view document_check_path, const std::string_view new_copy_path, const std::string_view js_enginee_name) {
    // 批量进行分析，查看当前语法的问题
    int valid_file_count = 0;
    for (auto &p : std::filesystem::directory_iterator(document_check_path)) {

        if (p.path().extension() == ".js") {
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

void DocumentCreate(const std::string_view input_file_path, const std::string_view output_file_path, const std::string_view suffix) {
    // 创建文件夹
    for (auto &p : std::filesystem::directory_iterator(input_file_path)) {
        std::string file_name = p.path().filename().string();
        // 去除尾缀.js
        file_name = file_name.substr(0, file_name.length() - suffix.length());
        std::string new_file_path = std::string(output_file_path) + "/" + file_name;
        std::filesystem::create_directory(new_file_path);
    }
}

// 检查文件是否为空
bool CheckFileEmpty(const std::string_view file_path) {
    std::filesystem::path file_check(file_path);
    if (std::filesystem::exists(file_check)) {
        if (std::filesystem::file_size(file_check) == 0) {
            fprintf(stdout, "%s is empty.\n", file_path.data());
            // std::cout << "File is empty.\n";
            return true;
        } else {
            // std::cout << "File is not empty.\n";
            fprintf(stdout, "%s is not empty.\n", file_path.data());
            return false;
        }
    } else {
        // std::cout << "File does not exist.\n";
        fprintf(stderr, "%s does not exist.\n", file_path.data());
    }
    return 0;
}

// 删除空的文件
void ClearEmptyFile(const std::string_view file_path) {
    std::filesystem::path file_check(file_path);
    if (std::filesystem::exists(file_check)) {
        if (std::filesystem::file_size(file_check) == 0) {
            std::filesystem::remove(file_check);
            fprintf(stdout, "%s is empty, delete it.\n", file_path.data());
        } else {
            fprintf(stdout, "%s is not empty.\n", file_path.data());
        }
    } else {
        fprintf(stderr, "%s does not exist.\n", file_path.data());
    }
}

// 检查文件夹内包含的文件个数
int CheckFileNum(const std::string_view file_path) {
    int file_num = 0;
    for (auto &p : std::filesystem::directory_iterator(file_path)) {
        file_num++;
    }
    return file_num;
}