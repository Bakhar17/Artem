#include <iostream>
#include "class.cpp"
int main() {
	//Array b{ 8 };
	//std::cout << b.data << "\n";
	//for (size_t i = 0; i < b.GetSize(); i++)
	//{
	//	b[i] = i + 1;
	//}
	//for (size_t i = 0; i < b.GetSize(); i++)
	//{
	//	std::cout << b[i] << "\t";
	//}
	//b.SetSize(10);
	//std::cout <<"\n"<< b.data<<"\n";
	//for (size_t i = 0; i < b.GetSize(); i++)
	//{
	//	std::cout << b[i] << "\t";
	//}
	//std::cout << "\n" << b.GetSize()<<"\n";
	//b.SetAt(7,6);
	//for (size_t i = 0; i < b.GetSize(); i++)
	//{
	//	std::cout << b[i] << "\t";
	//}
	//std::cout << "\n"<<b.GetSize()<<"\n";
	//std::cout << b.GetUpperBound()<<"\n";
	////b.RemoveAt(25);
	//b.FreeExtra();
	//for (size_t i = 0; i < b.GetSize(); i++)
	//{
	//	std::cout << b[i] << "\t";
	//}
	Array q1(5);
	for (size_t i = 0; i < 5; i++)
	{
		q1[i] = rand() % 10;
		std::cout << q1[i] << "\t";
	}
	Array q2(7);
	std::cout << "\n";
	for (size_t i = 0; i < 7; i++)
	{
		q2[i] = i + 12;
		std::cout << q2[i] << "\t";
	}
	Array sum = q1.Append(q2);
	std::cout << "\n";
	for (size_t i = 0; i < sum.GetSize(); i++)
	{
		std::cout << sum[i] << "\t";
	}
	q1.RemoveAll(); q2.RemoveAll();  sum.RemoveAll();
	//b.RemoveAll();
}