#include <iostream>

int main()
{
	int n;
	std::cout << "task number: ";
	std::cin >> n;
	switch (n) {
	case(4): {
		int a;
		std::cout << "Put a: ";
		std::cin >> a;
		int x;
		std::cout << "Put degree: ";
		std::cin >> x;
		__asm {
			mov eax, 1
			mov ebx, a
			mov ecx, x
			cmp ecx,0
			je stop4
			degree:
			imul ebx
			loop degree
			mov a, eax
			jmp end4
			stop4:
			mov a,1
			jmp end4
				end4:
		}
		std::cout << "a^x= " << a;
		break; 
	}
	case(5): {
		std::cout << "Put number: ";
		int x;
		std::cin >> x;
		__asm {
			mov eax,x
			mov ebx,1
			start:
			cmp eax, ebx
			jg greater
			je right
			jl less
				greater:
			shl ebx,1
			jmp start
				less:
			mov x,0
			jmp end
				right:
			mov x,1
			jmp end
			end:

		}
		if (x)std::cout << "Yes";
		else std::cout << "No";
		break;
	}
	case(3): {
		int x;
		std::cout << "Put the number: ";
		std::cin >> x;
		__asm {
			mov eax,x
			mov ecx,0
				start1:
			cmp eax,0
			je end1
			test eax,1
			jz notcount
				count:
			add ecx, 1
			shr eax, 1
			jmp start1
				notcount:
			shr eax,1
			jmp start1
				end1:
			mov x,ecx
		}
		std::cout << x;
		break;
	}
	}
	return 0;
}


