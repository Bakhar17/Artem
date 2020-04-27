#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>

int GetRect(int x, int y,int xSize,int ySize);
void Paint1(HDC, HPEN, int flag, int xSize, int ySize);
void Paint2(HDC, HPEN, int flag, int xSize, int ySize);
void Paint3(HDC, HPEN, int flag, int xSize, int ySize);
void Paint4(HDC, HPEN, int flag, int xSize, int ySize);
void Paint5(HDC, HPEN, int flag, int xSize, int ySize);
void Paint6(HDC, HPEN, int flag, int xSize, int ySize);
void Paint7(HDC, HPEN, int flag, int xSize, int ySize);
void Paint8(HDC, HPEN, int flag, int xSize, int ySize);
void Paint9(HDC, HPEN, int flag, int xSize, int ySize);
void (*Paint[9])(HDC, HPEN, int flag, int xSize, int ySize) = {Paint1,Paint2,Paint3 ,Paint4 ,Paint5 ,Paint6 ,Paint7 ,Paint8 ,Paint9 };
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
    HDC hdc;
    static int flag[9];
    static int xSize, ySize;
    int x, y;
    static int sector;
    switch (uMsg)
    {
    case WM_SIZE:
    {
        xSize = LOWORD(lParam);
        ySize = HIWORD(lParam);
        InvalidateRect(hwnd, NULL, 1);
        break;
    }
    case WM_LBUTTONDOWN:{
        HPEN pen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
        hdc = GetDC(hwnd);
        x = LOWORD(lParam);
        y = HIWORD(lParam);
        sector = GetRect(x, y, xSize, ySize);
        switch (sector) {
        case 1:
            if (flag[0] == 0) {
            flag[0] = 1;
            Paint[0](hdc, pen, flag[0], xSize, ySize);
            }
            break;
        case 2:
            if (flag[1] == 0) {
                flag[1] = 1;
                Paint[1](hdc, pen, flag[1], xSize, ySize);
            }
            break;
        case 3:
            if (flag[2] == 0) {
                flag[2] = 1;
                Paint[2](hdc, pen, flag[2], xSize, ySize);
            }

            break;
        case 4:
            if (flag[3] == 0) {
                flag[3] = 1;
                Paint[3](hdc, pen, flag[3], xSize, ySize);
            }

            break;
        case 5:
            if (flag[4] == 0) {
                flag[4] = 1;
                Paint[4](hdc, pen, flag[4], xSize, ySize);
            }

            break;
        case 6:
            if (flag[5] == 0) {
                flag[5] = 1;
                Paint[5](hdc, pen, flag[5], xSize, ySize);
            }

            break;
        case 7:
            if (flag[6] == 0) {
                flag[6] = 1;
                Paint[6](hdc, pen, flag[6], xSize, ySize);
            }
  
            break;
        case 8:
            if (flag[7] == 0) {
                flag[7] = 1;
                Paint[7](hdc, pen, flag[7], xSize, ySize);
            }

            break;
        case 9:
            if (flag[8] == 0) {
                flag[8] = 1;
                Paint[8](hdc, pen, flag[8], xSize, ySize);
            }

            break;
        }
        DeleteObject(pen);
        break;
    }
    case WM_RBUTTONDOWN:
    {
        HPEN pen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
        hdc = GetDC(hwnd);
        x = LOWORD(lParam);
        y = HIWORD(lParam);
        sector = GetRect(x, y, xSize, ySize);
        switch (sector) {
        case 1:
            if (flag[0] == 0) {
                flag[0] = 2;
                Paint[0](hdc, pen, flag[0], xSize, ySize);
            }
            break;
        case 2:
            if (flag[1] == 0) {
                flag[1] = 2;
                Paint[1](hdc, pen, flag[1], xSize, ySize);
            }
            break;
        case 3:
            if (flag[2] == 0) {
                flag[2] = 2;
                Paint[2](hdc, pen, flag[2], xSize, ySize);
            }

            break;
        case 4:
            if (flag[3] == 0) {
                flag[3] = 2;
                Paint[3](hdc, pen, flag[3], xSize, ySize);
            }

            break;
        case 5:
            if (flag[4] == 0) {
                flag[4] = 2;
                Paint[4](hdc, pen, flag[4], xSize, ySize);
            }

            break;
        case 6:
            if (flag[5] == 0) {
                flag[5] = 2;
                Paint[5](hdc, pen, flag[5], xSize, ySize);
            }

            break;
        case 7:
            if (flag[6] == 0) {
                flag[6] = 2;
                Paint[6](hdc, pen, flag[6], xSize, ySize);
            }

            break;
        case 8:
            if (flag[7] == 0) {
                flag[7] = 2;
                Paint[7](hdc, pen, flag[7], xSize, ySize);
            }

            break;
        case 9:
            if (flag[8] == 0) {
                flag[8] = 2;
                Paint[8](hdc, pen, flag[8], xSize, ySize);
            }

            break;
        }
        DeleteObject(pen);
        break;
    }
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
        

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        hdc = BeginPaint(hwnd, &ps);
        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
        HPEN pen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
        SelectObject(hdc, pen);
        MoveToEx(hdc, xSize / 3, 0, NULL);
        LineTo(hdc, xSize / 3, ySize );
        MoveToEx(hdc, xSize * 2 / 3, 0, NULL);
        LineTo(hdc, xSize * 2 / 3, ySize);
        MoveToEx(hdc, 0, ySize / 3,NULL);
        LineTo(hdc, xSize, ySize / 3);
        MoveToEx(hdc, 0, ySize * 2 / 3, NULL);
        LineTo(hdc, xSize, ySize * 2 / 3);
        for (int i = 0; i < 9; i++)
        {   
            hdc = GetDC(hwnd);
            if (flag[i] != 0) {
                Paint[i](hdc,pen,flag[i],xSize,ySize);
            }
        }

        DeleteObject(pen);

        EndPaint(hwnd, &ps);
    }
    return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int GetRect(int x, int y,int xSize,int ySize) {
    int sector = 0;
    if (x < xSize / 3) {
        if (y < ySize / 3) sector = 1;
        else if (y > ySize / 3 && y < ySize * 2 / 3) sector = 4;
        else if (y > ySize * 2 / 3) sector = 7;
    }
    else if (x > xSize / 3 && x < xSize * 2 / 3) {
        if (y < ySize / 3) sector = 2;
        else if (y > ySize / 3 && y < ySize * 2 / 3) sector = 5;
        else if (y > ySize * 2 / 3) sector = 8;
    }
    else if (x > xSize * 2 / 3) {
        if (y < ySize / 3) sector = 3;
        else if (y > ySize / 3 && y < ySize * 2 / 3) sector = 6;
        else if (y > ySize * 2 / 3) sector = 9;
    }

    return sector;
}

