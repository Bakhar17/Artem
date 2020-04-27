#include <iostream>
#include "shared_ptr.h"
#include <memory>
#include <vector>
using std::shared_ptr;

SharedPtr<int> CheckMove();

int main()
{
    { int* a = new int(5);
   
    SharedPtr<int> ptra(a);// check copy construcor and increasing ref counter 
    {

        std::vector<SharedPtr<int>> res;
        res.push_back(ptra);
    }//check destructor( doesn't work because ref_counter != 0)
    } //check destructor (it works because ref_counter == 0)


    int* b = new int(8);
    SharedPtr<int> ptrb(b);
    int* a = new int(9);
    SharedPtr<int> ptra(a);
    ptra =ptrb; // operator = (ref_counter ++, ref_counter for obj a --)
                // also checking operator == for T objects
    

    //Checking move semantics
    SharedPtr<int> move = CheckMove();
    //function as operator ==, != checked by debugger 

    //Release 
    ptra.Release();
    system("pause");
    return 0;
}


SharedPtr<int> CheckMove() {
    int* move = new int(10);
    SharedPtr<int> temp(move);
    return temp;
}