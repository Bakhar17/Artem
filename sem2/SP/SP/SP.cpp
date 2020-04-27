#include <iostream>
extern "C" int _stdcall CharLength(const char*);//task 1
extern "C" int _fastcall LeftPos(const char*, const char*);//task 2
extern "C" int _fastcall RightPos(const char*, const char*);//task 3
extern "C" void _cdecl PodStroka(const char*, int, int);//task 4 (first int for pos, second int for size) 

int main()
{
    char stroka[50];
    std::cout << "Put the string: ";
    std::cin.getline(stroka, 50);
    std::cout << "Length of the string: " << CharLength(stroka);
    std::cout << "\nPut the char: ";
    char symbol;
    std::cin.get(symbol);
    std::cout << "Check LeftPos: " << LeftPos(stroka, &symbol);
    std::cout << "\nPut new symbol: ";
    char symbol2;
    std::cin.ignore();
    std::cin.get(symbol2);
    std::cout << "Check RightPos: " << RightPos(stroka, &symbol2) << "\n";
    std::cout << "Check PodStroka: ";
    PodStroka(stroka, 3, 6);
    std::cout << stroka << "\n";
    system("pause");
    return 0;
}


// Экземпляры старых функций, решил не удалять.
//int CharLength (const char* stroka) {
//    int dlina=0;
//    __asm {
//        mov eax,dlina
//        mov esi,stroka
//        mov bh,'\0'
//    start:
//        mov bl,[esi]
//        cmp bl,bh
//        je finish
//        inc eax
//        add esi,1
//        jmp start
//
//        finish:
//        mov dlina,eax
//    }
//    return dlina;
//}

//int LeftPos(const char* stroka, char symbol) {
//    int pos = -1;
//    int dlina = CharLength(stroka);
//    __asm {
//        mov eax,0
//        mov esi,stroka
//        mov bh,symbol
//        mov ecx, dlina
//        dec ecx
//
//            start:
//        mov bl,[esi]
//        cmp bl,bh
//        je ChangePos
//        inc eax
//        add esi,1
//        loop start
//        jmp finish
//            ChangePos:
//        mov pos,eax
//            finish:
//    }
//    return pos;
//}

//int RightPos(const char* stroka,const char* symbol) {
//    int pos = -1;
//    int dlina = CharLength(stroka);
//    __asm {
//        mov eax,0
//        mov esi,stroka
//        mov ecx,dlina
//        add esi,ecx
//        dec esi
//        mov bh,[symbol]
//
//            start:
//        mov bl,[esi]
//        cmp bl,bh
//        je ChangerPos
//        dec esi
//        inc eax
//        loop start
//        jmp finish
//
//            ChangerPos:
//        mov pos,eax
//            finish:
//
//    }
//    return pos;
//}