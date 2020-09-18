#include <iostream>
#include "Iterator.h"
#include "Deque.h"

Array<int> CheckMove(int a) {
	Array<int> move_test(a);
	return move_test;
}
Deque<int> CheckMode(int a) {
	Deque<int> move_test;
	move_test.PushBack(a);
	return move_test;
}

int main() {
	{
	Array<int> test{ 1,5,2,5 };
	Array<int> test2(test);
	std::cout << (test == test2);
	test2 = test;
	std::cout << test2[2];
	test=CheckMove(13);


	Array<int> testPush{ 1,3,5,2};
	testPush.PushBack(4);
	std::cout << testPush.Back();
	std::cout << testPush.Size();
	testPush.PushFront(2);
	std::cout << testPush.Front();
	std::cout << testPush.Size();
	testPush.PopBack();
	std::cout << testPush.Back();
	std::cout << testPush.Size();
	testPush.PopFront();
	std::cout << testPush.Front();
	std::cout << testPush.Size();
	std::cout << "\n\n\n";
	}//also checked destructors


	Deque<int> test{1,2,3,4};
	std::cout << test.Back();
	std::cout << test.Front();
	std::cout << test.Size();
	test.PopBack();
	test.PopFront();
	std::cout << test.Back();
	std::cout << test.Front();
	std::cout << test.Size();
	test = CheckMode(13);


	Deque<int> test1;
	std::cout << "\n\n";
	std::cout << (test == test1);
	std::cout <<( test != test1);
	test = test1;
	std::cout << (test == test1);
	std::cout << (test != test1);
	std::cout << "\n\n\n";


	Deque<int> test2{ 1,2,3,4 };
	DequeIterator<int> iter(&test2);
	for (iter.First(); !iter.IsDone(); iter.Next())
	{
		std::cout << iter.CurrentItem() << " ";
	}
	system("pause");
	return 0;
}