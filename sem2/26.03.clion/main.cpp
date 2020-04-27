#include <iostream>
#include <list>
#include <iterator>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>

int main()
{
    std::list<std::string> list;
    std::ifstream fin("Input.txt");

    if(fin.is_open()){
        while(!fin.eof()){
            std::string string;
            getline(fin,string);
            std::stringstream temp(string);
            std::copy(std::istream_iterator<std::string>(temp),std::istream_iterator<std::string>(),list.begin());
        }
        std::copy(list.begin(),list.end(),std::ostream_iterator<std::string>(std::cout,"\n"));
    }
    std::cout << "Hello World!\n";
    system("pause");
    return 0;
}
