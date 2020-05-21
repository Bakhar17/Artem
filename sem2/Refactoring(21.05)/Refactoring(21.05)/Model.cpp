#include "Model.h"


Model::Model()
{
}
Model::Model(const vector<string>&data):data_(data) {}

Model::~Model()
{
}

void Model::SetData(const vector<string>& data) {
	this->data_ = data;
}
const vector<string> Model::GetData()const {
	return this->data_;
}
void Model::DownloadData() {
    
    OPENFILENAME ofn;
    CHAR szFile[260];
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = NULL;
    ofn.lpstrFile = szFile;
    ofn.lpstrFile[0] = '\0';
    ofn.nMaxFile = sizeof(szFile);
    ofn.lpstrFilter = "All\0*.*\0Text\0*.TXT\0";
    ofn.nFilterIndex = 1;
    ofn.lpstrFileTitle = NULL;
    ofn.nMaxFileTitle = 0;
    ofn.lpstrInitialDir = NULL;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
    if (GetOpenFileName(&ofn) == TRUE) {
        std::ifstream fin(ofn.lpstrFile);
        if (fin.is_open()) {
            this->data_.clear();
            std::string temp;
            while (!fin.eof()) {
                getline(fin, temp);
                this->data_.push_back(temp);
            }
        }
    }
}
bool Model::IsValid()const {
    return this->data_.size();
}