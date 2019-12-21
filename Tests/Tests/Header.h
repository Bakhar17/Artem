#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <string>
using namespace std;
void Er(const string word, string& stroka) {
	size_t pos = stroka.find(word);
	while (pos != string::npos) {
		stroka.erase(pos,word.size() + 1);
		pos = stroka.find(word);
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
