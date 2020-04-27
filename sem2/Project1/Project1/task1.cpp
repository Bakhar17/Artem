#ifndef UNICODE
#define UNICODE
#endif

#define _USE_MATH_DEFINES
#include <cmath>
#include <windows.h>
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow)
{
    // Register the window class.
    const wchar_t CLASS_NAME[] = L"Sample Window Class";

    WNDCLASS wc = { };

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
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
    // Run the message loop.
    MSG msg = { };
    SetTimer(hwnd, 1, 500, NULL);
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
    static int size_x, size_y, x, y,sec;
    int i;
    static POINT apt[1001];


    switch (uMsg)
    {
    case WM_LBUTTONDOWN:
        SetTimer(hwnd, 1, 500, NULL);
        return 0;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    case WM_SIZE:
        //Запоминаем текущие размеры окна.
        size_x = LOWORD(lParam);
        size_y = HIWORD(lParam);
        break;
    case WM_TIMER:
        if (sec <= 1000) {
        x = apt[sec].x;
        y = apt[sec].y;
        sec += 50;
        InvalidateRect(hwnd, NULL, TRUE);
        break;
        }
        else if (sec <= 2000) {
            x = apt[2000-sec].x;
            y = apt[2000-sec].y;
            sec += 50;
            InvalidateRect(hwnd, NULL, TRUE);
            break;
        }
        else {
            sec = 0;
            InvalidateRect(hwnd, NULL,TRUE);
            break;
        }
        

    case WM_RBUTTONDOWN:
        KillTimer(hwnd, 1);
        break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        HBRUSH brushr = CreateSolidBrush(RGB(255, 118, 1));
        FillRect(hdc, &ps.rcPaint, brushr);
        DeleteObject(brushr);
        HPEN pen = CreatePen(PS_SOLID, 4, RGB(0, 0, 0));
        HBRUSH brush = CreateSolidBrush(RGB(60, 179, 13));
        MoveToEx(hdc, 0, size_y / 2, nullptr);
        LineTo(hdc, size_x, size_y / 2);
        SelectObject(hdc, pen);
        for (i = 0; i <= 1000; i++)
        {
            apt[i].x = i * size_x / 1000;
            apt[i].y = (int)(size_y / 2 * (1 - sin(M_PI * i / 250)));
        }
        Polyline(hdc, apt,1000);
        SelectObject(hdc, brush);
        Ellipse(hdc, x - 20, y - 20, x + 20, y + 20);
        DeleteObject(brush);
        DeleteObject(pen);


        EndPaint(hwnd, &ps);
        break;
    }


    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}