.586
.model flat
.data
x dd 0.0
res dd 0.0
del dd 2.0
zero dd 0.0
.code
_CalculateSqrt@8 proc
mov edx,[esp+8]
mov ecx,[esp+4]
finit
fld dword ptr [edx]
fstp x

cycle:
BlockX:

fld res
fmul zero
fstp res


fld x
fdiv del
fadd res
fstp res

fld dword ptr[edx]
fdiv del
fdiv x
fadd res
fstp res
fld res
fstp x
loop cycle

fld dword ptr [edx]
fsqrt
fst st(1)
fld res
fsub
fabs
fstp dword ptr [edx]
mov [esp+8],edx

finish:
lea eax,res

ret 8
_CalculateSqrt@8 endp
end