#include "Iterator.h"
#include <iostream>


int main() {
	{
	Deque<int> emptest{5,4,9,5};

	DequeIterator<int> iter(&emptest);
	iter.First();
	int x = iter.CurrentItem();
	}
	Deque<int> test2;
	test2.PushBack(5);
	test2.PushBack(2);
	test2.PushBack(1);
	test2.PushBack(2);
	test2.PushBack(8);
	test2.PopFront();
	std::cout << test2.Front();
	std::cout << test2.Back();
	test2.PopBack();
	std::cout << test2.Back();
	DequeIterator<int> iter(&test2);
	iter.First();
	while (!iter.IsDone()) {
		std::cout << iter.CurrentItem();
		iter.Next();
	}
	return 0;
}