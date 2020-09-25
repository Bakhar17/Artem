#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "Deque.h"
#include "Integer.h"
#include "View.h"

class Controller
{
public:
	Controller() = delete;
	Controller(View*,Deque<Integer>*);
	~Controller();
	void Update();
	void PushF();
	void PushB();
	void PopF();
	void PopB();

private:
	Deque<Integer>* model_=nullptr;
	View* view_=nullptr;
};




#endif // !CONTROLLER_H_
