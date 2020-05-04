#undef UNICODE
#include <windows.h>
#include "resource.h"
#include <Commdlg.h>

OPENFILENAME ofn;
HWND hWnd;
HANDLE FirstFile;//File "Messeger"
DWORD dwTEMPWrite;// for Write and Read functions
DWORD dwTEMPRead;

CHAR s_text_1[256] = { 0 };//Arrays for file

BOOL CALLBACK DlgMain(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    static HANDLE hFile, hFileMap;
    static DWORD fSize;
    static char* p;

    switch (uMsg)
    {
    case WM_CLOSE:
        EndDialog(hwndDlg, 0);
        break;

    case WM_COMMAND:
    {
        switch (LOWORD(wParam))
        {
        case IDCANCEL:
        {
            EndDialog(hwndDlg, 1);
            break;
        }
        case IDOK:
        {
            EndDialog(hwndDlg, 2);
            break;
        }
        case IDC_BUTTON1:
        {
            char szFile[260] = { 0 };
            ZeroMemory(&ofn, sizeof(ofn));
            ofn.lStructSize = sizeof(ofn);
            ofn.hwndOwner = NULL;
            ofn.lpstrFile = szFile;
            ofn.nMaxFile = sizeof(szFile);
            ofn.lpstrInitialDir = NULL;
            ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_EXPLORER;
            GetOpenFileName(&ofn);
            SendDlgItemMessage(hwndDlg, IDC_LIST1, LB_ADDSTRING, 0, (LPARAM)szFile);
            break;
        }

        case IDC_BUTTON2:
        {
            GetDlgItemText(hwndDlg, IDC_EDIT1, s_text_1, sizeof(s_text_1));

            FirstFile = CreateFile("E:\\labs\\Artem\\sem2\\04.05\\Messeger.txt", GENERIC_WRITE | GENERIC_READ,
                FILE_SHARE_WRITE | FILE_SHARE_READ,
                NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
            WriteFile(FirstFile, &s_text_1, sizeof(s_text_1), &dwTEMPWrite, NULL);
            CopyFile("E:\\labs\\Artem\\sem2\\04.05\\Messeger.txt",
                "E:\\labs\\Artem\\sem2\\04.05\\First.txt", FALSE);

            break;
        }
        case IDC_BUTTON3:
        {
            SetFilePointer(FirstFile, 0, 0, FILE_BEGIN);
            ReadFile(FirstFile, s_text_1, sizeof(s_text_1), &dwTEMPRead, NULL);
            SetDlgItemText(hwndDlg, IDC_EDIT1, s_text_1);
            break;
        }
        }
    }
    return TRUE;


    default:
        return FALSE;
    }
    return TRUE;
}




int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow)
{
    int code = DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgMain);
    if (code == 1) MessageBox(NULL, "CANCEL was pressed", "Exit", MB_OK);
    if (code == 2) MessageBox(NULL, "OK was pressed", "Exit", MB_OK);

    return 0;
}