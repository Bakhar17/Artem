#include <iostream>
int Symmetry(int a) {
	__asm {
		mov eax, a
		mov ebx, 10
		mov ecx, 0
			contin:
		cmp eax, 0
			JG repeat
			JE the_end1
				repeat :
		cdq
			div ebx
			cmp edx, 3
			je nextdel
			cmp edx,6
			je nextdel
			jmp next
				nextdel:
			jmp contin
				next:
			imul ecx,10
			add ecx,edx
			jmp contin
				the_end1 :
			mov a, ecx
			mov eax, a
			mov ebx, 10
			mov ecx, 0
				contin2 :
			cmp eax, 0
			JG repeat2
			JE the_end2
				repeat2 :
			cdq
			div ebx
			imul ecx, 10
			add ecx, edx
			jmp contin2
				the_end2 :
		mov a, ecx
	}
	return a;
}

int main()
{
	int n;
	printf("Put the number ");
	scanf_s("%d", &n);
	if (n > 0) {
		int x;
		__asm {
			mov eax, n
			mov ebx,1
			mov ecx,0
				start:
			cmp eax,ebx
			jg greater
			je stop
			jl less
				greater:
			inc ecx
			shl ebx,1
			jmp start
				stop:
			mov x,ecx
			jmp end
				less:
			mov x,ecx
			jmp end
				end:
		}
		std::cout <<"2^"<<x - 1 << "<="<<n<<"<=2^"<< x;
	}
		if (n <= 0) {
		std::cout << n << "<2^0";
		}
//task1
		printf("\nPut the number ");
		scanf_s("%d", &n);
		printf("New number %d", Symmetry(n));
} 
