.586
.model flat
public _CreateVectorB
.data
sizeofint dd 4
sizeofline dd 16
stroka dd ?
temp dd 0
mnozh dd 10
check dd 0; check for zero matches at all lines
.code
_CreateVectorB proc
    mov ecx,[esp+8]; number of lines
    dec ecx
    mov stroka,ecx
begin:
    cmp stroka,0
    jl finish
    mov esi,[esp+4]
    mov eax, stroka
    mul sizeofline; find a line 
    add esi,eax
    mov ebx,[esp+12]; number of elements in one line
    
start:
    dec ebx
    cmp ebx,0
    je nomatches
    mov eax,ebx
    mul sizeofint
PartCMP:
    cmp eax,0
    je next
    push eax
    mov eax,[esi][eax]
    cmp [esi], eax
    je writeB
    pop eax
    sub eax,4
    jmp PartCMP
next:
    add esi,4
    jmp start
loop begin

nomatches:
    dec stroka
    jmp begin

writeB:
    pop eax
    mov esi,[esp+16]
    mov eax,[esi]
    add eax,stroka
    mul mnozh
    mov [esi],eax
    mov [esp+16],esi
    dec stroka
    jmp begin
    

finish:
    dec stroka
    mov esi,[esp+16]
    mov eax,[esi]
    div mnozh
    mov [esi],eax
    mov [esp+16],esi


ret 
_CreateVectorB endp
end
