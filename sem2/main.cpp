#include <iostream>
int main()
{
    int arr[5][5];
    int sr = 1;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            arr[i][j] = sr;
            sr++;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        std::cout << "\n";
        for (int j = 0; j < 5; j++)
        {
            std::cout << arr[i][j] << "\t";
        }
    }
    std::cout << "\nPut the line: ";
    int k;
    std::cin >> k;
    __asm {
    lea edi, arr
    mov ebx, k
    dec ebx
    imul ebx, 20
    mov esi, k
    dec esi
    imul esi, 4
    mov ecx, 5
    xor eax, eax
    xor ebp, ebp
    start :
    mov eax, [edi][ebx]
    mov ebp, [edi][esi]
    mov[edi][ebx], ebp
    mov[edi][esi], eax
    add edx, 20
    add ebx, 4
    loop start
    }
    for (int j = 0; j < 5; j++)
    {
        std::cout << "\n";
        for (int s = 0; s < 5; s++)
        {
            std::cout << arr[j][s] << "\t";
        }
    }
    system("pause");
    return 0;
}