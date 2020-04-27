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
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
std::vector<Participant> vec;

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow)
{
    // Register the window class.
    const wchar_t CLASS_NAME[] = L"Sample Window Class";

    WNDCLASS wc = { };

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, Dialog);
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
    static LOGFONT lf;
    static int xSize, ySize;
    RECT diagram,pie;
    diagram.left = 0;
    diagram.right = xSize / 2;
    diagram.bottom = ySize ;
    diagram.top = 0;
    pie.left = xSize/2;
    pie.top = 0;
    pie.right = xSize;
    pie.bottom = ySize;
    switch (uMsg)
    {
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
            } 
            // end of rectangle chart 


            // pie chart площадь сектора зависит от отношения рейтинга участника к сумме рейтингов всех участников 
            //установка центра окружности
            SetMapMode(hdc, MM_ANISOTROPIC);
            SetWindowExtEx(hdc, xSize, ySize, NULL);
            SetViewportExtEx(hdc, xSize, -ySize, NULL);
            SetViewportOrgEx(hdc, xSize / 2 + xSize / 4, ySize/2, NULL);
            //конец установки центра окружности 
            HBRUSH hBrush;
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
                    for (int i = 0; i <degree.size(); i++)
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

 
        EndPaint(hwnd, &ps);
    }
    return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

INT_PTR CALLBACK Dialog(HWND DLG, UINT message, WPARAM wParam, LPARAM lParam) {
    {
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
                            GetDlgItemText(DLG, IDC_EDIT4, sinput, sizeof(sinput));
                            red = _wtoi(sinput);
                        }

                        else if ((green < 0 || green>255)) {
                            SetDlgItemText(DLG, IDC_EDIT5, L"Error");
                            GetDlgItemText(DLG, IDC_EDIT5, sinput, sizeof(sinput));
                            green = _wtoi(sinput);
                        }

                        else if ((blue < 0 || blue>255)) {
                            SetDlgItemText(DLG, IDC_EDIT6, L"Error");
                            GetDlgItemText(DLG, IDC_EDIT6, sinput, sizeof(sinput));
                            blue = _wtoi(sinput);
                        }

                        else if ((n > 100 || n <= 0)) {
                        SetDlgItemText(DLG, IDC_EDIT2, L"Error");
                        GetDlgItemText(DLG, IDC_EDIT2, sinput, sizeof(sinput));
                        n = _wtof(sinput);
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
    }
}
