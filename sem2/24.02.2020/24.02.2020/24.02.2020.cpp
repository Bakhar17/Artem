#include <iostream>
int ZeroZone(int* darr,int size_) {
	int res = 0;
	__asm {
		xor eax,eax
		mov esi,darr
		mov ecx,size_
			start:
		cmp ecx,0
		je finish
		cmp [esi],0
		je fstop
		add esi,4
		dec ecx
		jmp start
			fstop:
		inc eax
		add esi,4
		dec ecx
		cmp [esi],0
		je sstop
		jmp start
			sstop:
		cmp ecx,0
		je finish
		add esi,4
		dec ecx
		cmp [esi],0
		je sstop
		jmp start
			finish:
		mov res,eax
	}
	return res;
}
int MaxPos(int* darr, int size_) {
	int max = *darr;
	__asm {
		xor eax,eax
		xor ebx,ebx
		mov ecx,size_
		mov eax,max
		mov edx,darr
		dec ecx
			start_max:
		add edx,4
		cmp eax,[edx]
		jl less
		jmp cont
			less:
		mov ebx,ecx
		mov eax,[edx]
			cont:
		loop start_max
		mov max,ebx

	}
	return (size_-max);
}
int MinPos(int* darr, int size_) {
	int min = *darr;
	__asm {
		xor eax, eax
		xor ebx, ebx
		mov ecx, size_
		mov eax, min
		mov edx, darr
		dec ecx
		start_min :
		add edx, 4
			cmp eax, [edx]
			jg great
			jmp contm
			great :
		mov ebx, ecx
			mov eax, [edx]
			contm :
			loop start_min
			mov min, ebx

	}
	return (size_ - min);
}
void SwipeElem(int* darr,int size_) {
	int max_pos = MaxPos(darr, size_);
	__asm {
		mov esi,darr
		mov eax,max_pos
		imul eax,4
		mov ebx,[esi][eax]
		mov edx,size_
		sub edx,1
		mov ecx,[esi][edx*4]
		mov [esi][eax],ecx
		mov [esi][edx*4],ebx
	}
}
void AsmSort(int* darr, int size_) {
	__asm {
	mov ecx,size_
	dec ecx
		start:
	mov esi,darr

	push size_
	push darr
	call MaxPos
	mov edx,[esi][eax*4]
	mov ebx,[esi]
	mov [esi],edx
	mov [esi][eax*4],ebx
	add esi,4
	mov darr,esi
 mov eax,size_
 dec eax
mov size_,eax
		loop start
	mov ecx,size_
	imul ecx,4
	sub esi,ecx
	mov darr,esi
}
}

int main()
{
	int n;
	std::cout << "Put the task number: ";
	std::cin >> n;
	switch (n)
	{
	case(1): {
		int size_;
		std::cout << "Put the size of array: ";
		std::cin >> size_;
		int* darr = new int[size_];
		for (int i = 0; i < size_; i++)
		{
			std::cin >> *(darr + i);
		}
		for (int i = 0; i < size_; i++)
		{
			std::cout << *(darr + i)<<"\t";
		}
		int res =ZeroZone(darr,size_);
		std::cout << "\nThe number of ZeroZone: " << res;
		delete[]darr;
		break;
	}
	case(2): {		
		int size_;
		std::cout << "Put the size of array: ";
		std::cin >> size_;
		int* darr = new int[size_];
		for (int i = 0; i < size_; i++)
		{
			std::cin >> *(darr + i);
		}
		for (int i = 0; i < size_; i++)
		{
			std::cout << *(darr + i) << "\t";
		}
		SwipeElem(darr, size_);
		std::cout << "\n";
		for (int i = 0; i < size_; i++)
		{
			std::cout << *(darr + i) << "\t";
		}
		delete[]darr;
		break;
	}
	case(3): {
		int size_;
		std::cout << "Put the size of array: ";
		std::cin >> size_;
		int* darr = new int[size_];
		for (int i = 0; i < size_; i++)
		{
			std::cin >> *(darr + i);
		}
		for (int i = 0; i < size_; i++)
		{
			std::cout << *(darr + i) << "\t";
		}
		 //AsmSort(darr, size_);
		 std::cout << "\n";
		 for (int i = 0; i < size_; i++)
		 {
			 std::cout << *(darr + i) << "\t";
		 }

		break;
	}
		
	default:
		break;
	}
	system("pause");
	return 0;
}
