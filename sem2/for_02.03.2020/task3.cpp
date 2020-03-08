#include <iostream>
void SortArray(int*, int);//sort array
int FindMax(int*,int);//return max position in array with the address offset
void Swipe(int*,int );// swipe max position with the first(considering the address offset)
int DiffNum(int*,int);//return the number of different numbers
int OftenUse(int*,int);//return the most used number

//task 3, Artem Bakhar, group 4
                       
    int main()
{
    std::cout << "Put the size: ";
    int size;
    std::cin >> size;
    int* array = new int[size];
    for (int i = 0; i < size; i++)
    {
        std::cin >> array[i];
    }
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i]<<"\t";
    }
    SortArray(array, size);
    std::cout<<"\nDifferent numbers: "<<DiffNum(array, size);
    std::cout << "\nMore usable: " << OftenUse(array, size);
    system("pause");
    return 0;
}

    void SortArray(int* darr, int size_) {
        while (size_) {
            int pos = FindMax(darr, size_);
            Swipe(darr, pos);
            darr=darr+1;
            size_--;
        }
    }; 
    int FindMax(int* darr, int size_) {
        int pos;
        __asm {       
            mov ebx, 0
            mov edx, 0
            mov esi, darr
            mov eax, [esi]
            mov ecx, size_
            cmp ecx,1
            je end
            sub ecx,1
            start :
            add esi, 4
                inc ebx
                cmp eax, [esi]
                jl less
                jg cont
                less :
            mov eax, [esi]
                mov edx, ebx
                cont :
            loop start
                end:
                mov pos, edx
        }
        return pos;
    };
    void Swipe(int* darr, int pos) {
        __asm {
            mov esi, darr
            mov edx, pos
            imul edx,4
            mov eax,[esi]
            mov ebx,[esi][edx]
            mov ecx,eax
            mov [esi],ebx
            mov [esi][edx],ecx
        }
    }
    int DiffNum(int* darr, int size_) {
        
        int num;
        __asm {
            mov esi,darr
            mov ecx,size_
            xor eax,eax
            mov ebx,1
            dec ecx
                start:
            mov eax,[esi]
            cmp eax,[esi+4]
            je skip
            inc ebx
                skip:
            add esi,4
            loop start
            mov num,ebx
        }
        return num;
    }
    int OftenUse(int* darr, int size_) {
        int num = DiffNum(darr, size_);
        int* temp = new int[2 * num];//extra array where first half is different numbers and second half is counts of different numbers 
        __asm {
            mov esi,darr
            mov edx,temp
            mov ecx,size_
            mov ebx,1
            mov edi,num
            dec ecx
                start:
            mov eax,[esi]
            cmp eax,[esi+4]
            je cont
            mov [edx],eax
            mov [edx][edi*4],ebx
            add edx,4
            xor ebx,ebx
                cont:
            add esi,4
            add ebx,1
            cmp ecx,1
            je adder
            jmp skip
                adder:
            mov eax, [esi]
            mov[edx], eax
            mov[edx][edi * 4], ebx
                skip:
            loop start
        }
        std::cout << "\n";
        for (int i = 0; i < 2*num; i++)
        {
            std::cout << temp[i] << "\t";
        }
        int res= temp[FindMax(temp+num, num)];
        delete[]temp;
        return res;
    }