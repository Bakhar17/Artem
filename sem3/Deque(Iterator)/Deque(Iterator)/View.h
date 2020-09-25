#ifndef VIEW_H_
#define VIEW_H_
#include "Deque.h"
#include "Integer.h"
#include <windows.h>

class View
{
public:
	View()=delete;
	View(const HWND&, Deque<Integer>*);
	~View();
	void SetModel(Deque<Integer>*);
	void SetHwnd(const HWND&);
	const HWND GetHwnd()const;
	Deque<Integer>* GetModel()const;
	void Update();
private:
	Deque<Integer>* model_=nullptr;
	HWND hwnd_ = NULL;
};

#endif // !VEIW_H_
