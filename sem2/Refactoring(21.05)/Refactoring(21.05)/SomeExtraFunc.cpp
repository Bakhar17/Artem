#include "SomeExtraFunc.h"
#include <algorithm>
#include <sstream>

std::set<char> SymCount(const char* stroka) {
    std::set<char> sym;
    int i = 0;
    while (stroka[i] != '\0') {
        if (stroka[i] == ' ') {
            i++;
            continue;
        }
        sym.insert(stroka[i]);
        i++;
    }
    return sym;
}
std::vector<std::pair<char, int>> PairACount(const char* stroka, std::set<char>& sym) {

    std::vector<std::pair<char, int>> temp;
    std::for_each(sym.begin(), sym.end(), [&stroka, &temp](char a) {
        int count = 0;
        int k = 0;
        while (stroka[k] != '\0') {
            if (a == stroka[k]) {
                count++;
            }
            k++;
        }
        temp.push_back(std::make_pair(a, count));
        });
    return temp;
}

std::vector<std::pair<int, int>> PairBCount(const char* stroka, std::set<int>& words) {
    std::vector<std::pair<int, int>> temp;

    std::for_each(words.begin(), words.end(), [&stroka, &temp](int word) {
        int count = 0;
        std::stringstream stroka_(stroka);
        while (!stroka_.eof()) {
            std::string tmp;
            stroka_ >> tmp;
            if (tmp.length() == word) count++;
        }
        temp.push_back(std::make_pair(word, count));
        });
    return temp;
}
std::set<int> WordCount(const char* stroka) {
    std::set<int> words;
    std::stringstream str(stroka);
    std::string str1;
    while (!str.eof()) {
        str >> str1;
        if(str1.length()!=0)
        words.insert(str1.length());
    }
    return words;
}
