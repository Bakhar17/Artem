// Asm.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
	{ // Task 3
	 //int res;//50=2x+3y task3
	 //__asm {
	 //	mov ebx, 0
	 //	mov ecx, 0
	 //	jmp start
	 //	start :
	 //	mov eax, 50
	 //	mov edx, ebx
	 //	imul edx, 3
	 //	sub eax, edx
	 //	cmp eax, 0
	 //	jl finish
	 //	test eax, 1
	 //	jz stop
	 //	add ebx, 1
	 //	jmp start
	 //	stop :
	 //	add ecx, 1
	 //	add ebx, 1
	 //	jmp start
	 //	finish :
	 //	mov res, ecx
	 //}
	 //std::cout << res;
	 //return 0;

	 /*int res = 0;
	 int i = 0;
	 do
	 {
		 __asm {
 start:
 mov ecx,res
 mov eax,50
 mov edx,i
 mov ebx,i
 imul ebx,3
 sub eax,ebx
 test eax,1
 jz stop
 add edx,1
 mov i,edx
 jmp start
 stop:
 add ecx,1
 add edx,1
 mov i,edx
 mov res,ecx

		 }
		 std::cout << i-1 << "\t";
	 } while (50-3*i>0);
	 std::cout <<"\n"<< res;*/


	 // task 4
		//int n = 0;
		//int a;
		//std::cin >> a;
		//__asm {

		//	mov ecx, 1
		//	mov eax, a
		//	mov edx, a
		//	jmp start
		//	start :
		//	mul edx
		//		add ecx, 1
		//		cmp eax, edx
		//		jl less
		//		jmp start
		//		less :
		//	mov n, ecx
		//		mov a, eax
		//}
		//std::cout << a << "\t" << n;

		//task 5
		std::cout << 0 << " ";
		int a = 1;
		int b = 1;
		do {
		__asm {
			mov eax,a
			mov ebx,b
			start:
			add eax, ebx
				mov a, eax
			cmp eax,0
			jl stop1
			add ebx, eax
			mov b, ebx
			cmp ebx,0
			jl stop2
			jmp end
			stop1:
			sub eax,ebx
			jmp end
			stop2:
			sub ebx,eax
			jmp end
			end:
			
		}
		std::cout << a<<" "<<b<<" ";
		}
while (a+b>0);

		system("pause");
		return 0;
	}
}
