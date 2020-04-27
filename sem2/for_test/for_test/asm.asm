.586
.model flat
.data
mnozh dd ?
k dd 1.0
count dd 1.0
fact dd 1.0
x dd 0.0
res dd 0.0

.code
_SinX@4 proc
    mov edx,20
    fld dword ptr [esp+4]
    fstp x
    fld x
    fstp res
    dec edx
start:
    mov ecx,2
cycle:

    BlockX:
    fld x
    fst ST(1)
    fld dword ptr [esp+4]
    Fmul
    fstp x
    

    fld1
    fst st(1)
    fld count
    fadd
    fstp count
    fld fact
    fmul count
    fstp fact
loop cycle
    
    ChangeZnak:
    fld k
    fchs 
    fstp k

    fld k
    fmul fact
    fstp mnozh


    fld x
    fdiv mnozh
    fadd res
    fstp res

    dec edx
    cmp edx,0
    jne start

lea eax,res
ret 4
_SinX@4 endp
end