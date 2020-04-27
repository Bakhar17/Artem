#define _USE_MATH_DEFINES // for C++
#include <iostream>
#include <cmath>
extern "C" double* _stdcall Ln2(int&,int&,int&);
int main()
{
    int k5=0;
    int k7=0;
    int k9=0;
    std::cout << *Ln2(k5,k7,k9);
    std::cout << "\n" << M_LN2;
    std::cout << "\n" << k5;
    system("pause");
    return 0;
}

