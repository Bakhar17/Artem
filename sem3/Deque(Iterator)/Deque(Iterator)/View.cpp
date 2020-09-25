#include "View.h"
#include "resource.h"
#include <string>
#include "Iterator.h"
View::View(const HWND& hdlg, Deque<Integer>* ptr):hwnd_(hdlg),model_(ptr){}

View::~View()
{
}

void View::SetModel(Deque<Integer>* ptr)
{
	model_ = ptr;
}

void View::SetHwnd(const HWND& ptr)
{
	hwnd_ = ptr;
}

const HWND View::GetHwnd() const
{
	return hwnd_;
}

Deque<Integer>* View::GetModel() const
{
	return model_;
}

void View::Update()
{
	SetDlgItemText(hwnd_,IDC_EDIT1, L"");
	std::wstring text;
	DequeIterator<Integer>* iter =model_->CreateIterator();
	IntegerVisitor sum;
	for (iter->First(); !iter->IsDone(); iter->Next()) 
	{
		iter->CurrentItem().Accept(sum);
		text += std::to_wstring(iter->CurrentItem().GetInt()) + L" ";
	}
	SetDlgItemText(hwnd_, IDC_EDIT1, LPCWSTR(text.c_str()));
	text = std::to_wstring(sum.GetSum());
	SetDlgItemText(hwnd_, IDC_EDIT3, LPCWSTR(text.c_str()));
}
