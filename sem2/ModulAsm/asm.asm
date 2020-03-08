.586
.model flat
public _Swipe@12 ;function declaration
public _CheckPos@16
public _Erase@16
.code
_Swipe@12 proc
		mov esi, [esp+4]
		mov ebx, [esp+12]
		dec ebx
		imul ebx, 20
		mov edx, [esp+12]
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
		ret 12
_Swipe@12 endp

_CheckPos@16 proc
mov esi,[esp+4]
	mov ecx,[esp+8]
	dec ecx
	mov ebx, [esp+16]
	dec ebx
		start:
	cmp ecx,ebx
	jl badfinish
	mov edx, [esp+12]
	mov ebx, [esp+16]
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
		badfinish:
	mov eax,-1
	jmp finish
		finish1:
mov eax,[esp+8]
sub eax,[esp+16]
sub eax,ecx
		finish:
		ret 16
_CheckPos@16 endp

_Erase@16 proc
			mov eax,-1
			cmp [esp+16],eax
			je finish
			mov eax,[esp+8]
			mov esi,[esp+4]
			mov ecx,[eax]
			mov ebx,[esp+16]
			imul ebx,4
			add esi,ebx
			sub ecx,[esp+12]
			sub ecx,[esp+16]
			mov edx,[esp+12]
			swap:
			push [esi][edx*4]
			pop eax
			mov [esi],eax
			add esi,4
			loop swap
			finish:
			mov eax,[esp+8]
			mov ebx,[eax]
			sub ebx,[esp+12]
			mov [eax],ebx
			mov [esp+8],eax
ret 16
_Erase@16 endp
end