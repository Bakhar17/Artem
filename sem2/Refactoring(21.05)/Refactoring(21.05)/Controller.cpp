#include "Controller.h"

Controller::~Controller()
{
}

Controller::Controller(Model* model, View* view) :model_(model), view_(view){}

void Controller::ChangeData() {
	this->model_->DownloadData();
	this->view_->SetModel(model_);
}

HWND Controller::UploadL() {
	return this->view_->ViewL();
}
void Controller::UploadG(HDC hdc,int xSize,int ySize,char* stroka) {
	this->view_->ViewH(hdc,xSize,ySize,stroka);
	this->view_->ViewG(hdc, xSize, ySize, stroka);
}