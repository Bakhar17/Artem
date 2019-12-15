#pragma once
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
void Er(string word, vector<string>& lines) {
	for (size_t i = 0; i < size(lines); i++)
	{
		auto pos = lines[i].find(word);
		if (pos < lines[i].size() && pos >= 0)
			lines[i].erase(pos, size(word)+1);
	}
}

void SortR(vector<string>& Stroki) {
	sort(begin(Stroki), end(Stroki),
		[](const string& l, const string& r) {
			return lexicographical_compare(
				begin(l), end(l),
				begin(r), end(r),
				[](char cl, char cr) { return tolower(cl) < tolower(cr); }
			);
		}
	);
}
int Sum(int x, int y) {
	return x + y + 1;
}
int Pos() {
	return 0;
}