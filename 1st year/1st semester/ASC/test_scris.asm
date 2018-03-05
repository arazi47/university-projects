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
    format db "hex %X, d = %d", 0
    sir dd 12345678h, 0
    
    ; 78h 56h 34h 12h

; our code starts here
segment code use32 class=code
    start:
        mov esi, sir
        lodsw
        
        movsx eax, ax
        mov ah, 0
        
        push dword eax
        push dword eax
        push dword format
        call [printf]
        add esp, 8
        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
