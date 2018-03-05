bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

extern printf
import printf msvcrt.dll

extern fopen
import fopen msvcrt.dll

extern fread
import fread msvcrt.dll

extern fclose
import fclose msvcrt.dll

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    fileName db "fis.txt", 0
    accessRights db "r", 0
    descriptor dd -1
    
    len equ 100
    sir times (len + 1) db 0
    
    format_str db "%s", 0
    format_chr db "%c", 0
    format_int db "%d ", 0
    format_unsigned db "%u ", 0
    
    occurences times 26 dd 0

; our code starts here
segment code use32 class=code
    start:
        push dword accessRights
        push dword fileName
        call [fopen]
        add esp, 8
        
        cmp eax, 0
        je final
        
        mov [descriptor], eax
        
        push dword [descriptor]
        push dword len
        push dword 1
        push dword sir
        call [fread]
        add esp, 16
        
        push eax
        
        push dword [descriptor]
        call [fclose]
        add esp, 4
        
        pop eax
        
        ;push dword eax
        ;push dword format_int
        ;call [printf]
        ;add esp, 8
        
        cmp eax, 0
        je final
        
        mov esi, 0
        mov ecx, eax
        
        mainloop:
            mov al, [sir + esi]
            movzx ax, al
            movzx eax, ax
            
            sub eax, 97
            
            ;pushad
            
            ;push dword eax
            ;push dword format_int
            ;call [printf]
            ;add esp, 8
            
            ;popad
            
            add dword [occurences + eax * 4], 1
            
            inc esi
        loop mainloop
        
        mov ecx, 26 ; no of letters in the alphabet
        mov esi, 0
        loopocc:
            pushad
            
            push dword [occurences + esi]
            push dword format_int
            call [printf]
            add esp, 8
            
            popad
            
            inc esi
        loop loopocc
    
        final:
            ; exit(0)
            push    dword 0      ; push the parameter for exit onto the stack
            call    [exit]       ; call exit to terminate the program
