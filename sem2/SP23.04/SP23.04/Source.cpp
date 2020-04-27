#ifndef UNICODE
#define UNICODE
#endif
#include <windows.h>
#include "resource.h"

INT_PTR CALLBACK DLG(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow)
{
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DLG);
	return 0;
}

INT_PTR CALLBACK DLG(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);

	switch (message)
	{
	case WM_INITDIALOG:
		SetDlgItemText(hDlg, IDC_STATIC_MY1, L"Fuck WinApi");
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case IDOK:
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
			break;
		case IDCANCEL:
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
			break;
		}
		break;
	}
	return (INT_PTR)FALSE;
}