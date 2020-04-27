#include <iostream>
extern "C" int _stdcall FindSize(const char*,int size);
extern "C" int _stdcall FindPos(const char*,int , const char*,int);

int main()
{
    ////task 1
    //std::cout << "Put the string: ";
    char string[50];
    //std::cin.getline(string, 50);
    int sizer = strlen(string);
    //std::cout << string;
    //int num = FindSize(string,sizer);
    //std::cout << "\n" << num;
    //task 2
    std::cout << "\nPut the string: ";
    std::cin.getline(string, 50);
    sizer = strlen(string);
    std::cout << "Put the word: ";
    char word[20];
    std::cin.getline(word,20);
    int ssizer = strlen(word);
    int pos = FindPos(string, sizer, word, ssizer);
    std::cout << pos;
    std::cout << "\n" << string[pos];

    system("pause");
    return 0;
}