#pragma once
#include <set>
#include <vector>

std::set<char> SymCount(const char*);
std::set<int> WordCount(const char*);
std::vector<std::pair<char, int>> PairACount(const char* stroka, std::set<char>& sym);
std::vector<std::pair<int, int>> PairBCount(const char* stroka, std::set<int>& words);