#include "List.h"
#include "Stack.h"
#include "Queue.h"

int main()
{
	//List<int> list;
	//list.push_back(2);
	//list.push_back(100);
	//list.push_front(4);
	//list.insert(5, 2);
	//cout << list;
	//cout<<list.find(3);
	Stack<int> st;
	st.Push(5);
	st.Push(8);
	st.Push(9);
	cout << st.Top();
	st.Pop();
	cout << st.empty();
	cout << st.Top();
	Queue<int> qw;
	qw.Push(5);
	qw.Push(3);
	qw.Push(2);
	cout << qw.back();
	cout << qw.front();
	qw.Pop();
	cout<<qw.front();
	return 0;
}
