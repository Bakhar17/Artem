// SP(for 14.04).cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "SP(for 14.04).h"
#include <commdlg.h>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <sstream>

#define MAX_LOADSTRING 100
#define ID_LIST 1          

std::set<char> SymCount(const char*);
std::set<int> WordCount(const char*);
std::vector<std::pair<char, int>> PairACount(const char* stroka, std::set<char>& sym);
std::vector<std::pair<int, int>> PairBCount(const char* stroka, std::set<int>& words);
// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{

    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_SPFOR1404, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_SPFOR1404));

    MSG msg;
    
    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SPFOR1404));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_SPFOR1404);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    std::set<int> words;
    std::set<char> symbols;
    static std::vector<std::pair<char, int>> resultA;
    static std::vector<std::pair<int, int>> resultB;
    std::ifstream fin("Text.txt");
    static HWND hListBox;
    static int xSize, ySize;
    switch (message)
    {
    case WM_SIZE:
    {
        xSize = LOWORD(lParam);
        ySize = HIWORD(lParam);
        SetWindowPos(hListBox,0, xSize / 2 - xSize / 8, 0, xSize / 4, ySize / 4, SWP_NOACTIVATE);
        InvalidateRect(hWnd, NULL, TRUE);
        break;
    }
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
            switch (wmId)
            {
            case ID_LIST:
            {
                switch (HIWORD(wParam))
                {
                case LBN_SELCHANGE:
                {
                    if (hListBox != NULL) {
                    int item = (int)SendMessage(hListBox, LB_GETCURSEL, 0, 0L);
                    if (item != LB_ERR)
                    {
                        CHAR temp[256];
                        SendMessage(hListBox, LB_GETTEXT, item, (LPARAM)temp);
                        MessageBox(hWnd, temp, "Выбранная строка", MB_OK);
                        symbols = SymCount(temp);
                        resultA = PairACount(temp, symbols);
                        words = WordCount(temp);
                        resultB = PairBCount(temp, words);
                        InvalidateRect(hWnd, NULL, TRUE);
                    }
                    }
                        break;
                }
             }
                   
            }
            break;
            
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            HBRUSH hBrush = CreateSolidBrush(RGB(248, 248, 255));
            FillRect(hdc, &ps.rcPaint, hBrush);
            MoveToEx(hdc, 0, ySize / 4, NULL);
            LineTo(hdc, xSize, ySize / 4);
            MoveToEx(hdc, xSize/2, ySize / 4, NULL);
            LineTo(hdc, xSize/2, ySize );
            RECT rect;

            //part A

            //установка удобного центра
            SetMapMode(hdc, MM_ANISOTROPIC);
            SetWindowExtEx(hdc, xSize, ySize, NULL);
            SetViewportExtEx(hdc, xSize, -ySize, NULL);
            SetViewportOrgEx(hdc, 0, ySize, NULL);
            //конец установки удобного центра 

            if (resultA.size()!=0)
            {
                HPEN hPen = CreatePen(PS_SOLID, 4, RGB(0, 0, 0));
                SelectObject(hdc, hPen);
                hBrush = CreateSolidBrush(RGB(253, 245, 230));
                int sum = 0;
                for (size_t i = 0; i < resultA.size(); i++)
                {
                    sum += resultA[i].second;
                }

                for (size_t i = 0; i < resultA.size(); i++)
                {
                    std::string buf;
                    rect.left = 1;
                    rect.top = (i + 1) * 3*ySize / (4 * resultA.size());
                    rect.right = resultA[i].second * xSize/20;
                    rect.bottom = i* 3 * ySize / (4 * resultA.size());
                    Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
                    
                    FillRect(hdc, &rect, hBrush);
                    buf += resultA[i].first;
                    buf += ", ";
                    buf += std::to_string(resultA[i].second);
                    SetBkColor(hdc, RGB(253, 245, 230));
                    TextOut(hdc, resultA[i].second * xSize / 40, (i + 1) * 3 * ySize / (8 * resultA.size())+ (i ) * 3 * ySize / (8 * resultA.size()),buf.c_str(), buf.size());
                }
            }
            //end of part A

            //part B

            //установка удобного центра
            SetMapMode(hdc, MM_ANISOTROPIC);
            SetWindowExtEx(hdc, xSize, ySize, NULL);
            SetViewportExtEx(hdc, xSize, -ySize, NULL);
            SetViewportOrgEx(hdc, xSize/2, ySize, NULL);
            //конец установки удобного центра 

            if (resultB.size() != 0)
            {
                HPEN hPen = CreatePen(PS_SOLID, 4, RGB(0, 0, 0));
                SelectObject(hdc, hPen);
                hBrush = CreateSolidBrush(RGB(253, 245, 230));
                for (size_t i = 0; i < resultB.size(); i++)
                {
                    std::string buf;
                    rect.left = 1;
                    rect.top = (i + 1) * 3 * ySize / (4 * resultB.size());
                    rect.right = resultB[i].second * xSize / 8;
                    rect.bottom = i * 3 * ySize / (4 * resultB.size());
                    Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);

                    FillRect(hdc, &rect, hBrush);
                    buf += std::to_string(resultB[i].first);
                    buf += " symbols, ";
                    buf += std::to_string(resultB[i].second);
                    SetBkColor(hdc, RGB(253, 245, 230));
                    TextOut(hdc, resultB[i].second * xSize / 16, (i + 1) * 3 * ySize / (8 * resultB.size()) + (i) * 3 * ySize / (8 * resultB.size()), buf.c_str(), buf.size());
                }
            }
            DeleteObject(hBrush);
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_CREATE:
        {
        hListBox = CreateWindow("listbox", NULL,
            WS_CHILD | WS_VISIBLE | LBS_NOTIFY | WS_BORDER| WS_VSCROLL |
            LBS_WANTKEYBOARDINPUT,50, 50, 350, 100, hWnd, (HMENU)ID_LIST, hInst, NULL);
        if (fin.is_open()) {
            std::string text;
            while (!fin.eof()) {
                getline(fin, text);
                SendMessage(hListBox, LB_ADDSTRING, 0,(LPARAM)text.c_str());
            }
        }
        }
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

std::set<char> SymCount(const char* stroka) {
    std::set<char> sym;
    int i = 0;
    while (stroka[i] != '\0') {
        if (stroka[i] == ' ') {
            i++;
            continue;
        }
        sym.insert(stroka[i]);
        i++;
    }
    return sym;
}
std::vector<std::pair<char, int>> PairACount(const char* stroka, std::set<char>& sym){

    std::vector<std::pair<char, int>> temp;
    std::for_each(sym.begin(), sym.end(), [&stroka,&temp](char a) {
        int count = 0;
        int k = 0;
        while (stroka[k] != '\0') {
            if (a == stroka[k]) {
                count++;
            }
            k++;
        }
        temp.push_back(std::make_pair(a, count));
        });
    return temp;
}

std::vector<std::pair<int, int>> PairBCount(const char* stroka, std::set<int>& words) {
    std::vector<std::pair<int, int>> temp;
    
    std::for_each(words.begin(), words.end(), [&stroka, &temp](int word) {
        int count = 0;
        std::stringstream stroka_(stroka);
        while (!stroka_.eof()) {
            std::string tmp;
            stroka_ >> tmp;
            if (tmp.length() == word) count++;
        }
        temp.push_back(std::make_pair(word, count));
        });
    return temp;
}
std::set<int> WordCount(const char* stroka){
    std::set<int> words;
    std::stringstream str(stroka);
    std::string str1;
    while (!str.eof()) {
        str >> str1;
        words.insert(str1.length());
    }
    return words;
}