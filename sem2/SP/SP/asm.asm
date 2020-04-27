.586
.model flat
.data
symbol db 0
.code
_CharLength@4 proc
        xor eax,eax
        mov esi,[esp+4]
        mov bh,symbol
    start:
        mov bl,byte ptr [esi]
        cmp bl,bh
        je finish
        inc eax
        add esi,1
        jmp start
    finish:
        ret 4
_CharLength@4 endp

@LeftPos@8 proc
        push ecx
        call _CharLength@4
        mov esi,ecx
        mov bh,[edx]
        mov ecx, eax
        mov eax,-1
        xor edx,edx
            start:
        mov bl,[esi]
        cmp bl,bh
        je ChangePos
        inc edx
        add esi,1
        loop start
        jmp finish
            ChangePos:
        mov eax,edx
            finish:
        ret
@LeftPos@8 endp


@RightPos@8 proc
        push ecx
        call _CharLength@4
        mov esi,ecx
        mov bh,[edx]

        mov ecx,eax
        add esi,ecx
        dec esi

        xor edx,edx 
        mov eax,-1

            start:
        mov bl,[esi]
        cmp bl,bh
        je ChangePos
        inc edx
        dec esi
        loop start
        jmp finish
            ChangePos:
        mov eax,edx
            finish:
        ret
        
@RightPos@8 endp

_PodStroka proc
    push [esp+4] ; check if we can make this string
    call _CharLength@4
    mov ebx,eax
    sub eax,[esp+12]
    sub eax,[esp+8]
    cmp eax,0
    jl stop

    mov esi,[esp+4]
    add esi,[esp+8]
    mov ecx,[esp+12]
    mov edx,[esp+4]

        copy:
    mov bh,[esi]
    mov [edx],bh
    inc edx
    inc esi
    loop copy

    mov bh,symbol
    mov [edx],bh

        stop:
    ret
_PodStroka endp


end