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
    sir dd 12A63478h, 12345678h, 1A2B3C4Dh, 0FEDC9876h
    len equ ($ - sir) / 4
    sirpoz times (len + 1) db 0
    
    ; 78h 34h A6h 12h
    
    format_hex db "testez %X", 10, 13, 0
    format_str db "%s", 0
    format_int db "testez %d", 10, 13, 0
    format_intf db "suma este %d", 10, 13, 0

; our code starts here
segment code use32 class=code
    start:
        mov esi, sir
        mov ecx, len
        
        jecxz final
        
        mov bl, 0 ; first dword, second dword, etc...
        mov edx, 0 ; sirpoz index counter
        mov ebp, 0 ; suma
        
        iaDword:
            inc bl ; we start counting from 1
            lodsw
            lodsb
            movsx eax, al
            
            pushad
            
            push dword eax
            push dword format_hex
            call [printf]
            add esp, 8
            
            popad
            
            cmp eax, 0
            jge iaDwordCont
            
            add ebp, eax
            
            mov bh, bl ; facem o copie a pozitiei dwordului in sir
            add bl, "0"
            
            mov byte [sirpoz + edx], bl
            mov bl, bh
            inc edx
            
            iaDwordCont:
            lodsb ; read the last byte, too
        loop iaDword
        
        push dword ebp
        push dword format_intf
        call [printf]
        add esp, 8
        
        push dword sirpoz
        push dword format_str
        call [printf]
        add esp, 8
            
        final:
            ; exit(0)
            push    dword 0      ; push the parameter for exit onto the stack
            call    [exit]       ; call exit to terminate the program
