.586
.model flat
.data
k dw 0
log dq ?
temp dq -1.0
m1 dq -1.0
res dq 0.0
sum dq 0.0
e5 dq 0.00001
e7 dq 0.0000001
e9 dq 0.000000001
public _Ln2@12
.code
_Ln2@12 proc
push ebp
mov ebp,esp
finit
fldln2
fstp log
mov ecx,15
cycle:

fld1
fiadd k
fistp k; k++

fld m1
fmul temp
fstp temp

fld temp
fidiv k
fstp sum
fld res
fadd sum
fstp res

fldln2
fsub res
fabs
fsub e5
fcom e5
and AX,0700h ;
cmp AH,1h
jg less
loop cycle
jmp finish
less:
	mov edx, dword ptr k
	mov [ebp+4],edx
finish:
	lea eax,res
pop ebp
ret 12
_Ln2@12 endp
end