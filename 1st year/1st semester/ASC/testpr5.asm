bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
; our data is declared here (the variables needed by our program)
extern fread
import fread msvcrt.dll

extern fprintf
import fprintf msvcrt.dll

extern fopen
import fopen msvcrt.dll

extern fclose
import fclose msvcrt.dll

extern scanf
import scanf msvcrt.dll

extern printf
import printf msvcrt.dll

segment data use32 class=data
    char_to_replace db "a", 0
    char_to_be_replaced_with db "#", 0
    descriptor dd -1
    fisier db "fis.txt", 0
    mod_acces db "w", 0
    sir times 100 db 0
    format_str db "%s", 0
    format_dec db "%d", 0
    format_char db "%c", 0

; our code starts here
segment code use32 class=code
    start:
        push dword sir
        push dword format_str
        call [scanf]
        add esp, 8
            
        push dword mod_acces
        push dword fisier
        call [fopen]
        add esp, 8
            
        cmp eax, 0
        je continua
            
        mov [descriptor], eax
            
        mov ecx, 0
        lungime:
            cmp byte[sir + ecx], 0
            je gatalungime
            
            inc ecx
        jmp lungime
        
        ;gatalng1:
        
        ;push ecx
        
        ;push dword ecx
        ;push dword format
        ;call [printf]
        ;add esp, 8
        
        ;pop ecx
        
        ;jmp continua
        
        gatalungime:
            mov esi, sir
            cld
            
            repeta:
                lodsb
                
                cmp al, 97
                jne scrie_eax
                
                push ecx
                
                push dword char_to_be_replaced_with
                push dword [descriptor]
                call [fprintf]
                add esp, 8
                
                pop ecx
                
                jmp cont_repeta
                
                scrie_eax:
                    movzx ax, al
                    movzx eax, ax
                    
                    push ecx
                    
                    push dword eax
                    push dword [descriptor]
                    call [fprintf]
                    add esp, 8
                    
                    pop ecx
                    
                    cont_repeta:
            loop repeta
            
        continua:
            ; inchide fisier
            push dword [descriptor]
            call [fclose]
            add esp, 4
        
            final:
                ; exit(0)
                push    dword 0      ; push the parameter for exit onto the stack
                call    [exit]       ; call exit to terminate the program
