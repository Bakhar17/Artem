#pragma once

#include "Model.h"

class View
{
public:
	View();
	~View();
	View(HWND, HINSTANCE,Model*);
	void SetModel(Model*);
	void SetHwnd(const HWND&);
	const HWND GetHwnd()const ;
	const HINSTANCE GetHinst()const;
	const Model GetModel()const;
	HWND ViewL();
	void ViewG(HDC,int,int,char*);
	void ViewH(HDC, int, int, char*);
private:
	Model* model_;
	HWND hwnd_ = NULL;
	HINSTANCE hInst_ = NULL;
};

