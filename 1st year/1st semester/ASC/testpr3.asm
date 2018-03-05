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
    sir dd  00123110h, 110abcb0h, 55123110h, 0000bcb0h
    len equ ($ - sir) / 4
    
    ; 10 31 12 00, B0 BC 0A 11
    
    format db "max: %X, rang: %X   ", 0
    

; our code starts here
segment code use32 class=code
    start:
        mov esi, sir
        mov ecx, len
        
        cld
        
        repeta:
            xor ebx, ebx ; octetul maxim
            xor edx, edx ; rangul octetului
            
            lodsb
            ;cbw
            ;cwde ; eax = primul octet
            movzx ax, al
            movzx eax, ax
            
            mov ebx, eax
            mov edx, 1
            
            ;;;;;;;;;;
            
            lodsb
            ;cbw
            ;cwde
            movzx ax, al
            movzx eax, ax
            
            cmp ebx, eax
            jg continua
            
            mov ebx, eax
            mov edx, 2
            
            continua:
                lodsb
                ;cbw
                ;cwde
                movzx ax, al
                movzx eax, ax
                
                cmp ebx, eax
                jg continua2
                
                mov ebx, eax
                mov edx, 3
                
                continua2:
                    lodsb
                    ;cbw
                    ;cwde
                    movzx ax, al
                    movzx eax, ax
                    
                    cmp ebx, eax
                    jg continua_repeta
                    
                    mov ebx, eax
                    mov edx, 4
                   
                    continua_repeta:
                        pushad
                    
                        push dword edx
                        push dword ebx
                        push dword format
                        call [printf]
                        add esp, 12
                        
                        popad
        loop repeta
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
