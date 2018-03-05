bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
extern printf
import printf msvcrt.dll

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a dw 2150
    b db 6
    
    format_int db "Catul %d si restul %d", 0

; our code starts here
segment code use32 class=code
    start:
        ;mov eax, 0
        mov ax, [a]
        mov dx, 0
        ;movzx eax, ax
        
        ;push eax
        ;pop ax
        ;pop dx
        
        mov bl, [b]
        ;movzx bx, bl
        mov bh, 0
        
        div bx
       
        ;dx - restul
        ;ax - catul
        
        movzx edx, dx ; restul
        movzx eax, ax ; catul
        
        push dword edx
        push dword eax
        push dword format_int
        call [printf]
        add esp, 12
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
