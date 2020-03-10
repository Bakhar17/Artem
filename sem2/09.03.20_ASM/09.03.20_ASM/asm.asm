.386
.model flat
.data 
masd db '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'
.code
_Reverse@4 proc
		mov esi,[esp+4]
		mov ecx,0
		mov edx,7
	reverse:
		mov ah,[esi][ecx]
		mov bh,[esi][edx]
		mov [esi][ecx],bh
		mov [esi][edx],ah
		inc ecx
		dec edx
	cmp ecx,4
	je finish
	jmp reverse
	finish:
ret 4
_Reverse@4 endp
_IntToHex@8 proc
		mov eax,[esp+4]
		mov esi,[esp+8]
		mov ecx,16
calc:
		cdq
		div ecx
		mov bl,masd[edx]
		mov [esi],bl
		cmp eax,0
	je finish
		add esi,1
	jmp calc
finish:
ret 8
_IntToHex@8 endp
end