bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
extern fprintf
import fprintf msvcrt.dll
extern scanf
import scanf msvcrt.dll
extern printf
import printf msvcrt.dll
extern fclose
import fclose msvcrt.dll
extern fopen
import fopen msvcrt.dll

segment data use32 class=data
    var dd 0
    format db "%d"
    
    fisier db "fis.txt", 0
    mod_acces db "w", 0
    descriptor dd -1
    
    text db "0", 0

; our code starts here
segment code use32 class=code
    start:
        ;mov eax, 0 ; nr
        mov ebx, 0 ; suma numerelor
        
        repeta:
            push dword var
            push dword format
            call [scanf]
            add esp, 8
            
            mov eax, [var]
            
            ;push dword eax
            ;push dword format
            ;call [printf]
            ;add esp, 8
            
            cmp eax, 0
            je termina_repeta
            
            add ebx, [var]
         jmp repeta
            
        termina_repeta:
            ;push dword ebx
            ;push dword format
            ;call [printf]
            ;add esp, 8
            
            push dword mod_acces
            push dword fisier
            call [fopen]
            add esp, 8
            
            mov [descriptor], eax
            
            cmp eax, 0
            je final
            
            mov ecx, ebx ; pt loop
            
            scrie_bytes:
                push ecx
                
                push dword text
                push dword [descriptor]
                call [fprintf]
                add esp, 8  
                
                pop ecx
                
                loop scrie_bytes
    
        final:            
            push dword [descriptor]
            call [fclose]
            add esp, 4
            
            ; exit(0)
            push    dword 0      ; push the parameter for exit onto the stack
            call    [exit]       ; call exit to terminate the program
