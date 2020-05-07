#include <windows.h>
#include "resource.h"
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

std::vector<int> alter_answer = { 1,3,2,3 };
int atnum = 0;

int CheckAns(const std::vector<int>&);
int GetAnswer(HWND, int); //int — RadioButton code
INT_PTR CALLBACK DLG(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow)
{
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DLG);
	return 0;
}


INT_PTR CALLBACK DLG(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	std::ifstream fin("Tasks.txt");
	std::string text;
	static std::vector<int> user_answer = { 0,0,0,0 };
	switch (message)
	{
	case WM_CLOSE:
		EndDialog(hDlg,0);
		return (INT_PTR)TRUE;
	case WM_INITDIALOG:
		ShowWindow((GetDlgItem(hDlg, IDC_BACK)), SW_HIDE);
		ShowWindow((GetDlgItem(hDlg, IDC_NEXT)), SW_HIDE);
		SetDlgItemText(hDlg, IDC_STATIC_MY1, "Нажмите кнопку \"ОК\" для начала теста.");
		for (int i = 0; i < 3; i++)
		{
			ShowWindow(GetDlgItem(hDlg, IDC_RADIO1 + i), SW_HIDE);
		}
	break;

	case WM_COMMAND: {
		switch (LOWORD(wParam)) {
		case IDOK:
			ShowWindow((GetDlgItem(hDlg, IDOK)), SW_HIDE);
			ShowWindow((GetDlgItem(hDlg, IDC_NEXT)), SW_SHOW);
			getline(fin, text);
			SetDlgItemText(hDlg, IDC_STATIC_MY1, text.c_str());
			for (int i = 0; i < 3; i++)
			{
				ShowWindow(GetDlgItem(hDlg, IDC_RADIO1 + i), SW_SHOW);
			}
			break;
		case IDC_NEXT:
		{
			atnum++;
			ShowWindow((GetDlgItem(hDlg, IDC_BACK)), SW_SHOW);
			getline(fin, text);
			int k;
			for (int i = 0; i < atnum; i++)
			{
				if (fin.eof()) {
					k = GetAnswer(hDlg, IDC_RADIO1);
					SendDlgItemMessage(hDlg, IDC_RADIO1 + i, BM_SETCHECK, 0, 0);
					user_answer[atnum - 1] = k;
					k = CheckAns(user_answer);//number of right answers
					char buffer[100];
					sprintf_s(buffer, "Вы ответили на все вопросы!\nВерно %i/%i", k, alter_answer.size());
					MessageBox(hDlg, buffer, "Результат", MB_OK);
					EndDialog(hDlg, LOWORD(wParam));
					return (INT_PTR)TRUE;
				}
				getline(fin, text);
			}
			SetDlgItemText(hDlg, IDC_STATIC_MY1, text.c_str());
			for (int i = 0; i < 3; i++)
			{
				ShowWindow(GetDlgItem(hDlg, IDC_RADIO1 + i), SW_SHOW);
			}
			k = user_answer[atnum - 1];
			if (k != 0) {
				SendDlgItemMessage(hDlg, IDC_RADIO1 + k - 1, BM_CLICK, 0, 0);
			}
			k = GetAnswer(hDlg, IDC_RADIO1);
			SendDlgItemMessage(hDlg, IDC_RADIO1 + k - 1, BM_SETCHECK, 0, 0);
			user_answer[atnum - 1] = k;
			break;
		}
		case IDC_BACK:
		{
			atnum--;
			if (atnum == 0) {
				ShowWindow((GetDlgItem(hDlg, IDC_BACK)), SW_HIDE);
			}

			for (int i = 0; i <= atnum; i++)
			{
				getline(fin, text);
			}
			SetDlgItemText(hDlg, IDC_STATIC_MY1, text.c_str());
			for (int i = 0; i < 3; i++)
			{
				ShowWindow(GetDlgItem(hDlg, IDC_RADIO1 + i), SW_SHOW);
			}
			int k = user_answer[atnum];
			if (k != 0) {
				SendDlgItemMessage(hDlg, IDC_RADIO1 + k - 1, BM_CLICK, 0, 0);
			}
			break;
		}
		}
	}

	}
	return FALSE;
}

int CheckAns(const std::vector<int>& user) {
	int k = 0;
	for (size_t d = 0; d < alter_answer.size(); d++)
	{
		if (user[d] == alter_answer[d]) ++k;
	}
	return k;
}

int GetAnswer(HWND hDlg, int radio) {
	for (int i = 0; i < 3; i++)
	{
		if (SendDlgItemMessage(hDlg, radio + i, BM_GETCHECK, 0, 0)) {
			return (i + 1);
		}
	}
	return 0;
}