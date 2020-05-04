#ifndef UNICODE
#define UNICODE
#endif

#define _USE_MATH_DEFINES
#include <math.h>

#include <windows.h>
#include "Participant.h"
#include "resource.h"
#include <fstream>
#include <sstream>

INT_PTR CALLBACK Dialog(HWND DLG, UINT message, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK Dlg(HWND DLG, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
void ShowRate(HWND);
int CheckRect(int,int,LPARAM);
std::vector<Participant> vec;

HINSTANCE hDlg;
int flag=0;
int rect_pos=-1;
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow)
{
// Register the window class.
const wchar_t CLASS_NAME[] = L"Sample Window Class";

WNDCLASS wc = { };
wc.style = CS_DBLCLKS;
wc.lpfnWndProc = WindowProc;
wc.hInstance = hInstance;
wc.lpszClassName = CLASS_NAME;
wc.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, Dialog);
RegisterClass(&wc);
hDlg = hInstance;
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
    HMENU hMenu = GetMenu(hwnd);
    static LOGFONT lf;
    static int xSize, ySize, xPos, yPos;
    RECT diagram, pie;
    diagram.left = 0;
    diagram.right = xSize / 2;
    diagram.bottom = ySize;
    diagram.top = 0;
    pie.left = xSize / 2;
    pie.top = 0;
    pie.right = xSize;
    pie.bottom = ySize;
    switch (uMsg)
    {
    case WM_COMMAND:
    {
        switch (LOWORD(wParam))
        {
        case ID_FUNCTION_CHANGECOLOUR:
            flag = 1;
            DialogBox(hDlg, MAKEINTRESOURCE(IDD_DIALOG2), NULL, Dlg);
            InvalidateRect(hwnd, NULL, TRUE);
            break;
        case ID_FUNCTION_EXIT:
            PostQuitMessage(0);
            return 0;
        case ID_FUNCTION_CHANGERATING:
            flag = 2;
            DialogBox(hDlg, MAKEINTRESOURCE(IDD_DIALOG2), NULL, Dlg);
            InvalidateRect(hwnd, NULL, TRUE);
            break;
        case ID_FUNCTION_RATINGSTAT:
            ShowRate(hwnd);
            break;
        }
        return 0;
    }
    case WM_MOUSEMOVE:
        if (wParam & MK_LBUTTON)
        { 
            double rate;
            int xPos = LOWORD(lParam);
            int yPos = HIWORD(lParam);
            int i;
            for (i = 0; i < vec.size(); i++)
            {
                if (xPos <= (i + 1) * xSize / (2 * vec.size())) {
                    break;
                }
            }
            if (i != vec.size()) {
            yPos= HIWORD(lParam);
            rate = 100 * (ySize - yPos) * 4 / (3 * ySize);
            if (rate <= 100) {
            vec[i].SetRating(rate);
            InvalidateRect(hwnd, NULL, TRUE);
            }
            }
        }
        break;

    case WM_LBUTTONUP:
    {
            rect_pos = CheckRect(xSize, ySize, lParam);
            if (rect_pos != -1) {
                flag = 3;
                DialogBox(hDlg, MAKEINTRESOURCE(IDD_DIALOG2), NULL, Dlg);
                InvalidateRect(hwnd, NULL, TRUE);
            }
        break;
    }
    case WM_RBUTTONDOWN:
    {
        rect_pos = CheckRect(xSize, ySize, lParam);
        if (!(rect_pos == -1)) {
            flag = 4;
            DialogBox(hDlg, MAKEINTRESOURCE(IDD_DIALOG2), NULL, Dlg);
            InvalidateRect(hwnd, NULL, TRUE);
        }
        break;
    }
    case WM_LBUTTONDBLCLK:
    {
        rect_pos = CheckRect(xSize, ySize, lParam);
        if (rect_pos == -1) {
            ShowRate(hwnd);
        }

        break;
    }
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    case WM_SIZE:
        xSize = LOWORD(lParam);
        ySize = HIWORD(lParam);
        InvalidateRect(hwnd, NULL, 1);
        break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
        HBRUSH hBrush = CreateSolidBrush(RGB(220,220,220));
        FillRect(hdc, &diagram, hBrush);
        hBrush = CreateSolidBrush(RGB(255 ,228, 181));
        FillRect(hdc, &pie, hBrush);
        HPEN hPen = CreatePen(PS_SOLID, 5, RGB(0, 0, 0));
        SelectObject(hdc, hPen);
        MoveToEx(hdc, xSize / 2, 0, NULL);
        LineTo(hdc, xSize / 2, ySize);
        SetMapMode(hdc, MM_ANISOTROPIC);
        SetWindowExtEx(hdc, xSize, ySize, NULL);
        SetViewportExtEx(hdc, xSize, -ySize, NULL);
        SetViewportOrgEx(hdc, 0, ySize, NULL);
        if (vec.size()) {
            RECT rect;
            // rectangle chart
            //установка удобного центра
            SetMapMode(hdc, MM_ANISOTROPIC);
            SetWindowExtEx(hdc, xSize, ySize, NULL);
            SetViewportExtEx(hdc, xSize, -ySize, NULL);
            SetViewportOrgEx(hdc, 0, ySize, NULL);
            //конец установки удобного центра 
            for (int i = 0; i < vec.size(); i++)
            {
                Rectangle(hdc, i * xSize / (2 * vec.size()), (vec[i].GetRating() / 100) * 3 * ySize / 4, (i + 1) * xSize / (2 * vec.size()), 0);
                rect.left = i * xSize / (2 * vec.size());
                rect.top = (vec[i].GetRating() / 100) *3 * ySize /4;
                rect.right = (i + 1) * xSize / (2 * vec.size());
                rect.bottom = 0;
                hBrush = CreateSolidBrush(RGB(vec[i].GetRed(), vec[i].GetGreen(), vec[i].GetBlue()));
                FillRect(hdc, &rect, hBrush);
                std::wstring stemp = vec[i].GetName();
                LPCWSTR result = stemp.c_str();
                lf.lfCharSet = DEFAULT_CHARSET;
                lf.lfPitchAndFamily = DEFAULT_PITCH;
                lf.lfWeight = FW_BOLD;
                lf.lfEscapement = -900;
                HFONT hFontN1 = CreateFontIndirect(&lf);
                (HFONT)SelectObject(hdc, hFontN1);
                SetTextColor(hdc, RGB(vec[i].GetRed(), vec[i].GetGreen(), vec[i].GetBlue()));
                SetBkColor(hdc, RGB(220, 220, 220));
                TextOut(hdc, (i + 1) * xSize / (2 * vec.size()) - xSize / (3 * vec.size()), (vec[i].GetRating() / 100) * 3 * ySize / 4 +10, stemp.c_str(), stemp.size());
                std::wstringstream wss;
                wss << vec[i].GetRating();
                const std::wstring ws(wss.str());
                result = ws.c_str();
                lf.lfEscapement = 0;
                hFontN1 = CreateFontIndirect(&lf);
                (HFONT)SelectObject(hdc, hFontN1);
                TextOut(hdc, (i + 1) * xSize / (2 * vec.size()) - xSize / (4 * vec.size()), (vec[i].GetRating() / 100) * 3 * ySize / 4+30, ws.c_str(), ws.size());
                DeleteObject(hFontN1);
            } 
            // end of rectangle chart 


            // pie chart площадь сектора зависит от отношения рейтинга участника к сумме рейтингов всех участников 
            //установка центра окружности
            SetMapMode(hdc, MM_ANISOTROPIC);
            SetWindowExtEx(hdc, xSize, ySize, NULL);
            SetViewportExtEx(hdc, xSize, -ySize, NULL);
            SetViewportOrgEx(hdc, xSize / 2 + xSize / 4, ySize/2, NULL);
            //конец установки центра окружности 
            if (vec.size() == 1) {
                hBrush = CreateSolidBrush(RGB(vec[0].GetRed(), vec[0].GetGreen(), vec[0].GetBlue()));
                SelectObject(hdc, hBrush);
                Ellipse(hdc, -ySize / 4, ySize / 4, ySize / 4, -ySize / 4);
            }
            else {
                POINT start,finish;//точка, от которой считается угол поворота, и точка, до которой рисуется Pie
                int radius = ySize / 4;
                start.x = radius;
                start.y = 0;
            
                std::vector<double> degree;//вектор,который содержит углы отклонений
                double summa = 0;//суммарный рейтинг
                    for (int i = 0; i < vec.size(); i++)
                    {
                        summa += vec[i].GetRating();
                    }
                    for (int i = 0; i < vec.size(); i++)
                    {
                        degree.push_back(2 * M_PI * vec[i].GetRating() / summa);// соответствующий угол
                    }
                    summa = 0;
                    for (int i = 0; i < degree.size(); i++)
                    {
                        summa += degree[i];
                        finish.x = radius * cos(summa);
                        finish.y = radius * sin(summa);

                        hBrush = CreateSolidBrush(RGB(vec[i].GetRed(), vec[i].GetGreen(), vec[i].GetBlue()));
                        SelectObject(hdc, hBrush);
                        Pie(hdc, -radius, radius, radius, -radius, start.x, start.y, finish.x, finish.y);
                        start = finish;
                    }
             }
           
                //установка центра для вывода участников
                SetMapMode(hdc, MM_ANISOTROPIC);
                SetWindowExtEx(hdc, xSize, ySize, NULL);
                SetViewportExtEx(hdc, xSize, -ySize, NULL);
                SetViewportOrgEx(hdc, xSize / 2 , 0, NULL);
                //конец

                std::wstring res;
                int y=0;
                for (int i = 0; i < vec.size(); i++)
                {
                    res = vec[i].GetName() + L" ";
                    std::wstringstream wss;
                    wss << vec[i].GetRating();
                    const std::wstring ws(wss.str());
                    res += ws;
                    SetBkColor(hdc, RGB(255, 228, 181));
                    SetTextColor(hdc,RGB(vec[i].GetRed(), vec[i].GetGreen(), vec[i].GetBlue()));
                    TextOut(hdc, 10, y, res.c_str(), res.size());
                    y -= 20;
                }
        }
        DeleteObject(hBrush);
        ReleaseDC(hwnd, hdc);
        EndPaint(hwnd, &ps);
    }
    return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

INT_PTR CALLBACK Dialog(HWND DLG, UINT message, WPARAM wParam, LPARAM lParam) {
        switch (message)
        {
        case WM_CLOSE:
            EndDialog(DLG, 0);
            return 0;
        case WM_INITDIALOG://инициализация, здесь будут добавляться компоненты

            SetDlgItemText(DLG, IDC_EDIT1, L"Enter name");
            SetDlgItemText(DLG, IDC_EDIT2, L"Enter rating");
            SetDlgItemText(DLG, IDC_MY_TEXT, L"Set colour(RGB SYSTEM)");
            SetDlgItemText(DLG, IDC_EDIT4, L"0");
            SetDlgItemText(DLG, IDC_EDIT5, L"0");
            SetDlgItemText(DLG, IDC_EDIT6, L"0");
            break;
        case WM_COMMAND:
        {
            switch (LOWORD(wParam))
            {
            case IDADD:
            {
                wchar_t txt[100];
                GetDlgItemText(DLG, IDC_EDIT1, txt, sizeof(txt));
                std::wstring ws(txt);
                std::wstring name(ws.begin(), ws.end());
                TCHAR sinput[15];
                GetDlgItemText(DLG, IDC_EDIT2, sinput, sizeof(sinput));
                double n;
                n = _wtof(sinput);
                int red, green, blue;
                GetDlgItemText(DLG, IDC_EDIT4, sinput, sizeof(sinput));
                red = _wtoi(sinput);

                GetDlgItemText(DLG, IDC_EDIT5, sinput, sizeof(sinput));
                green = _wtoi(sinput);

                GetDlgItemText(DLG, IDC_EDIT6, sinput, sizeof(sinput));
                blue = _wtoi(sinput);
                        if ((red < 0 || red>255)) {
                            SetDlgItemText(DLG, IDC_EDIT4, L"Error");
                        }

                        else if ((green < 0 || green>255)) {
                            SetDlgItemText(DLG, IDC_EDIT5, L"Error");
                        }

                        else if ((blue < 0 || blue>255)) {
                            SetDlgItemText(DLG, IDC_EDIT6, L"Error");
                        }

                        else if ((n > 100 || n <= 0)) {
                        SetDlgItemText(DLG, IDC_EDIT2, L"Error");
                        }
                        else {
                        vec.push_back(Participant(name, n,red,green,blue));
                        SetDlgItemText(DLG, IDC_EDIT1, L"Enter name");
                        SetDlgItemText(DLG, IDC_EDIT2, L"Enter rating");
                        SetDlgItemText(DLG, IDC_EDIT4, L"0");
                        SetDlgItemText(DLG, IDC_EDIT5, L"0");
                        SetDlgItemText(DLG, IDC_EDIT6, L"0");
                        }
                 break;
            }
            case IDFINISH:
            {
                EndDialog(DLG, LOWORD(wParam));
                return (INT_PTR)TRUE;
            }  
            }
        }
        return TRUE;

        default:
            return FALSE;
        }
        return FALSE;
}
INT_PTR CALLBACK Dlg(HWND DLG, UINT message, WPARAM wParam, LPARAM lParam) {
    int n;
    switch (message)
    {
    case WM_CLOSE:
        EndDialog(DLG, 0);
        return 0;
    case WM_INITDIALOG://инициализация, здесь будут добавляться компоненты
    {
        
        SetDlgItemText(DLG, IDC_STATIC_LIST, L"Choose a participant");
        switch (flag)
        {
        case 1:

            ShowWindow(GetDlgItem(DLG, IDC_STATIC_COLOUR), SW_HIDE);
            SetDlgItemText(DLG, IDC_STATIC_RGB, L"RGB system");
            SetDlgItemText(DLG, IDC_EDIT1, L"0");
            SetDlgItemText(DLG, IDC_EDIT2, L"0");
            SetDlgItemText(DLG, IDC_EDIT3, L"0");
            for (int i = 0; i < vec.size(); i++)
            {
                SendDlgItemMessage(DLG, IDC_COMBO2, CB_ADDSTRING, 0, (LPARAM)(LPWSTR)vec[i].GetName().c_str());
            }
            break;

        case 2: 
           ShowWindow(GetDlgItem(DLG, IDC_STATIC_COLOUR), SW_HIDE);
           SetDlgItemText(DLG, IDC_STATIC_RGB, L"New Rating");
           SetDlgItemText(DLG, IDC_EDIT1, L"0");
           ShowWindow(GetDlgItem(DLG, IDC_EDIT2), SW_HIDE);
           ShowWindow(GetDlgItem(DLG, IDC_EDIT3), SW_HIDE);
           for (int i = 0; i < vec.size(); i++)
           {
               SendDlgItemMessage(DLG, IDC_COMBO2, CB_ADDSTRING, 0, (LPARAM)(LPWSTR)vec[i].GetName().c_str());
           }
           break;
        case 3:
            SetDlgItemText(DLG, IDC_STATIC_COLOUR, vec[rect_pos].GetName().c_str());
            SetDlgItemText(DLG, IDC_STATIC_RGB, L"RGB system");
            SetDlgItemText(DLG, IDC_EDIT1, L"0");
            SetDlgItemText(DLG, IDC_EDIT2, L"0");
            SetDlgItemText(DLG, IDC_EDIT3, L"0");
            break;
        case 4:
            SetDlgItemText(DLG, IDC_STATIC_COLOUR, vec[rect_pos].GetName().c_str());
            SetDlgItemText(DLG, IDC_STATIC_RGB, L"New Rating");
            ShowWindow(GetDlgItem(DLG, IDC_EDIT3), SW_HIDE);
            ShowWindow(GetDlgItem(DLG, IDC_EDIT2), SW_HIDE);
            SetDlgItemText(DLG, IDC_EDIT1, L"0");
            break;
        }  

    }
    case WM_COMMAND:
        switch (LOWORD(wParam)) {
            case IDC_UPDATE:
                n=SendDlgItemMessage(DLG, IDC_COMBO2,CB_GETCURSEL, 0, 0L);

                switch (flag)
                {
                case 3:
                {   TCHAR sinput[15];
                int red, green, blue;
                GetDlgItemText(DLG, IDC_EDIT1, sinput, sizeof(sinput));
                red = _wtoi(sinput);
                GetDlgItemText(DLG, IDC_EDIT2, sinput, sizeof(sinput));
                green = _wtoi(sinput);
                GetDlgItemText(DLG, IDC_EDIT3, sinput, sizeof(sinput));
                blue = _wtoi(sinput);

                if ((red < 0 || red>255)) {
                    SetDlgItemText(DLG, IDC_EDIT1, L"Error");
                }

                else if ((green < 0 || green>255)) {
                    SetDlgItemText(DLG, IDC_EDIT2, L"Error");
                }

                else if ((blue < 0 || blue>255)) {
                    SetDlgItemText(DLG, IDC_EDIT3, L"Error");
                }
                else {
                    vec[rect_pos].SetRed(red);
                    vec[rect_pos].SetGreen(green);
                    vec[rect_pos].SetBlue(blue);
                    EndDialog(DLG, 0);
                    return 0;
                }
                break;
                }
                case 1: {
                    if (n == -1) {
                        EndDialog(DLG, 0);
                        return 0;
                    }
                    TCHAR sinput[15];
                    int red, green, blue;
                    GetDlgItemText(DLG, IDC_EDIT1, sinput, sizeof(sinput));
                    red = _wtoi(sinput);
                    GetDlgItemText(DLG, IDC_EDIT2, sinput, sizeof(sinput));
                    green = _wtoi(sinput);
                    GetDlgItemText(DLG, IDC_EDIT3, sinput, sizeof(sinput));
                    blue = _wtoi(sinput);

                    if ((red < 0 || red>255)) {
                        SetDlgItemText(DLG, IDC_EDIT1, L"Error");
                    }

                    else if ((green < 0 || green>255)) {
                        SetDlgItemText(DLG, IDC_EDIT2, L"Error");
                    }

                    else if ((blue < 0 || blue>255)) {
                        SetDlgItemText(DLG, IDC_EDIT3, L"Error");
                    }
                    else {
                        vec[n].SetRed(red);
                        vec[n].SetGreen(green);
                        vec[n].SetBlue(blue);
                        EndDialog(DLG, 0);
                        return 0;
                    }
                    break;
                }
                case 2:
                {
                    if (n == -1) {
                        EndDialog(DLG, 0);
                        return 0;
                    }
                    double rate;
                    TCHAR sinput[15];
                    GetDlgItemText(DLG, IDC_EDIT1, sinput, sizeof(sinput));
                    rate = _wtof(sinput);
                    if (rate <= 0 || rate > 100) {
                        SetDlgItemText(DLG, IDC_EDIT1, L"Error");
                    }
                    else 
                    {
                        vec[n].SetRating(rate);
                        EndDialog(DLG, 0);
                        return 0;
                    }
                    break;
                }  
                case 4:
                    double rate;
                    TCHAR sinput[15];
                    GetDlgItemText(DLG, IDC_EDIT1, sinput, sizeof(sinput));
                    rate = _wtof(sinput);
                    if (rate <= 0 || rate > 100) {
                        SetDlgItemText(DLG, IDC_EDIT1, L"Error");
                    }
                    else
                    {
                        vec[rect_pos].SetRating(rate);
                        EndDialog(DLG, 0);
                        return 0;
                    }
                    break;
                }
                break;
            case WM_CLOSE:
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

int CheckRect(int xSize,int ySize,LPARAM lParam) {
    int xPos = LOWORD(lParam);
    int yPos = HIWORD(lParam);
    for (int i = 0; i < vec.size(); i++)
    {
        if (xPos <= (i + 1) * xSize / (2 * vec.size())) {
            if (yPos >= ySize - (vec[i].GetRating() / 100) * 3 * ySize / 4) {
                return i;
            }
        }
    }
    return -1;
}

void ShowRate(HWND hwnd) {
    std::wstring stroka;
    for (int i = 0; i < vec.size(); i++)
    {
        stroka += vec[i].GetName();
        stroka += L" ";
        std::wstringstream wss;
        wss << vec[i].GetRating();
        const std::wstring ws(wss.str());
        stroka += ws;
        stroka += L"\n";
    }
    MessageBox(hwnd, stroka.c_str(), L"Rating", MB_OK);
}