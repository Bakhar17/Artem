#ifndef UNICODE
#define UNICODE
#endif

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
    const unsigned int Timer1 = 1;
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);
    // Run the message loop.

    MSG msg = { };
    SetTimer(hwnd, Timer1, 500, NULL);
    //void someFunc (HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime);
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
    KillTimer(hwnd, Timer1);


}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    HBRUSH brush;
    static int size_x, size_y, x, y;
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    case WM_SIZE:
        //Запоминаем текущие размеры окна.
        size_x = LOWORD(lParam);
        size_y = HIWORD(lParam);
        break;
    case WM_TIMER:
        x = rand() % size_x;
        y = rand() % size_y;
        InvalidateRect(hwnd, NULL, TRUE);
        break;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        brush = CreateSolidBrush(RGB(60, 179, 13));
        SelectObject(hdc, brush);
        Ellipse(hdc, x - 20, y - 20, x + 20, y + 20);
        DeleteObject(brush);

        // FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));

        EndPaint(hwnd, &ps);
        break;
    }
    UpdateWindow(hwnd);
    return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}