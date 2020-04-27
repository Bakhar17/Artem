#ifndef UNICODE
#define UNICODE
#endif 

#include <windows.h>
#include "resource.h"
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK edit_R(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
static HINSTANCE hInst;
static unsigned int n = 20;
const unsigned int Timer1 = 1;
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow)
{
    // Register the window class.
    const wchar_t CLASS_NAME[] = L"Sample Window Class";


    WNDCLASS wc = { };

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wc.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
    HWND hMainWindow = NULL;
    RegisterClass(&wc);

    // Create the window.

    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        L"Learn to Program Windows",    // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,       // Parent window    
        NULL,       // Menu
        hInstance,  // Instance handle
        NULL        // Additional application data
    );

    /*if (hwnd == NULL)
    {
    return 0;
    }*/

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);
    // Run the message loop.

    MSG msg = { };

    //void someFunc (HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime);
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;



}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    HBRUSH brush;
    static int size_x, size_y, x, y;
    switch (uMsg)
    {


    case WM_DESTROY:
        KillTimer(hwnd, Timer1);
        PostQuitMessage(0);
        return 0;
    case WM_COMMAND:
    {
        HMENU hMenu = GetMenu(hwnd); // Получаем дескриптор меню; 
        switch (LOWORD(wParam)) // Смотрим, какая команда;
        {
        case ID_MENU_CHANGER:
        { static bool check = true; // bool хранит состояние;
        if (check) // Если включён, снимаем флажок;
        {
            CheckMenuItem(hMenu, ID_MENU_CHANGER, MF_UNCHECKED);
            check = false;
            /*Код для выключения*/
        }
        else // Если выключен, то включаем;
        {
            CheckMenuItem(hMenu, ID_MENU_CHANGER, MF_CHECKED);
            check = true;
                if (DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hwnd, edit_R))
                    InvalidateRect(hwnd, 0, 1);
            /*Код для включения*/
        }
        break;
        }
        case ID_CHANGER_COLOR:
        { EnableMenuItem(hMenu, ID_CHANGER_COLOR, MF_GRAYED); // Выключаем - делаем серым;
        EnableMenuItem(hMenu, ID_CHANGER_EXIT, MF_ENABLED); // Включаем - делаем чёрным;
        /*Код*/
        }
        break;
        case ID_CHANGER_EXIT:
        { EnableMenuItem(hMenu, ID_CHANGER_EXIT, MF_GRAYED);
        EnableMenuItem(hMenu, ID_CHANGER_COLOR, MF_ENABLED);
        /*Код*/
        }
        break;

        }
    }
    case WM_CREATE:
        SetTimer(hwnd, Timer1, 1000, NULL);
        break;
    case WM_SIZE:
        //Запоминаем текущие размеры окна.
        size_x = LOWORD(lParam);
        size_y = HIWORD(lParam);
        break;
    case WM_TIMER:
        x = rand() % (size_x + 1);
        y = rand() % (size_y + 1);
        InvalidateRect(hwnd, NULL, TRUE);
        break;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        brush = CreateSolidBrush(RGB(60, 179, 13));
        SelectObject(hdc, brush);
        Ellipse(hdc, x - n, y - n, x + n, y + n);
        DeleteObject(brush);

        EndPaint(hwnd, &ps);
        break;
    }
    UpdateWindow(hwnd);
    return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

INT_PTR CALLBACK edit_R(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_CLOSE:
        EndDialog(hwndDlg, 0);
        break;
    case WM_INITDIALOG://инициализация, здесь будут добавляться компоненты

        SetDlgItemText(hwndDlg, IDC_EDIT1, L"Enter number");

        break;
    case WM_COMMAND:
    {
        switch (LOWORD(wParam))
        {
        case IDC_BUTTON1:
        {
            TCHAR input[100];
            GetDlgItemText(hwndDlg, IDC_EDIT1, input, sizeof(input));
            n = _wtoi(input);

        }
        break;
        }
    }
    return TRUE;

    default:
        return FALSE;
    }
}