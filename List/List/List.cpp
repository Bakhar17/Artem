#include "container.h"
#include "container.cpp"
//#include "Stack.h"
//#include "Queue.h"

int main()
{//тесты исходных функций
	{BiDirectionalList<int> test;
	test.PushBack(5);
	test.PushFront(4);
	test.PushBack(5);
	test.PushFront(4);
	test.PushBack(5);
	test.PushFront(4);
	test.PopBack();
	BiDirectionalList<int> test2 { 2,5,6 };
	cout << test.Back()->value;
	cout << test.Size();
	cout << test<<"\n";//перегружено для проверки правиьно введенного содержимого
	vector<int> res;
	res = test.FindAll(5);
	for (size_t i = 0; i < size(res); i++)
	{
		cout << res[i] << " ";
	}
	std::cout << "\n" << test2;
	test = test2;
	test = test;
	cout << "\n" << test;
	cout << "\n" << (test==test2);
	}
	return 0;
}
