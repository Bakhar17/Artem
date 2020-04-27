#ifndef UNICODE
#define UNICODE
#endif 

#include <string>
#include <windows.h>

double Func(double x, int a, int b, int c);
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow)
{
    // Register the window class.
    const wchar_t CLASS_NAME[] = L"Sample Window Class";

    WNDCLASS wc = { };

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    // Create the window.

    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        L"Quadratic function",    // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        // Size and position
        0, 0, 1000, 1000,

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
    static double x;
    static double y;
    static HBRUSH brush;
    static HPEN pen;
    static int number = 0;
    static double points[10000][2];

    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_CREATE:
        pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
        brush = CreateSolidBrush(RGB(255, 255, 255));
        break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        FillRect(hdc, &ps.rcPaint, brush);
        std::string str = "y=2x^2-50x+1";
        std::wstring stemp = std::wstring(str.begin(), str.end());
        LPCWSTR sw = stemp.c_str();
        TextOut(hdc, 1, 1,sw, str.size());
        SelectObject(hdc, pen);
        MoveToEx(hdc, 0, 500, 0);
        LineTo(hdc, 1000, 500);
        MoveToEx(hdc, 500, 0, 0);
        LineTo(hdc, 500, 1000);
        number = 0;
        int a = 2;
        int b = -50;
        int c = 1;
        for (double i = -200; i < 200; i = i + 0.05)
        {
            x = i;
            y = Func(x, a, b, c);
            if (y < (100000)) {
                points[number][0] = x * 1.5 + 500;
                points[number][1] = (-y / 100) + 500;
                number++;
            }
        }


        for (int i = 0; i < number; i++)
        {
            SetPixel(hdc, points[i][0], points[i][1], RGB(0, 0, 0));
        }
        EndPaint(hwnd, &ps);
    }
    case WM_LBUTTONDOWN:
    {
        HDC hdc;
        hdc = GetDC(hwnd);
        int xPos, yPos;
        xPos = LOWORD(lParam);
        yPos = HIWORD(lParam);
        double xpos = (xPos*1. - 500) / 1.5;
        double ypos = Func(xpos, 2, -50, 1);

        if (xPos >= 250 && xPos <= 780) {
            if (yPos <= 550) {
                std::string str = "(" + std::to_string(xpos) + "; " +
                    std::to_string(ypos) + ")";
                std::wstring stemp = std::wstring(str.begin(), str.end());
                LPCWSTR sw = stemp.c_str();
                TextOut(hdc, xPos,(-ypos)/100+500, sw, str.size());
            }
        }



        ReleaseDC(hwnd, hdc);
        break;
    }
    case WM_RBUTTONDOWN:
    {
        InvalidateRect(hwnd, NULL, TRUE);
        break;
    }
    return 0;

    }
    
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

double Func(double x,int a,int b,int c) {
    return (a * (x * x) + b * x + c * 1.);
}