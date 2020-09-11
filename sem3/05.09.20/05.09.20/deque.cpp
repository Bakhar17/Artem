#include "Iterator.h"
#include <iostream>


int main() {
	Deque<int> emptest{5,4,9,5};
	DequeIterator<int> iter(&emptest);
	iter.First();
	int x = iter.CurrentItem();
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
	DequeIterator<int> iter2(&test2);
	iter2.First();
	while (!iter2.IsDone()) {
		std::cout << iter2.CurrentItem();
		iter2.Next();
	}
	std::cout << "\n";
	Deque<int> test3(test2);
	DequeIterator<int> iter3(&test3);
	while (!iter3.IsDone()) {
		std::cout << iter3.CurrentItem();
		iter3.Next();
	}
	//std::cout << (emptest == test2);
	return 0;
}