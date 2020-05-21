#include <windows.h>
#include <vector>
#include "resource.h"
#include <string>

COLORREF color1=RGB(255,0,0);
COLORREF color2=RGB(0,255, 0);
COLORREF color3=RGB(0,0,255);
int width=1500;
int high=1300;
void InitCenter(std::vector<std::pair<int, int>>&);
void Check(std::vector<std::pair<int,char>>& flags,int& skill);
int ChoosePole(int, int, std::vector<std::pair<int, int>>&);
void RandomEllipse(std::vector<std::pair<int, char>>&);
int Finish(std::vector<std::pair<int, char>>& flags);// если заполнены все клетки
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK Dlg(HWND DLG, UINT message, WPARAM wParam, LPARAM lParam);
HINSTANCE hInstance;

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow)
{
    // Register the window class.
    const CHAR CLASS_NAME[] = "Sample Window Class";

    WNDCLASS wc = { };

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);

    RegisterClass(&wc);

    // Create the window.

    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        "Learn to Program Windows",    // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT,width,high,

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
    static int kol;
    static int skill;
    static int s;
    static int xPos,yPos;
    static std::vector<std::pair<int,char>> flags(100);
    std::vector < std::pair<int, int>> center;
    
    switch (uMsg)
    {
    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_F5:
            for (size_t i = 0; i < 100; i++)
            {
                flags[i].first = 0;
                flags[i].second = 'n';
            }
            kol = 0;
            skill = 0;
            InvalidateRect(hwnd, NULL, TRUE);
        }
            break;
    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case ID_RESET:
        {
            for (size_t i = 0; i < 100; i++)
            {
                flags[i].first = 0;
                flags[i].second = 'n';
            }
            kol = 0;
            skill = 0;
            InvalidateRect(hwnd, NULL, TRUE);
        }
        break;
        case ID_40003:
        {
            DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), hwnd, Dlg);
            break;
        }
        }
        break;
    case WM_LBUTTONDOWN:
    {   
        InitCenter(center);
        xPos = LOWORD(lParam);
        yPos = HIWORD(lParam);
        
        s = ChoosePole(xPos, yPos, center);
        if (s != -1) {
        if (flags[s].first == 1) {
            flags[s].first = 0;
        }
        else s = 5000;
        }

        break;
    }

    case WM_LBUTTONUP: 
    {
        InitCenter(center);
        HDC hdc;
        hdc = GetDC(hwnd);
        
        xPos = LOWORD(lParam);
        yPos = HIWORD(lParam);
        if (s != -1) {

        if (s != 5000) {
        if (flags[s].second == 'r') {
            s = ChoosePole(xPos, yPos, center);

            if (flags[s].first == 0) {
                flags[s].first = 1;
                flags[s].second = 'r';
            }
        }
        if (flags[s].second == 'g') {
            s = ChoosePole(xPos, yPos, center);

            if (flags[s].first == 0) {
                flags[s].first = 1;
                flags[s].second = 'g';
            }
        }
        if (flags[s].second == 'b') {
            s = ChoosePole(xPos, yPos, center);

            if (flags[s].first == 0) {
                flags[s].first = 1;
                flags[s].second = 'b';
            }
        }
        }
        if (100 - kol + skill >= 3) {
            RandomEllipse(flags);
        }

        kol += 3;
        Check(flags, skill);
        if (Finish(flags) || (kol - skill)>100) {
            MessageBox(hwnd, "You Lose", "Game Over", MB_OK);
            SendMessage(hwnd, WM_COMMAND, ID_RESET, 0);
        }
        InvalidateRect(hwnd, NULL, TRUE);
        }

    }
