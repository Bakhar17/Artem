#include <iostream>
extern "C" float* __stdcall CalculateSqrt(int N, float* A);
//extern "C" void __stdcall CreateVectorB(unsingned int A[][M], int N, int M, int* B);

float* CalculateSqrtVstavka(int N, float* A);


int main()
{
    float* x =new float(2.5);
    float* y = new float(4.2);
    std::cout <<"Sqrt of x: "<< *CalculateSqrt(5, x)<<"\n";
    std::cout << "Sqrt of y(__asm): " << *CalculateSqrtVstavka(5, y)<<"\n";

    std::cout <<"Module of differences for first program: "<< *x<<"\n";
    std::cout <<"Module of differences for second program: "<< *y<<"\n";

}


float* CalculateSqrtVstavka(int N, float* A) {
    int numberofiter = N;
    float* reftofloat = A;
    float x;
    float zero = 0;
    float res;
    float del = 2;
    __asm {
        mov edx, reftofloat
        mov ecx, N
        finit
        fld dword ptr[edx]
        fstp x

        cycle :
        fld res
            fmul zero
            fstp res


            fld x
            fdiv del
            fadd res
            fstp res

            fld dword ptr[edx]
            fdiv del
            fdiv x
            fadd res
            fstp res
            fld res
            fstp x
            loop cycle

            fld dword ptr[edx]
            fsqrt
            fst st(1)
            fld res
            fsub
            fabs
            fstp dword ptr[edx]
            mov reftofloat, edx

            finish :
        lea eax, res
    }
}