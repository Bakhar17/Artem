#include "Route.h"
#include <list>
#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <vector>
int main()
{
    std::cout << "Hello World!\n";
    Route test(std::make_pair(5, "Kamenka"), "Bakhar", 3);
    std::cout << ToString(test);
    std::list<Route> routes;
    std::fstream fin("Routes.txt");
    if (fin.is_open()) {
        std::string line;
        std::vector<std::string> init_route;
        while (!fin.eof()) {
                std::copy(std::istream_iterator<std::string>(fin), std::istream_iterator<std::string>(), std::back_inserter(init_route));
        }
        for (int i = 0; i < init_route.size(); i=i+4)
        {
            test.SetBus(std::make_pair(stoi(init_route[i + 0]), init_route[i + 1]));
            test.SetSurname(init_route[i + 2]);
            test.SetRoute(stoi(init_route[i + 3]));
            routes.push_back(test);
        }
    }
    std::for_each(routes.begin(), routes.end(), [](Route route) {
        std::cout << ToString(route);
        });
    system("pause");
    return 0;
}

