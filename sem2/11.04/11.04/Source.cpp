
#include <windows.h>
#include "resource.h"
#include <commdlg.h>
#include <string>
#include <fstream>

OPENFILENAME ofn;


HWND hWnd;
size_t GetStringCursel(HWND hwnd, int list, std::string stroka);

INT_PTR CALLBACK DlgMain(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    std::ifstream fin;
    std::string temp;
    CHAR stroka[256];
    int kol = 0;
    static HBRUSH hBrush = CreateSolidBrush(RGB(230, 230, 230));
    // ...

    switch (uMsg)
    {
    case WM_INITDIALOG:
        ShowWindow((GetDlgItem(hwndDlg, IDC_BUTTON2)), SW_HIDE);
        ShowWindow((GetDlgItem(hwndDlg, IDC_EDIT1)), SW_HIDE);
        break;
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
            
            size_t stringsize=0;
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
            HDC hdcStatic = (HDC)wParam;
            SetTextColor(hdcStatic, RGB(5, 7, 9));
            SetBkColor(hdcStatic, RGB(230, 230, 230));
            if (GetOpenFileName(&ofn) == TRUE) {
                if (SendDlgItemMessage(hwndDlg, IDC_LIST1, LB_GETCOUNT, 0, 0L) != 0) {
                    SendDlgItemMessage(hwndDlg, IDC_LIST1, LB_RESETCONTENT, 0, 0L);
                }
                ShowWindow((GetDlgItem(hwndDlg, IDC_BUTTON2)), SW_SHOW);
                ShowWindow((GetDlgItem(hwndDlg, IDC_EDIT1)), SW_SHOW);
                fin.open(szFile);

                while (!fin.eof()) {
                    kol++;
                    getline(fin, temp);
                    if (stringsize < temp.size()) stringsize = temp.size();
                    SendDlgItemMessage(hwndDlg, IDC_LIST1, LB_ADDSTRING, 0, (LPARAM)temp.c_str());
               }
                sprintf_s(stroka, "Количество строк:%d\nМаксимальная длина строки:%d\nПолное имя Файла:%s", kol, stringsize, szFile);
                SetDlgItemText(hwndDlg, IDC_STATIC_MY, stroka);
            }
            else {
                SetDlgItemText(hwndDlg, IDC_STATIC_MY, "File wasn't open");
            }
            break;
        }
        case IDC_Find:
        {
            GetDlgItemText(hwndDlg, IDC_EDIT1, stroka, sizeof(stroka));
            std::string nstroka(stroka);
            int k = GetStringCursel(hwndDlg, IDC_LIST1, nstroka);
            if (k != -1) {
                SendDlgItemMessage(hwndDlg, IDC_LIST1, LB_SETCURSEL, k, 0L);
            }
            else {
                MessageBox(hwndDlg, "Not found", "Error", MB_OK);
            }
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
    DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgMain);
    return 0;
}

size_t GetStringCursel(HWND hwnd,int list, std::string stroka) {
    int k = SendDlgItemMessage(hwnd, list, LB_GETCOUNT, 0, 0L);
    std::string temp;
    CHAR tmp[256];
    for (int i = 0; i < k; i++)
    {
        SendDlgItemMessage(hwnd, list, LB_GETTEXT, i, (LPARAM)tmp);
        temp = tmp;
        if (temp.find(stroka) != -1) {
             return i;
        }
           
    }
    return -1;
}