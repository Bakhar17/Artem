#include <iostream>

int main()
{
	//int a, b,res;
	//std::cout << "Put a: ";
	//std::cin >> a;
	//std::cout << "Put b: ";
	//std::cin >> b;
	//__asm {
	//	mov eax, b
	//	neg eax
	//	cdq
	//	idiv a
	//	mov res,eax
	//}
	//std::cout << "x= " << res;

	//int s, x, z,res;
	//std::cout << "Put s: ";
	//std::cin >> s;
	//std::cout << "Put x: ";
	//std::cin >> x;
	//std::cout << "Put z: ";
	//std::cin >> z;
	//__asm {
	//	mov eax,s
	//	mul z
	//	neg eax
	//	add eax,x
	//	mul s
	//	mov ebx,x
	//	imul ebx,z
	//	add ebx,s
	//	cdq
	//	idiv ebx
	//	mov res,eax
	//}
	//std::cout << "Result:" << res;
	int res;//50=2x+3y
	__asm {
		mov ebx, 1
		start:
		mov eax, 50
			imul ebx, 3
			sub eax, ebx
			mov ecx, 0
			cmp eax, 0
			jg greater
			jl finish
			je finish
			greater :
		test eax, 1
			je cont
			jz stop
			stop :
		add ecx, 1
			add ebx, 1
			jmp start
			cont :
		add ebx, 1
			jmp start
			finish :
		mov res, ecx
	}
	std::cout << res;
}

