#include <iostream>
#include <list>
#include <iterator>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <set>

using std::string;

int main()
{
    //task 1
    std::list<string> list;
    std::fstream fin("Input.txt",std::ios::in);
    std::string str="";
    while (!fin.eof()) {
        getline(fin, str);
        std::istringstream temp(str);
        while (!temp.eof()) {
        temp >> str;
        list.push_back(str);
        }

    }
   //task 2
    std::copy(list.begin(), list.end(), std::ostream_iterator<std::string>(std::cout, " "));//вывод всех слов песни в одну строку
    std::cout << "\n";

    //task 3
    std::vector<string> vec;
    std::copy(list.begin(), list.end(), vec.begin());
    std::cout << "\nCheck is copy right:\n";
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<std::string>(std::cout, " "));

    //task 8
    std::cout << "\nCopy_backward:\n";
    std::copy_backward(vec.begin(), vec.end(), std::ostream_iterator<string>(std::cout, " "));


    system("pause");
    return 0;
}