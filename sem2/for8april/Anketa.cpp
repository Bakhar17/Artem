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
    static int xSize, ySize;
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_SIZE:
        xSize = LOWORD(lParam);
        ySize = HIWORD(lParam);
        InvalidateRect(hwnd, NULL, TRUE);
        return 0;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        FillRect(hdc, &ps.rcPaint, (HBRUSH)RGB(255,255,255) );
        static LOGFONT lf;
        lf.lfCharSet = DEFAULT_CHARSET;
        lf.lfPitchAndFamily = DEFAULT_PITCH;
        lf.lfHeight = 1.5*ySize;
        lf.lfWeight = FW_ULTRALIGHT;
        lf.lfWidth=xSize/7;
        HFONT hFontN1 = CreateFontIndirect(&lf);
        HFONT FontO = (HFONT)SelectObject(hdc, hFontN1);
        SetTextColor(hdc, RGB(255, 0, 0));

        TextOut(hdc, 1, -ySize/4, L"A", 1);

        lf.lfCharSet = DEFAULT_CHARSET;
        lf.lfPitchAndFamily = DEFAULT_PITCH;
        lf.lfHeight = 0.7 * ySize;
        lf.lfWeight = FW_ULTRALIGHT;
        lf.lfWidth = xSize /8;
        hFontN1 = CreateFontIndirect(&lf);
        FontO = (HFONT)SelectObject(hdc, hFontN1);
        SetTextColor(hdc, RGB(0, 0, 255));
        TextOut(hdc, xSize/4, -ySize/5, L"нкета", 5);
        SetTextColor(hdc, RGB(0, 255, 0));
        TextOut(hdc, xSize /4 , ySize /2.5, L"nketa", 5);
        EndPaint(hwnd, &ps);
    }
    return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}