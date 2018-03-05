bits 32

global start        

extern exit
import exit msvcrt.dll

extern printf
import printf msvcrt.dll

segment data use32 class=data
    format_chr db "%c", 0
    sir db "a", "b", "c", "d", "e", 0
    len equ ($ - sir)
    

; our code starts here
segment code use32 class=code
    start:
        ;mov esi, sir
        std
        ;add esi, len
        
        ;lodsb
        
        ;movzx eax, al
        
        push dword 0
        call [exit]
