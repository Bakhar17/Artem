#include <iostream>
#include <cmath>
int main()
{
    ////task 1: Quadratic equation
    //std::cout << "Quadratic equation\n";
    //std::cout << "Put a: ";
    //float a;
    //std::cin >> a;
    //std::cout << "Put b: ";
    //float b;
    //std::cin >> b;
    //std::cout << "Put c: ";
    //float c;
    //std::cin >> c;
    //float res = -4;
    //float koren1=0;
    //float koren2=0;
    //__asm {
    //    finit
    //    FLD b
    //    FST st(1)
    //    FMUL
    //    FST ST(1)
    //    FLD a
    //    FST ST(1)
    //    FLD c
    //    FMUL
    //    FMUL res
    //    FADD ST(0), ST(2)
    //    FSTP res
    //    FLD res
    //    FTST
    //    FSTSW AX
    //    SAHF
    //    JA step2
    //    JZ step1
    //step2: //2 decisions 
    //    FLD a
    //    FST ST(1)
    //    FADD 
    //    FST ST(1)
    //    FLD b
    //    FCHS
    //    FST ST(1)
    //    FLD res
    //    FSQRT
    //    FADD
    //    FDIV ST,ST(2)
    //    FSTP koren1
    //    FLD a
    //    FST ST(1)
    //    FADD
    //    FST ST(1)
    //    FLD res
    //    FSQRT 
    //    FCHS
    //    FST ST(1)
    //    FLD b
    //    FCHS
    //    FADD
    //    FDIV ST,ST(2)
    //    FSTP koren2
    //    jmp finish
    //step1:// 1 decision
    //    FLD a
    //    FST ST(1)
    //    FLD a
    //    FADD ST,ST(1)
    //    FST ST(1)
    //    FLD b
    //    FCHS
    //    FDIV ST,ST(1)
    //    FSTP koren1
    //    jmp finish
    //finish:
    //}
    //if (res > 0) {
    //    std::cout << "\nKOREN1: " << koren1
    //              << "\nKOREN2: " << koren2<<"\n";
    //}
    //else if (res == 0|| abs(res) < 0.0001) {//extra check because of translation discrepancies in 2SS
    //    __asm {
    //        FLD a
    //        FST ST(1)
    //        FADD ST(0),ST(1)
    //        FST ST(1)
    //        FLD b
    //        FCHS
    //        FDIV ST(0),ST(1)
    //        FSTP koren1
    //    }
    //    std::cout << "\nKOREN: " << koren1 << "\n";
    //}
    //else
    //{
    //    std::cout << "\nComplex roots!\n";
    //}

    //task 2: a^x
    std::cout << "a^x";
    float a;
    std::cout << "\nPut a: ";
    std::cin >> a;
    float x;
    std::cout << "Put x: ";
    std::cin >> x;
    float x2;
    float res;
    if (a > 0) {
    __asm {
        finit
        FLD x
        FST ST(1)
        FLD a
        FYL2X
        FST ST(1)
        FRNDINT
        FCOM ST(1)
        FSTSW AX
        SAHF
    ja reverse
        FSUB
        FSTP x2//нахождение дробной части(в зависимости от округления степени)
    jmp next_step
    reverse:
        FSUB
        FST ST(1)
        FLD1
        FADD
        FSTP x2//нахождение дробной части
    next_step:
        FLD x
        FST ST(1)
        FLD a
        FYL2X
        FST ST(1)
        FLD x2
        FSUB
        FSTP x//целая часть степени
    
        FLD x
        FST ST(1)
        FLD1 
        FSCALE
        FSTP x// 2 в целой части степени

        FLD x2
        F2XM1
        FST ST(1)
        FLD1
        FADD
        FSTP x2//2 в дробной части степени

        FLD x2
        FST ST(1)
        FLD x
        FMUL 
        FSTP res// их произведение и ответ.
    }
    std::cout << x;
    std::cout << "\n" << x2 << "\n";
    std::cout << "Finally: " << res;
    }

    system("pause");
    return 0;
}