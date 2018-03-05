bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
extern printf
import printf msvcrt.dll
segment data use32 class=data
    sir dd 0B234A68Ch, 528470C8h, 1AB3C470h, 0F9DC9886h
    
    ; 8C A6 34 B2
    len equ ($ - sir) / 4
    sir_rank times (len + 1) db 0
    
    format_chr db "%c", 0
    format_str db "%s", 0
    format_newline db "", 10, 13, 0
    format_suma db "%d", 0
    rank1 db "rank1", 0
    rank2 db "rank2", 0
    format_hex db "%X", 0
    
; our code starts here
segment code use32 class=code
    start:
        mov ecx, len
        jecxz final
        
        mov ebp, 0 ; contor sir rankuri
        mov edx, 0 ; suma
    
        mov esi, sir
        
        mainLoop:
            lodsw
            
            mov bx, ax ; bx - rank 2
            
            lodsw
            ; ax - rank 1
            
            cmp bx, ax
            ja rank2mare
            
            rank1mare:
                mov byte [sir_rank + ebp], "2"
                movzx eax, ax
                add edx, eax    
            jmp mainLoopCont
            
            rank2mare:
                mov byte [sir_rank + ebp], "1"
                movzx ebx, bx
                add edx, ebx
            
            mainLoopCont:
            inc ebp
        loop mainLoop
        
        pushad
        
        push dword sir_rank
        push dword format_str
        call [printf]
        add esp, 8
        
        popad
        
        pushad
        
        push dword format_newline
        call [printf]
        add esp, 4
        
        popad
        
        pushad
        
        push dword edx
        push dword format_suma
        call [printf]
        add esp, 8
        
        popad
    
        final:
            ; exit(0)
            push    dword 0      ; push the parameter for exit onto the stack
            call    [exit]       ; call exit to terminate the program
