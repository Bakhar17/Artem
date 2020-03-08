#include <iostream>
void Swipe(int (*arr)[5][5], int size_) {
	std::cout << "\nPut the line: ";
	int k;
	std::cin >> k;
	__asm {
		mov esi, arr
		mov ebx, k
		dec ebx
		imul ebx, 20
		mov edx, k
		dec edx
		imul edx, 4
		mov ecx, 5
		xor eax, eax
		start :
		mov eax, [esi][ebx]
		push eax
		mov eax, [esi][edx]
		mov[esi][ebx], eax
		pop eax
		mov[esi][edx], eax
		add edx, 20
		add ebx, 4
		loop start
	}
}
int CheckPos(int* arr,int size_,int *sarr,int ssize_) {
	if (ssize_ > size_) return 0;
	int pos;
	int flag=0;
	__asm {
	mov esi,arr
	mov ecx,size_
	dec ecx
	mov ebx, ssize_
	dec ebx
		start:
	cmp ecx,ebx
	jl finish
	mov edx, sarr
	mov ebx, ssize_
	dec ebx
	mov eax,[edx]
	cmp [esi],eax
	je next
	add esi,4
	dec ecx
	jmp start
		next:
	cmp ebx,0
	je finish1
	add esi,4
	dec ecx
	add edx,4
	dec ebx
	mov eax, [edx]
	cmp [esi], eax
	je next
	jmp start
		finish1:
	push ecx
		pop eax
		mov pos,eax
		mov flag,1
		finish:
	}
	if (flag) {
		return (size_ - pos-ssize_);
	}
	return -1;
}
void Erase(int* arr, int* size_,int ssize_, int pos) {
	int sizer(*size_);
	*size_ = *size_ - ssize_;
	if (pos != -1) {
		__asm {
			mov esi,arr
			mov ecx,sizer
			mov ebx,pos
			imul ebx,4
			add esi,ebx
			sub ecx,ssize_
			sub ecx,pos
			mov edx,ssize_
			swap:
			push [esi][edx*4]
			pop eax
			mov [esi],eax
			add esi,4
			loop swap
		}
	}
}
int main()
{
	int arr[5][5];
	int sr = 1;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			arr[i][j] = sr;
			sr++;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		std::cout << "\n";
		for (int j = 0; j < 5; j++)
		{
			std::cout << arr[i][j] << "\t";
		}
	}
	
	int n;
	std::cout << "\nPut the task number: ";
	std::cin >> n;
	switch (n) {
	case(1):
		Swipe(&arr, 25);
		for (int i = 0; i < 5; i++)
		{
			std::cout << "\n";
			for (int j = 0; j < 5; j++)
			{
				std::cout << arr[i][j] << "\t";
			}
		}
			break;
	case(2): {
		std::cout << "Put the size of first array: ";
		int size_;
		std::cin >> size_;
		std::cout << "Put the size of second array: ";
		int ssize_;
		std::cin >> ssize_;
		int* dyn_arr = new int[size_];
		for (int i = 0; i < size_; i++)
		{
			dyn_arr[i] = i + 1;
		}
		int* sdyn_arr = new int[ssize_];
		for (int i = 0; i < ssize_; i++)
		{
			sdyn_arr[i] = i + 3;
		}
		int pos = CheckPos(dyn_arr, size_, sdyn_arr, ssize_);
		std::cout<<"\n"<<pos<<"\n";
		Erase(dyn_arr, &size_, ssize_, pos);
		for (int i = 0; i < size_; i++)
		{
			std::cout << dyn_arr[i] << "\t";
		}
		delete[] dyn_arr;
		delete[] sdyn_arr;
	}
		break;
	default:
		break;
	}


	system("pause");
	return 0;
}