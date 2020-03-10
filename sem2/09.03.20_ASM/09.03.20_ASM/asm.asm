.586
.model flat
.data 
mas db '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'
.code
_Calc@8 proc
    mov eax,[esp+4]
	mov ebx,[esp+8]
	mov ecx,16
calc:
    cdq
	div ecx
	cmp edx,10
	je A

	cmp edx,11
	je B

	cmp edx,12
	je C

	cmp edx,13
	je D

	cmp edx,14
	je E

	cmp edx,15
	je F

	mov [ebx], edx
	add ebx,1
	cmp eax,0
	je finish

		A:
	mov [ebx], 'A'	
	add ebx,1
	cmp eax,0
	je finish
	jmp calc
		B:
	mov [ebx], 'B'	
	add ebx,1
	cmp eax,0
	je finish
	jmp calc
		C:
	mov [ebx], 'C'	
	add ebx,1
	cmp eax,0
	je finish
	jmp calc
		D:
	mov [ebx], 'D'	
	add ebx,1
	cmp eax,0
	je finish
	jmp calc
		E:
	mov [ebx], 'E'	
	add ebx,1
	cmp eax,0
	je finish
	jmp calc
		F:
	mov [ebx], 'F'	
	add ebx,1
	cmp eax,0
	je finish
	jmp calc
	finish:
ret 8
_Calc@8 endp
end