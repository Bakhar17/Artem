// Зачет.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "Зачет.h"
#include <string>

#define MAX_LOADSTRING 100
#define BUTTON1 1001
#define BUTTON2 1002
#define BUTTON3 1003
// Глобальные переменные:

HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

extern "C" int _stdcall CharLength(const char*);
extern "C" int _fastcall LeftPos(const char*, const char*);
extern "C" int _fastcall RightPos(const char*, const char*);

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
    LoadStringW(hInstance, IDC_MY, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY);
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
    static HWND hButton1, hButton2, hButton3,hEdit1,hEdit2;
    int k;
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
            switch (wmId)
            {
            case BUTTON1:
            {
                std::string temp;
                SendMessage(hEdit1, EM_GETLINE, (WPARAM)0,(LPARAM)temp.c_str());
                const char* buf = temp.c_str();
                k = CharLength(buf);
                MessageBox(hWnd, std::to_string(k).c_str(), "Количество символов", MB_OK);

            }
             break;
            case BUTTON2:
            {
                std::string temp;
                SendMessage(hEdit1, EM_GETLINE, (WPARAM)0, (LPARAM)temp.c_str());
                const char* buf = temp.c_str();
                std::string temp1;
                SendMessage(hEdit2, EM_GETLINE, (WPARAM)0, (LPARAM)temp1.c_str());
                const char* buf1 = temp1.c_str();
                k=LeftPos(buf,buf1);
                MessageBox(hWnd, std::to_string(k).c_str(), "Позиция символа", MB_OK);
            }
            break;
            case BUTTON3:
            {
                std::string temp;
                SendMessage(hEdit1, EM_GETLINE, (WPARAM)0, (LPARAM)temp.c_str());
                const char* buf = temp.c_str();
                std::string temp2;
                SendMessage(hEdit2, EM_GETLINE, (WPARAM)0, (LPARAM)temp2.c_str());
                const char* buf2 = temp2.c_str();
                k = RightPos(buf, buf2);
                MessageBox(hWnd, std::to_string(k).c_str(), "Позиция символа", MB_OK);
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
    case WM_CREATE:
    {
        hEdit1 = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT,10, 35, 350, 25, hWnd, NULL, hInst, NULL);
        hEdit2 = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT, 10,70, 350, 25, hWnd, NULL, hInst, NULL);
        hButton1= CreateWindow("button", "Button1",
            WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON, 365, 30, 60, 25, hWnd, (HMENU)BUTTON1, hInst, NULL);
        hButton2 = CreateWindow("button", "Button2",
            WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON, 365,60, 60, 25, hWnd, (HMENU)BUTTON2, hInst, NULL);
        hButton2 = CreateWindow("button", "Button2",
            WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON, 365, 90, 60, 25, hWnd, (HMENU)BUTTON3, hInst, NULL);
    }
    break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
            EndPaint(hWnd, &ps);
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
