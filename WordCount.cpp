#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

// 函数声明
int countCharacters(string filename);
int countWords(string filename);

int main(int argc, char* argv[]) {
    // 检查参数数量
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " [-c | -w] input_file_name" << endl;
        return 1;
    }

    // 获取参数
    string parameter = argv[1];
    string filename = argv[2];

    // 根据参数调用相应的函数
    if (parameter == "-c") {
        int charCount = countCharacters(filename);
        cout << "字符数：" << charCount << endl;
    }
    else if (parameter == "-w") {
        int wordCount = countWords(filename);
        cout << "单词数：" << wordCount << endl;
    }
    else {
        cerr << "Invalid parameter. Please use '-c' for character count or '-w' for word count." << endl;
        return 1;
    }

    return 0;
}

// 统计字符数
int countCharacters(string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Unable to open file: " << filename << endl;
        exit(EXIT_FAILURE);
    }

    int charCount = 0;
    char ch;
    while (file.get(ch)) {
        charCount++;
    }

    file.close();
    return charCount;
}

// 统计单词数
int countWords(string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Unable to open file: " << filename << endl;
        exit(EXIT_FAILURE);
    }

    int wordCount = 0;
    string word;
    while (file >> word) {
        wordCount++;
    }

    file.close();
    return wordCount;
}