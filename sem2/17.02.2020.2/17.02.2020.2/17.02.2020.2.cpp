#include <iostream>
bool Symmetry(int a) {
		int ra;
		__asm {
			mov eax, a
			mov ebx, 10
			mov ecx, 0
			contin:
			cmp eax, 0
				JG repeat
				JE the_end
				repeat :
			cdq
				div ebx
				imul ecx, 10
				add ecx, edx
				jmp contin
				the_end :
			mov ra, ecx

		}
		return (ra == a);
}
int Summa(int a) {
	__asm {
		mov eax, a
		mov ebx, 10
		mov ecx, 0
		contins:
		cmp eax, 0
		JG repeats
		JE the_ends
		repeats :
		cdq
		div ebx
		add ecx, edx
		jmp contins
		the_ends :
		mov a, ecx
	}
	return a;
	
}
int EvenSumma(int a) {
	__asm {
		mov eax, a
		mov ebx, 10
		mov ecx, 0
			contine:
		cmp eax, 0
		JG repeate
		JE the_ende
			repeate :
		cdq
		div ebx
		jmp checke
		jmp contine
			checke:
		test edx,1
		jz go
		jmp contine
			go:
		add ecx, edx
		jmp contine
			the_ende :
		mov a, ecx
	}
	return a;
}
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
	case(2): {
		std::cout << "Put the divisor: ";
		int divisor;
		std::cin >> divisor;
		std::cout << "Put the denominator(>0): ";
		int denominator;
		std::cin >> denominator;
		if (divisor == 0) {
			std::cout << 0;
			break;
		}
		if (denominator > 0&&divisor>0) {
		__asm {

				mov eax, divisor
				mov ebx, denominator
				beg2 :
				cmp eax, ebx
					je end2
					jg greater2
					sub ebx, eax
					jmp beg2
					greater2 :
				sub eax, ebx
					jmp beg2
					end2:
				mov ecx, eax
				mov eax,divisor
				cdq 
				idiv ecx
				mov divisor,eax
				mov eax,denominator
				cdq
				div ecx
				mov denominator,eax
		}
		std::cout << divisor << "/" << denominator;
		break;
		}
		if (divisor < 0) {
			__asm {
				mov eax,divisor
				mov ecx,-1
				imul ecx
				mov ebx,denominator
				jmp beg2
			}
			std::cout << -divisor << "/" << denominator;
		}
   break;
	}
	case(1): {
		int a;
		std::cout << "Put the number: ";
		std::cin >> a;
		if (a < 0) {
			std::cout << "Wrong data!";
			break;
		}
		if (Symmetry(a)) std::cout << "Symmetry!\n";
		else std::cout << "No symmetry\n";
		std::cout << "Summa of digits: " << Summa(a)<<"\n";
		std::cout << "Summa of even digits: " << EvenSumma(a);
		break;
	}
	}
	return 0;
}


