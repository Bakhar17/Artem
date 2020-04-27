.586
.model flat
public _FindSize@8
public _FindPos@16
.data
sym db ' '
counter dd 0
.code
_FindSize@8 proc
	mov ecx,[esp+8]
	mov eax,[esp+8]
	xor edx,edx
	mov esi,[esp+4]
start:
	mov bh,[esi]
	cmp bh,sym
	je skip
	inc edx
	inc esi
	jmp next
	skip:
	inc esi
	jmp swipe
	jmp next
swipe:
	cmp eax,edx
	jg change
	jmp skip2
change:
	mov eax,edx
skip2:
	xor edx,edx
next:
	loop start
	cmp eax,edx
	jg great
	jmp end1
great:
	mov eax,edx
end1:
ret 8
_FindSize@8 endp

_FindPos@16 proc
	mov esi,[esp+4]; start string
	mov eax,[esp+8];size string
start:
	cmp eax,0
	je badfinish
	mov ecx,[esp+16];size word
	dec ecx
	mov edi,[esp+12];start word
	mov bh,[esi]
	mov bl,[edi]
	cmp bh,bl
	je cycle
	jne space
	jmp start
cycle:
	inc counter 
	dec eax
	cmp eax,0
	je badfinish
	inc esi
	inc edi
	mov bh,[esi]
	mov bl,[edi]
	cmp bh,bl
	jne space
	loop cycle
	jmp maybefinish
space:
	inc counter
	mov bh,[esi]
	cmp bh,sym
	je back
	inc esi
	dec eax
	cmp eax,0
	je badfinish
	jmp space
back:
	dec eax
	inc esi
	jmp start
maybefinish:
	mov bh,[esi+1]
	cmp bh,sym
	je finish
	cmp eax,1
	je finish
	jmp start
badfinish:
	dec eax
	jmp final
finish:
	mov eax, counter
	sub eax,[esp+16]
	inc eax
final:


ret 16
_FindPos@16 endp
end