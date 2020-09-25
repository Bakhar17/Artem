#include <windows.h>
#include "resource.h"
#include "Deque.h"
#include "Iterator.h"
#include "Integer.h"
#include "Controller.h"

INT_PTR CALLBACK DlgMain(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    static Deque<Integer> deque = { 5,7,5,15,3,6 };
    static View content(hwndDlg, &deque);
    static Controller contr(&content, &deque);
    switch (uMsg)
    {
    case WM_INITDIALOG:
        contr.Update();
        break;
    case WM_CLOSE:
        EndDialog(hwndDlg, 0);
        break;
    case WM_COMMAND:
    {
        switch (LOWORD(wParam))
        {
        case IDPBack:
        {
            contr.PushB();
            break;
        }
        case IDPFRONT:
        {
            contr.PushF();
            break;
        }
        case IDPOPB:
        {
            contr.PopB();
            break;
        }
        case IDPOPF:
        {
            contr.PopF();
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
