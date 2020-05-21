#pragma once
#include "View.h"

class Controller
{
public:
	Controller(Model*, View*);
	void ChangeData();
	HWND UploadL();
	void UploadG(HDC, int, int, char*);
	~Controller();

private:
	Model* model_;
	View* view_;
};



