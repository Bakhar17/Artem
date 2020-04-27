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
    
    static int xsize, ysize, radius;

    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_SIZE:
        xsize = LOWORD(lParam)/2;
        ysize = HIWORD(lParam)/2;
        radius = ysize;
        InvalidateRect(hwnd, NULL, TRUE);
        UpdateWindow(hwnd);
        break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        HFONT oldFont, newFont;

        HBRUSH brush = CreateSolidBrush(RGB(255, 253, 186));
        FillRect(hdc, &ps.rcPaint,brush );

        hdc = GetDC(hwnd);
        brush = CreateSolidBrush(RGB(255, 127, 0));
        SelectObject(hdc, brush);
        Ellipse(hdc,xsize-radius, ysize-radius, xsize + radius, ysize + radius);
        SetBkColor(hdc,RGB(255, 127, 0));
        newFont = CreateFont(55, 0, 0, 0, 700, 1, 0, 0,
            DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
            DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"TimesNewRoman");
        oldFont = (HFONT)SelectObject(hdc, newFont);
        TextOut(hdc, xsize - radius + radius / 24, ysize-radius/12, L"1", 1);
        TextOut(hdc, xsize + radius - radius / 8, ysize-radius/12, L"1", 1);
        TextOut(hdc, xsize-radius/24, ysize - radius + radius / 48, L"1", 1);
        TextOut(hdc, xsize-radius/24 , ysize + radius-radius/6, L"1", 1);
        SelectObject(hdc, oldFont);
        DeleteObject(newFont);

       
        radius = radius / 1.2;
        brush = CreateSolidBrush(RGB(255, 255, 0));
        SelectObject(hdc, brush);
        Ellipse(hdc, xsize - radius, ysize - radius, xsize + radius, ysize + radius);
        SetBkColor(hdc, RGB(255, 255, 0));
        newFont = CreateFont(50, 0, 0, 0, 700, 1, 0, 0,
            DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
            DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"TimesNewRoman");
        oldFont = (HFONT)SelectObject(hdc, newFont);
        TextOut(hdc, xsize - radius + radius / 24, ysize - radius / 12, L"2", 1);
        TextOut(hdc, xsize + radius - radius / 8, ysize - radius / 12, L"2", 1);
        TextOut(hdc, xsize - radius / 24, ysize - radius + radius / 48, L"2", 1);
        TextOut(hdc, xsize - radius / 24, ysize + radius - radius / 5.5, L"2", 1);

        radius = radius / 1.2;
        brush = CreateSolidBrush(RGB(0,255,0));
        SelectObject(hdc, brush);
        Ellipse(hdc, xsize - radius, ysize - radius, xsize + radius, ysize + radius);
        SetBkColor(hdc, RGB(0, 255, 0));
        newFont = CreateFont(40, 0, 0, 0, 700, 1, 0, 0,
            DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
            DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"TimesNewRoman");
        oldFont = (HFONT)SelectObject(hdc, newFont);
        TextOut(hdc, xsize - radius + radius / 24, ysize - radius / 12, L"3", 1);
        TextOut(hdc, xsize + radius - radius / 8, ysize - radius / 12, L"3", 1);
        TextOut(hdc, xsize - radius / 24, ysize - radius + radius / 48, L"3", 1);
        TextOut(hdc, xsize - radius / 24, ysize + radius - radius / 6, L"3", 1);

        radius = radius / 1.2;
        brush = CreateSolidBrush(RGB(0, 0, 255));
        SelectObject(hdc, brush);
        Ellipse(hdc, xsize - radius, ysize - radius, xsize + radius, ysize + radius);
        SetBkColor(hdc, RGB(0, 0, 255));
        newFont = CreateFont(35, 0, 0, 0, 700, 1, 0, 0,
            DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
            DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"TimesNewRoman");
        oldFont = (HFONT)SelectObject(hdc, newFont);
        TextOut(hdc, xsize - radius + radius / 24, ysize - radius / 12, L"4", 1);
        TextOut(hdc, xsize + radius - radius / 8, ysize - radius / 12, L"4", 1);
        TextOut(hdc, xsize - radius / 24, ysize - radius + radius / 48, L"4", 1);
        TextOut(hdc, xsize - radius / 24, ysize + radius - radius / 6, L"4", 1);

        radius = radius / 1.2;
        brush = CreateSolidBrush(RGB(75, 0,130));
        SelectObject(hdc, brush);
        Ellipse(hdc, xsize - radius, ysize - radius, xsize + radius, ysize + radius);
        SetBkColor(hdc, RGB(75, 0, 130));
        newFont = CreateFont(30, 0, 0, 0, 700, 1, 0, 0,
            DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
            DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"TimesNewRoman");
        oldFont = (HFONT)SelectObject(hdc, newFont);
        TextOut(hdc, xsize - radius + radius / 24, ysize - radius / 12, L"5", 1);
        TextOut(hdc, xsize + radius - radius / 8, ysize - radius / 12, L"5", 1);
        TextOut(hdc, xsize - radius / 24, ysize - radius + radius / 48, L"5", 1);
        TextOut(hdc, xsize - radius / 24, ysize + radius - radius / 6, L"5", 1);

        radius = radius / 1.2;
        brush = CreateSolidBrush(RGB(143, 0, 255));
        SelectObject(hdc, brush);
        Ellipse(hdc, xsize - radius, ysize - radius, xsize + radius, ysize + radius);
        SetBkColor(hdc, RGB(143, 0, 255));
        newFont = CreateFont(25, 0, 0, 0, 700, 1, 0, 0,
            DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
            DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"TimesNewRoman");
        oldFont = (HFONT)SelectObject(hdc, newFont);
        TextOut(hdc, xsize - radius + radius / 24, ysize - radius / 12, L"6", 1);
        TextOut(hdc, xsize + radius - radius / 8, ysize - radius / 12, L"6", 1);
        TextOut(hdc, xsize - radius / 24, ysize - radius + radius / 48, L"6", 1);
        TextOut(hdc, xsize - radius / 24, ysize + radius - radius / 5.5, L"6", 1);

        radius = radius / 1.2;
        brush = CreateSolidBrush(RGB(0, 0, 255));
        SelectObject(hdc, brush);
        Ellipse(hdc, xsize - radius, ysize - radius, xsize + radius, ysize + radius);
        SetBkColor(hdc, RGB(0, 0, 255));
        newFont = CreateFont(22, 0, 0, 0, 700, 1, 0, 0,
            DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
            DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"TimesNewRoman");
        oldFont = (HFONT)SelectObject(hdc, newFont);
        TextOut(hdc, xsize - radius + radius / 24, ysize - radius / 12, L"7", 1);
        TextOut(hdc, xsize + radius - radius / 8, ysize - radius / 12, L"7", 1);
        TextOut(hdc, xsize - radius / 24, ysize - radius + radius / 48, L"7", 1);
        TextOut(hdc, xsize - radius / 24, ysize + radius - radius / 6, L"7", 1);


        radius = radius / 1.2;
        brush = CreateSolidBrush(RGB(251, 0, 255));
        SelectObject(hdc, brush);
        Ellipse(hdc, xsize - radius, ysize - radius, xsize + radius, ysize + radius);
        SetBkColor(hdc, RGB(251, 0, 255));
        newFont = CreateFont(18, 0, 0, 0, 700, 1, 0, 0,
            DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
            DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"TimesNewRoman");
        oldFont = (HFONT)SelectObject(hdc, newFont);
        TextOut(hdc, xsize - radius + radius / 24, ysize - radius / 12, L"8", 1);
        TextOut(hdc, xsize + radius - radius / 8, ysize - radius / 12, L"8", 1);
        TextOut(hdc, xsize - radius / 24, ysize - radius + radius / 48, L"8", 1);
        TextOut(hdc, xsize - radius / 24, ysize + radius - radius /5.5, L"8", 1);

        radius = radius / 1.2;
        brush = CreateSolidBrush(RGB(255,0,0));
        SelectObject(hdc, brush);
        Ellipse(hdc, xsize - radius, ysize - radius, xsize + radius, ysize + radius);
        SetBkColor(hdc, RGB(255, 0, 0));
        newFont = CreateFont(12, 0, 0, 0, 700, 1, 0, 0,
            DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
            DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"TimesNewRoman");
        oldFont = (HFONT)SelectObject(hdc, newFont);
        TextOut(hdc, xsize - radius + radius / 24, ysize - radius / 12, L"9", 1);
        TextOut(hdc, xsize + radius - radius / 8, ysize - radius / 12, L"9", 1);
        TextOut(hdc, xsize - radius / 24, ysize - radius + radius / 48, L"9", 1);
        TextOut(hdc, xsize - radius / 24, ysize + radius - radius / 6, L"9", 1);

        radius = radius / 1.2;
        brush = CreateSolidBrush(RGB(255, 255, 255));
        SelectObject(hdc, brush);
        Ellipse(hdc, xsize - radius, ysize - radius, xsize + radius, ysize + radius);
        SetBkColor(hdc, RGB(255, 255, 255));
        newFont = CreateFont(75, 0, 0, 0, 700, 1, 0, 0,
            DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
            DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"TimesNewRoman");
        oldFont = (HFONT)SelectObject(hdc, newFont);
        TextOut(hdc, xsize -radius/2, ysize-radius/2 , L"10",2);


        UpdateWindow(hwnd);
        DeleteObject(brush);

        EndPaint(hwnd, &ps);
        break;
    }
    return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}