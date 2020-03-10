#include <iostream>
extern "C" void _stdcall IntToHex(int, char*);
extern "C" void _stdcall Reverse(char*);
int main()
{
	std::cout << "Put the number: ";
	int n;
	std::cin >> n;
	char* str = new char[8]{ '0','0','0','0','0','0','0','0' };
	IntToHex(n,str );
	Reverse(str);
	int i = 0;
	while (str[i] == '0') {
		++i;
	}
	for (i ; i < 8; i++)
	{
		std::cout << str[i];
	}
	std::cout << "\n";
	delete[] str;
	system("pause");
	return 0;
}