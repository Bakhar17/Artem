#include <iostream>
#include "container.h"
BiDirectionalList<int> CheckMove(int a, int b) {
    BiDirectionalList<int> Move;
    Move.PushBack(a);
    Move.PushFront(b);
    return Move;
}
int main()
{
    BiDirectionalList<int> Test;
    std::cout << "Size: " << Test.Size() << "\tIsEmpty: " << Test.IsEmpty()<<"\n";
    Test.PushBack(10);
    Test.PushFront(2);
    std::cout << "Size: " << Test.Size() << "\tIsEmpty: " << Test.IsEmpty()<<"\n";

    Test.PushBack(14);
    Test.PushFront(34);
    Test.Erase(Test.Front());
    for (int i = 0; i < Test.Size(); i++)
    {
        std::cout << Test[i] << "\t";
    }
   
    Test.Erase(Test.Back());
    std::cout << "\n";
    for (int i = 0; i < Test.Size(); i++)
    {
        std::cout << Test[i] << "\t";
    }
    
    BiDirectionalList<int> Test2 = { 15,48,65,20,0 };
    BiDirectionalList<int> Test3(Test);
    std::cout << "\n" << "Test != Test2: " << (Test == Test2) << "\tTest!=Test3: " << (Test != Test3) << "\n";
    Test3 = Test2;
    
    std::cout << "Test3 == Test2: " << (Test3 == Test2)<<"\n";
    Test3.InsertAfter(2, 5);
    Test3.InsertBefore(5, 3);
    for (int i = 0; i < Test3.Size(); i++)
    {
        std::cout << Test3[i] << "\t";
    }
   
    std::cout << "\nToVector():\n";
    std::vector<int> vec = Test.ToVector();
    for (auto& i : vec)
    {
        std::cout << i<<"\t";
    }
    BiDirectionalList<int> Test4 = { 1,5,1,1,35,3,93,15,1 };
    std::cout << "\n";
    vec = Test4.FindAll(1);
    for (auto& i : vec)
    {
        std::cout << i << "\t";
    }
 
    Test4 = CheckMove(5, 2);
    std::cout << "\n";
    for (int i = 0; i < Test4.Size(); i++)
    {
        std::cout << Test4[i] << "\t";
    }

    std::cout << "\n Pop:\n";
    Test2.PopBack();
    Test2.PopFront();
    for (int i = 0; i < Test2.Size(); i++)
    {
        std::cout << Test2[i] << "\t";
    }
    system("pause");
    return 0;
}

