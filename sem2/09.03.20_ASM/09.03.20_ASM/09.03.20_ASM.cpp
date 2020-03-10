#include <iostream>
extern "C" void _stdcall Calc(int number, char* res);
int main()
{
	std::cout << "Put the number: ";
	int n;
	std::cin >> n;
	char str[8] = {0};
	Calc(25, str);
	for (int i = 0; i < 8; i++)
	{
		std::cout << int(str[i]);
	}
    std::cout << "Hello World!\n";
}