break;
    
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);



        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

        
        for (int i = 0; i <= 10; i++)
        {
            MoveToEx(hdc, 0, 100 * i, NULL);
            LineTo(hdc, 1000, 100 * i);
            MoveToEx(hdc, 100 * i, 0, NULL);
            LineTo(hdc, 100 * i, 1000);
        }
        InitCenter(center);
        HBRUSH hBrush;
        
        for (size_t i = 0; i < 100; i++)
        {
            if (flags[i].first == 1 && flags[i].second!='0') {
                if (flags[i].second == 'r') {
                    hBrush = CreateSolidBrush(color1);
                    SelectObject(hdc, hBrush);
                    Ellipse(hdc, center[i].first - 50, center[i].second - 50, center[i].first + 50, center[i].second + 50);
                }
                
                else if (flags[i].second == 'g') {
                    hBrush = CreateSolidBrush(color2);
                    SelectObject(hdc, hBrush);
                    Ellipse(hdc, center[i].first - 50, center[i].second - 50, center[i].first + 50, center[i].second + 50);
                }
                else if (flags[i].second == 'b') {
                    hBrush = CreateSolidBrush(color3);
                    SelectObject(hdc, hBrush);
                    Ellipse(hdc, center[i].first - 50, center[i].second - 50, center[i].first + 50, center[i].second + 50);
                }
               
            }
        }
        HPEN hPen = CreatePen(PS_SOLID, 4, RGB(0, 0, 0));
        char status[100];
        sprintf_s(status, "Количество шаров:%d, скилл:%d", kol, skill);
        TextOut(hdc, 1100, 500, status, 30);
        EndPaint(hwnd, &ps);
    }
    return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
void InitCenter(std::vector<std::pair<int,int>>& center) {

    for (int k = 0; k < 10; k++)
    {
        for (int i = 0; i < 10; i++)
        {
            center.push_back(std::make_pair(50 + (100 * k), 50 + (100 * i)));

        }
    }
}
int ChoosePole(int xPos, int yPos, std::vector<std::pair<int, int>>& center) {
    for (int i = 0; i < 100; i++)
    {
        if (xPos >= (center[i].first - 50) && xPos < (center[i].first + 50) && yPos <= (center[i].second + 50) && yPos >= (center[i].second - 50)) {
            return i;
        }

    }
    return -1;
}
void Check(std::vector<std::pair<int, char>>& flags,int& skill){
    int minv, maxv;
    //вертикальная проверка
    for (int i = 0; i < 100; i++)
    {
        if (flags[i].first == 1) {
            minv = i - i % 10;
            maxv = minv + 5;
            for (;minv  <= maxv; minv++)
            {
                if (flags[minv].first == flags[minv + 1].first && flags[minv + 1].first ==flags[minv + 2].first && flags[minv + 2].first == flags[minv + 3].first && flags[minv + 3].first == flags[minv + 4].first && flags[minv+4].first== 1) {
                    if (flags[minv].second == flags[minv + 1].second && flags[minv + 1].second == flags[minv + 2].second && flags[minv + 2].second == flags[minv + 3].second && flags[minv + 3].second == flags[minv + 4].second && flags[minv + 4].second) {
                    flags[minv].first = flags[minv+ 1].first = flags[minv + 2].first = flags[minv + 3].first = flags[minv + 4].first = 0;
                    skill += 5;
                }

                }
                
            }
        }
    }
    /*горизонтальная проверка*/
    int minh,maxh;
    for (size_t i = 0; i < 100; i++)
    {
        if (flags[i].first == 1) {
            minh = i;
            while (minh >= 10) {
                  minh -= 10;
            }
            maxh = minh + 50;
            for (; minh <=maxh; minh+=10)
            {
                if (flags[minh].first == flags[minh + 10].first && flags[minh + 10].first == flags[minh + 20].first && flags[minh + 20].first == flags[minh + 30].first && flags[minh + 30].first == flags[minh + 40].first && flags[minh + 40].first == 1) {
                    if (flags[minh].second == flags[minh + 10].second && flags[minh + 10].second == flags[minh + 20].second && flags[minh + 20].second == flags[minh + 30].second && flags[minh + 30].second == flags[minh + 40].second) {
                    flags[minh].first = flags[minh + 10].first = flags[minh + 20].first = flags[minh + 30].first = flags[minh + 40].first = 0;
                    skill+=5;
                    }

                }
            }
        }
    }
}

