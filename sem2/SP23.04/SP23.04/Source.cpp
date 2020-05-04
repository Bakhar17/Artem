#include <windows.h>
#include "resource.h"
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

std::vector<int> alter_answer = { 1,3,2,3 };
int atnum = 0;

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
	std::vector<int> user_answer;
	switch (message)
	{
	case WM_INITDIALOG:
	{
		getline(fin, text);
		SetDlgItemText(hDlg, IDC_STATIC_MY1, "Нажмите кнопку \"ОК\" для начала теста.");
			for (int i = 0; i < 3; i++)
			{
				ShowWindow(GetDlgItem(hDlg, IDC_RADIO1 + i), SW_HIDE);
			}

		

	}
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case IDOK:
			for (int i = 0; i <= atnum; i++)
			{
				if (fin.eof()) {
					int k=0;
					for (int d = 0; d < alter_answer.size(); d++)
					{
						if (user_answer[d] == alter_answer[d]) k++;
					}
					char buffer[100];
					sprintf_s(buffer, "Вы ответили на все вопросы!\nВерно %i/%i", k,alter_answer.size());
					MessageBox(hDlg, buffer, "", MB_OK);
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

			atnum++;
			switch (1)
			{
			case 1:
				if (SendDlgItemMessage(hDlg, IDC_RADIO1, BM_GETCHECK, 0, 0))
				{
					user_answer.push_back(1);
					break;
				}
			case 2:
				if (SendDlgItemMessage(hDlg, IDC_RADIO2, BM_GETCHECK, 0, 0))
				{
					user_answer.push_back(2);
					break;
				}
			case 3:
				if (SendDlgItemMessage(hDlg, IDC_RADIO2, BM_GETCHECK, 0, 0))
				{
					user_answer.push_back(3);
					break;
				}
			}
			break;
		case IDCANCEL:
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
			break;
		}
		return (INT_PTR)TRUE;
	}
	return (INT_PTR)FALSE;
}