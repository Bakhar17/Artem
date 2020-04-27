#undef UNICODE
#include <windows.h>
#include "resource.h"
#include <cstdlib>


BOOL CALLBACK DlgMain(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_CLOSE:
        EndDialog(hwndDlg, 0);
        break;
    case WM_INITDIALOG://инициализация, здесь будут добавляться компоненты

        SetDlgItemText(hwndDlg, IDC_EDIT1, "Enter number");

        break;
    case WM_COMMAND:
    {
        switch (LOWORD(wParam))
        {
        case IDOK:
        {
            char input[100];
            GetDlgItemText(hwndDlg, IDC_EDIT1, input, sizeof(input));
            unsigned int n = atoi(input);
            char output[100];
            //itoa(n, output, 10);
           // SetDlgItemText(hwndDlg, IDC_OUTPUT, output);
        }
        }
    }
    return TRUE;

    default:
        return FALSE;
    }
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow)
{
    DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgMain);
    return 0;
}