int Finish(std::vector<std::pair<int, char>>& flags) {
    for (size_t i = 0; i < 100; i++)
    {
        if (flags[i].first == 0) {
            return 0;
        }
    }
    return 1;
}

INT_PTR CALLBACK Dlg(HWND DLG, UINT message, WPARAM wParam, LPARAM lParam) {

    static CHOOSECOLOR cc;
    static COLORREF acrCustClr[16];
    switch (message)
    {
    case WM_INITDIALOG:
        SetDlgItemText(DLG, IDC_EDIT1, "0");
        SetDlgItemText(DLG, IDC_EDIT2, "0");
        break;
    case WM_CLOSE:
        EndDialog(DLG, 0);
        return 0;
    case WM_COMMAND:
        switch (LOWORD(wParam)) {

        case IDC_BUTTON1:

            ZeroMemory(&cc, sizeof(CHOOSECOLOR));
            cc.lStructSize = sizeof(CHOOSECOLOR);
            cc.hwndOwner = DLG;
            cc.lpCustColors = (LPDWORD)acrCustClr;
            cc.Flags = CC_FULLOPEN | CC_RGBINIT;

            if (ChooseColor(&cc) == TRUE) {
                color1 = cc.rgbResult;
            }
                break;
        case IDC_BUTTON2:

            
            ZeroMemory(&cc, sizeof(CHOOSECOLOR));
            cc.lStructSize = sizeof(CHOOSECOLOR);
            cc.hwndOwner = DLG;
            cc.lpCustColors = (LPDWORD)acrCustClr;
            cc.Flags = CC_FULLOPEN | CC_RGBINIT;

            if (ChooseColor(&cc) == TRUE) {
                color2 = cc.rgbResult;
            }
                break;
        case IDC_BUTTON3:
            
            ZeroMemory(&cc, sizeof(CHOOSECOLOR));
            cc.lStructSize = sizeof(CHOOSECOLOR);
            cc.hwndOwner = DLG;
            cc.lpCustColors = (LPDWORD)acrCustClr;
            cc.Flags = CC_FULLOPEN | CC_RGBINIT;

            if (ChooseColor(&cc) == TRUE) {
                color3 = cc.rgbResult;
            }
                break;
        case WM_CLOSE:
            EndDialog(DLG, 0);
            return 0;
        case IDOK:
        {
            TCHAR stroka[15];
            GetDlgItemText(DLG, IDC_EDIT1, stroka, sizeof(stroka));

            if (std::stoi(stroka) <= 0 && std::stoi(stroka) > 12) {
                SetDlgItemText(DLG, IDC_EDIT1, "Error");
            }
            else {
                width = std::stoi(stroka) * 1000;
                GetDlgItemText(DLG, IDC_EDIT2, stroka, sizeof(stroka));
                if (std::stoi(stroka) <= 0 && std::stoi(stroka) > 12) {
                    SetDlgItemText(DLG, IDC_EDIT2, "Error");
                }
                else {
                    EndDialog(DLG, 0);
                    InvalidateRect(DLG, NULL, TRUE);
                    return 0;
                }
            }
        }

        case IDCANCEL:
            EndDialog(DLG, 0);
            return 0;
        default:
            return 0;
        }
        return TRUE;
    default:
        return FALSE;
    }
}
void RandomEllipse(std::vector<std::pair<int, char>>&flags ) {
    int k = rand() % 100;
    if (flags[k].first == 1) {
        while (flags[k].first == 1) {
            k = rand() % 100;
        }
    }
    flags[k].first = 1;
    flags[k].second = 'r';

    k = rand() % 100;
    if (flags[k].first == 1) {
        while (flags[k].first == 1) {
            k = rand() % 100;
        }
    }
    flags[k].first = 1;
    flags[k].second = 'g';

    k = rand() % 100;
    if (flags[k].first == 1) {
        while (flags[k].first == 1) {
            k = rand() % 100;
        }
    }
    flags[k].first = 1;
    flags[k].second = 'b';
}
