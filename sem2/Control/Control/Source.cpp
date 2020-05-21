
#include <windows.h>
#include <vector>
#include <cmath>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow)
{
    // Register the window class.
    const CHAR CLASS_NAME[] = "Sample Window Class";

    WNDCLASS wc = { };

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    // Create the window.

    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        "Learn to Program Windows",    // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        // Size and position
        0, 0, 500, 1000,

        NULL,       // Parent window    
        NULL,       // Menu
        hInstance,  // Instance handle
        NULL        // Additional application data
    );

    if (hwnd == NULL)
    {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    // Run the message loop.
    SetTimer(hwnd, 1, 1000, NULL);
    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    static int xPos, yPos;
    static int numberofellipse;
    static std::vector<int> kf;
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    case WM_TIMER:
    case WM_MOUSEMOVE:

        xPos = LOWORD(lParam);
        yPos = HIWORD(lParam);
        numberofellipse++;
        kf.push_back((yPos-950) / (xPos-250));
        InvalidateRect(hwnd, NULL, TRUE);
        break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
        HPEN hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
        for (int i = 0; i <= 10; i++)
        {
            MoveToEx(hdc, 0, 100 * i, NULL);
            LineTo(hdc, 500, 100 * i);

        }
        for (int i = 0; i <= 5; i++)
        {
            MoveToEx(hdc, 100 * i, 0, NULL);
            LineTo(hdc, 100 * i, 1000);
        }
        HBRUSH hBrush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));
        for (int i = 0; i < numberofellipse; i++)
        {
            SelectObject(hdc, hBrush);
            Ellipse(hdc, 200, 900, 300, 1000);
        }
        for (int i = 0; i < numberofellipse; i++)
        {
            SelectObject(hdc, hBrush);
            Ellipse(hdc, 200+cos(atan(kf[i])), 900- 50*sin(atan(kf[i])), 300+ cos(atan(kf[i])), 1000- 50*sin(atan(kf[i])));
        }
        DeleteObject(hBrush);
        DeleteObject(hPen);
        

        EndPaint(hwnd, &ps);
    }
    return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}