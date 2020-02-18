#include <iostream>

int main()
{
	int sec;
	int hour;
    std::cout << "Put seconds: ";
	std::cin >> sec;
	int minute;
	int lsec;
	__asm {
		mov eax,sec
		cdq
		mov ebx,3600
		div ebx
		mov hour,eax
		mov eax, sec
		mov ebx,hour
		imul ebx,3600
		sub eax,ebx
		mov ebx,60
		cdq
		div ebx
		mov minute,eax
		mov eax,sec
		mov ebx,hour
		imul ebx,3600
		sub eax,ebx
		mov ebx,minute
		imul ebx,60
		sub eax,ebx
		mov lsec,eax
	}
	std::cout <<hour<<" "<<minute<<" "<<lsec;
	/*int a, b, c;
	int res=0;
	std::cin >> a >> b >> c;
	__asm {
		
		mov eax,a
		mov ecx,0
		test eax,1
		jz stop
		jmp next
		stop:
		add ecx,a
		jmp next
		next:
		mov eax, b
		test eax, 1
		jz stop1
		jmp next2
		stop1:
		add ecx, eax
		jmp next2
		next2:
		mov eax, c
		test eax, 1
		jz stop2
		jmp end2
		stop2 :
		add ecx, c
		jmp end2
		end2:
		mov res,ecx
	}
	std::cout << "\n"<<res;*/
	system("pause");
	return 0;
	
}