void Paint1(HDC hdc, HPEN pen,int flag, int xSize, int ySize) {
    if (flag == 1) {
        SelectObject(hdc, pen);
        MoveToEx(hdc, 1, 1, NULL);
        LineTo(hdc, xSize / 3, ySize / 3);
        MoveToEx(hdc, xSize / 3, 0, NULL);
        LineTo(hdc, 0, ySize / 3);
    }
    else if (flag == 2) {
        SelectObject(hdc, pen);
        Ellipse(hdc, xSize / 6 - ySize / 6, 0, xSize / 6 + ySize / 6, ySize / 3);
    }
    else return;
}

void Paint2(HDC hdc, HPEN pen, int flag, int xSize, int ySize) {
    if (flag == 1) {
        SelectObject(hdc, pen);
        MoveToEx(hdc, xSize/3, 0, NULL);
        LineTo(hdc, 2*xSize / 3, ySize / 3);
        MoveToEx(hdc, 2*xSize / 3, 0, NULL);
        LineTo(hdc,xSize/3, ySize / 3);
    }
    else if (flag == 2) {
        SelectObject(hdc, pen);
        Ellipse(hdc, xSize / 2 - ySize / 6, 0, xSize / 2 + ySize / 6, ySize / 3);
    }
    else return;
}
void Paint3(HDC hdc, HPEN pen, int flag, int xSize, int ySize) {
    if (flag == 1) {
        SelectObject(hdc, pen);
        MoveToEx(hdc, xSize * 2 / 3, 0, NULL);
        LineTo(hdc, xSize, ySize / 3);
        MoveToEx(hdc, xSize, 0, NULL);
        LineTo(hdc, xSize * 2 / 3, ySize / 3);
    }
    else if (flag == 2) {
        SelectObject(hdc, pen);
        Ellipse(hdc, 5*xSize / 6 - ySize / 6, 0, 5*xSize / 6 + ySize / 6, ySize / 3);
    }
    else return;
}

