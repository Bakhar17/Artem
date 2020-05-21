#include "View.h"
#include "SomeExtraFunc.h"

View::View()
{
}

View::~View()
{
}

View::View(HWND hwnd,HINSTANCE hInst,Model* model):hwnd_(hwnd),hInst_(hInst),model_(model) {}


void View::SetModel(Model* model) {
	this->model_ = model;
}

const Model View::GetModel()const {
	return *this->model_;
}


const HWND View::GetHwnd() const {
	return this->hwnd_;
}


const HINSTANCE View::GetHinst()const {
	return this->hInst_;
}


void View::SetHwnd(const HWND& hwnd) {
	this->hwnd_ = hwnd;
}


HWND View::ViewL(){
	HWND hListBox=NULL;
	RECT rect;
	GetWindowRect(this->GetHwnd(), &rect);
	if (this->GetModel().IsValid()) {
	hListBox = CreateWindow("listbox", NULL,
		WS_CHILD | WS_VISIBLE | LBS_NOTIFY | WS_BORDER | WS_VSCROLL , 10, 10, 350,100, this->GetHwnd(), NULL, this->GetHinst(), NULL);
	const vector<string> temp = this->GetModel().GetData();
	for (size_t i = 0; i < temp.size(); i++)
	{
		SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)temp[i].c_str());
	}
	}
	return hListBox;
}


void View::ViewG(HDC hdc, int xSize, int ySize, char* stroka){
	std::set<char> sym = SymCount(stroka);
	std::vector<std::pair<char, int>> char_pair = PairACount(stroka, sym);
	RECT rect;
	//установка удобного центра
	SetMapMode(hdc, MM_ANISOTROPIC);
	SetWindowExtEx(hdc, xSize, ySize, NULL);
	SetViewportExtEx(hdc, xSize, -ySize, NULL);
	SetViewportOrgEx(hdc, 0, ySize, NULL);
	//конец установки удобного центра 
	HBRUSH hBrush;
	HPEN hPen = CreatePen(PS_SOLID, 4, RGB(0, 0, 0));
	SelectObject(hdc, hPen);
	hBrush = CreateSolidBrush(RGB(253, 245, 230));
	int sum = 0;

	for (size_t i = 0; i < char_pair.size(); i++)
	{
		std::string buf;
		rect.left = 1;
		rect.top = (i + 1) * 3 * ySize / (4 * char_pair.size());
		rect.right = char_pair[i].second * xSize / 20;
		rect.bottom = i * 3 * ySize / (4 * char_pair.size());
		Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);

		FillRect(hdc, &rect, hBrush);
		buf += char_pair[i].first;
		buf += ", ";
		buf += std::to_string(char_pair[i].second);
		SetBkColor(hdc, RGB(253, 245, 230));
		TextOut(hdc, char_pair[i].second * xSize / 40, (i + 1) * 3 * ySize / (8 * char_pair.size()) + (i) * 3 * ySize / (8 * char_pair.size())+3, buf.c_str(), buf.size());
	}
}
void View::ViewH(HDC hdc, int xSize, int ySize, char*stroka ){
	std::set<int> words = WordCount(stroka);
	std::vector<std::pair<int, int>> words_pair = PairBCount(stroka, words);
	RECT rect;
	HBRUSH hBrush;
	//установка удобного центра
	SetMapMode(hdc, MM_ANISOTROPIC);
	SetWindowExtEx(hdc, xSize, ySize, NULL);
	SetViewportExtEx(hdc, xSize, -ySize, NULL);
	SetViewportOrgEx(hdc, xSize / 2, ySize, NULL);
	//конец установки удобного центра 
	HPEN hPen = CreatePen(PS_SOLID, 4, RGB(0, 0, 0));
	SelectObject(hdc, hPen);
	hBrush = CreateSolidBrush(RGB(253, 245, 230));
	for (size_t i = 0; i < words_pair.size(); i++)
	{
		std::string buf;
		rect.left = i * 3 * ySize / (4 * words_pair.size());
		rect.top = words_pair[i].second * xSize / 8; 
		rect.right = (i + 1) * 3 * ySize / (4 * words_pair.size());
		rect.bottom = 0;
		Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);

		FillRect(hdc, &rect, hBrush);
		buf += std::to_string(words_pair[i].first);
		buf += " symbols, ";
		buf += std::to_string(words_pair[i].second);
		SetBkColor(hdc, RGB(253, 245, 230));
		TextOut(hdc, i * 3 * ySize / (4 * words_pair.size()), words_pair[i].second * xSize / 8 +20, buf.c_str(), buf.size());
	}
}