#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iterator>

int main()
{
    //task 1
    std::ifstream fin("Input.txt");
    std::list<std::string> list;
    if (fin.is_open()) {
        std::copy(std::istream_iterator<std::string>(fin), std::istream_iterator<std::string>(), std::inserter(list, list.end()));
    }
    //task 2
    std::copy(list.begin(), list.end(), std::ostream_iterator<std::string>(std::cout, " "));//вывод всех слов песни в одну строку
    std::cout << "\n";

    //task 3
    std::vector<std::string> vec(list.size());
    std::copy(list.begin(), list.end(), vec.begin());
    std::cout << "\nCheck is copy right:\n";
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<std::string>(std::cout, " "));

    //task 8
    std::cout << "\nReverse:\n";
    std::list<std::string> list_back;
    std::copy(list.begin(), list.end(), std::back_inserter(list_back));
    std::reverse(list_back.begin(), list_back.end());
    std::copy(list_back.begin(), list_back.end(), std::ostream_iterator<std::string>(std::cout, " "));

    //task 5
    std::cout << "\nPut the symbol:";
    char symbol;
    symbol=getchar();
    std::copy_if(list.begin(), list.end(), std::ostream_iterator<std::string>(std::cout, " "), [&symbol](std::string word) {
        return (word[0] == symbol);
        });

    //task 6
    std::cout << "\nPut the symbol:";
    std::cin.ignore();
    symbol=getchar();

    std::remove_if(list.begin(), list.end(), [&symbol](std::string word) {
        return (word[0] == symbol);
        });
    std::copy(list.begin(), list.end(), std::ostream_iterator<std::string>(std::cout, " "));
    
    //task 7
    std::cout << "\nPut the symbol:";
    std::cin.ignore();
    symbol=getchar();
    int count = 0;
    std::for_each(list.begin(), list.end(), [&count, &symbol](std::string word) {
        if (word[0] == symbol) count++;
        });
    std::cout << "Counter of words with " << symbol << ": " << count;

    //task 9
    std::cout << "\nUnique elements: ";
    std::list<std::string> un_list;
    std::unique_copy(list.begin(), list.end(), std::back_inserter(un_list));
    std::copy(un_list.begin(),un_list.end(), std::ostream_iterator<std::string>(std::cout, " "));
    system("pause");
    return 0;

}

