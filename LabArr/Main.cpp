#include <iostream>
#include "class.cpp"
int main() {
	Array b{ 8 };
	for (size_t i = 0; i < b.GetSize(); i++)
	{
		b[i] = i + 1;
	}
	for (size_t i = 0; i < b.GetSize(); i++)
	{
		std::cout << b[i] << "\t";
	}
	std::cout<<"\n"<<b.IsEmpty();
	b.SetSize(9);
	std::cout << "\n" << b.GetSize()<<"\n";
	b.At(12, 15);
	std::cout<<b[7];
	b.RemoveAll();
}