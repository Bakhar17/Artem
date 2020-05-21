#include <iostream>
#include <Windows.h>
#include <string>
#include <cstdlib>
using namespace std;

void SetColor(int text, int bg) {
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}

int main() {
    SetColor(60,4);
    std::string temp;
    temp = "Fuck";
    std::cout << temp;
    SetColor(14, 3);
    std::cout << temp;
    return 0;
}