void Paint4(HDC hdc, HPEN pen, int flag, int xSize, int ySize) {
    if (flag == 1) {
        SelectObject(hdc, pen);
        MoveToEx(hdc, 0, ySize / 3, NULL);
        LineTo(hdc, xSize / 3, 2 * ySize / 3);
        MoveToEx(hdc, xSize / 3, ySize / 3, NULL);
        LineTo(hdc, 0, 2 * ySize / 3);
    }
    else if (flag == 2) {
        SelectObject(hdc, pen);
        Ellipse(hdc, xSize / 6 - ySize / 6, ySize/3, xSize / 6 + ySize / 6, 2*ySize / 3);
    }
    else return;
}

void Paint5(HDC hdc, HPEN pen, int flag, int xSize, int ySize) {
    if (flag == 1) {
        SelectObject(hdc, pen);
        MoveToEx(hdc, xSize / 3, ySize / 3, NULL);
        LineTo(hdc, xSize * 2 / 3, 2 * ySize / 3);
        MoveToEx(hdc, xSize * 2 / 3, ySize / 3, NULL);
        LineTo(hdc, xSize / 3, 2 * ySize / 3);
    }
    else if (flag == 2) {
        SelectObject(hdc, pen);
        Ellipse(hdc, xSize / 2 - ySize / 6, ySize / 3, xSize / 2 + ySize / 6, 2*ySize / 3);
    }
    else return;
}

void Paint6(HDC hdc, HPEN pen, int flag, int xSize, int ySize) {
    if (flag == 1) {
        SelectObject(hdc, pen);
        MoveToEx(hdc, xSize * 2 / 3, ySize / 3, NULL);
        LineTo(hdc, xSize, 2 * ySize / 3);
        MoveToEx(hdc, xSize, ySize / 3, NULL);
        LineTo(hdc, xSize * 2 / 3, 2 * ySize / 3);
    }
    else if (flag == 2) {
        SelectObject(hdc, pen);
        Ellipse(hdc, 5 * xSize / 6 - ySize / 6, ySize/3, 5 * xSize / 6 + ySize / 6, 2*ySize/3 );
    }
    else return;
}

void Paint7(HDC hdc, HPEN pen, int flag, int xSize, int ySize) {
    if (flag == 1) {
        SelectObject(hdc, pen);
        MoveToEx(hdc, 0, 2 * ySize / 3, NULL);
        LineTo(hdc, xSize / 3, ySize);
        MoveToEx(hdc, xSize / 3, 2 * ySize / 3, NULL);
        LineTo(hdc, 0, ySize);
    }
    else if (flag == 2) {
        SelectObject(hdc, pen);
        Ellipse(hdc, xSize / 6 - ySize / 6, 2*ySize/3, xSize / 6 + ySize / 6, ySize );
    }
    else return;
}

void Paint8(HDC hdc, HPEN pen, int flag, int xSize, int ySize) {
    if (flag == 1) {
        SelectObject(hdc, pen);
        MoveToEx(hdc, xSize / 3, 2 * ySize / 3, NULL);
        LineTo(hdc, xSize * 2 / 3, ySize);
        MoveToEx(hdc, xSize * 2 / 3, 2 * ySize / 3, NULL);
        LineTo(hdc, xSize / 3, ySize);
    }
    else if (flag == 2) {
        SelectObject(hdc, pen);
        Ellipse(hdc, xSize / 2 - ySize / 6, 2*ySize / 3, xSize / 2 + ySize / 6, ySize);
    }
    else return;
}

void Paint9(HDC hdc, HPEN pen, int flag, int xSize, int ySize) {
    if (flag == 1) {
        SelectObject(hdc, pen);
        MoveToEx(hdc, xSize * 2 / 3, 2 * ySize / 3, NULL);
        LineTo(hdc, xSize, ySize);
        MoveToEx(hdc, xSize, 2 * ySize / 3, NULL);
        LineTo(hdc, xSize * 2 / 3, ySize);
    }
    else if (flag == 2) {
        SelectObject(hdc, pen);
        Ellipse(hdc, 5 * xSize / 6 - ySize / 6, 2*ySize / 3, 5 * xSize / 6 + ySize / 6,ySize);
    }
    else return;
}

