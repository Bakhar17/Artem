#include <iostream>
extern "C" float* _stdcall SinX(float x);


int main()
{
    float x = 6;
    std::cout << x << "\n";
    x = *(SinX(x));
    std::cout << x << "\n";

    std::cout << "Hello World!\n";
}