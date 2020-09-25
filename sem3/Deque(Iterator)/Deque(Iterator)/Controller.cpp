#include "Controller.h"
#include "resource.h"
#include <string>
Controller::Controller(View* view, Deque<Integer>* model) :view_(view), model_(model) {}

Controller::~Controller()
{
}

void Controller::Update()
{
	view_->Update();
}

void Controller::PushF()
{
	HWND temp = view_->GetHwnd();
    wchar_t txt[100];
    GetDlgItemText(temp, IDC_EDIT2, txt, sizeof(txt));
    SetDlgItemText(temp, IDC_EDIT2, L"");
    Integer data(_wtoi(txt));
    model_->PushFront(data);
    view_->Update();
}

void Controller::PushB()
{
    HWND temp = view_->GetHwnd();
    wchar_t txt[100];
    GetDlgItemText(temp, IDC_EDIT2, txt, sizeof(txt));
    SetDlgItemText(temp, IDC_EDIT2, L"");
    Integer data(_wtoi(txt));
    model_->PushBack(data);
    view_->Update();
}

void Controller::PopF()
{
    model_->PopFront();
    view_->Update();
}

void Controller::PopB()
{
    model_->PopBack();
    view_->Update();
}
