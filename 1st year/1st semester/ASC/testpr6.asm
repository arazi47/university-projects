bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

extern printf
import printf msvcrt.dll

extern scanf
import scanf msvcrt.dll

extern fopen
import fopen msvcrt.dll

extern fread
import fread msvcrt.dll

extern fclose
import fclose msvcrt.dll
                          
; our data is declared here (the variables needed by our program)
segment data use32 class=data
    format_str db "%s", 0
    format_int db "%d", 0
    format_char db "%c", 0
    
    char_special times 2 db 0
    nr dd 0
    
    nume_fisier times 20 db 0
    
    mod_acces db "r", 0
    descriptor dd -1
    
    text_len equ 100
    text times (text_len + 1) db 0
    
    endText db "end text", 10, 0
    ammt db "are mai multe", 10, 0
    testtext db "test", 10, 0

; our code starts here
segment code use32 class=code
    start:        
        push dword nume_fisier
        push dword format_str
        call [scanf]
        add esp, 8
        
        ;push dword nume_fisier
        ;push dword format_str
        ;call [printf]
        ;add esp, 8
        
        push dword char_special
        push dword format_str
        call [scanf]
        add esp, 8
        
        push dword nr
        push dword format_int
        call [scanf]
        add esp, 8
        
        ;push dword nume_fisier
        ;push dword format_str
        ;call [printf]
        ;add esp, 8
        
        push dword mod_acces
        push dword nume_fisier
        call [fopen]
        add esp, 8
        
        cmp eax, 0
        je final
        
        mov [descriptor], eax
        
        push dword [descriptor]
        push dword text_len
        push dword 1
        push dword text
        call [fread]
        add esp, 16
        
        pushad
        push dword [descriptor]
        call [fclose]
        add esp, 4
        popad
        
        ; eax contine nr de caractere citite
        ;push eax
        
        ;push dword text
        ;push dword format_str
        ;call [printf]
        ;add esp, 8
        
        ;pop eax
        
        mov esi, text
        mov edx, eax ; edx = lungimea sirului
        
        cmp eax, 0
        je final
        
        mainloop:
            mov ebx, 0 ; nr de caractere per cuvant
           
            citeste_si_afiseaza_cuvant:
                lodsb
                
                cmp al, 0 ; s-a terminat textul
                je complete_word_if_needed
                
                cmp al, 32 ; spatiu (end of word)
                je complete_word_if_needed
                
                inc ebx
                
                ; al => eax
                cbw
                cwde
                
                pushad
                
                push dword eax
                push dword format_char
                call [printf]
                add esp, 8
                
                popad
                
                jmp citeste_si_afiseaza_cuvant
                
                complete_word_if_needed:
                    ;pushad
                    ;push dword testtext
                    ;push dword format_str
                    ;call [printf]
                    ;jmp final
                    ;popad
                
                    cmp ebx, [nr]
                    jge mainloopcont
                    
                    ; nr - ebx => cate caractere trebuie ca sa completam cuvantul
                    ;mov ebp, [nr]
                    ;sub ebp, ebx
                    
                    ;mov ecx, ebp
                    
                    mov ecx, [nr]
                    sub ecx, ebx
                    
                    ;pushad
                    ;push dword ecx
                    ;push dword format_int
                    ;call [printf]
                    ;jmp final
                    ;popad
                    
                    complete_word:
                        pushad
                        
                        push dword char_special
                        push dword format_str
                        call [printf]
                        add esp, 8
                        
                        popad
                    loop complete_word
                    
                mainloopcont:
                    
                    ; iesim din mainloop daca am parcurs tot textul
                    sub edx, ebx ; scadem caracterele parcurse
                    sub edx, 1 ; scadem spatiul
                    cmp edx, 0
                    jle final
                    
        jmp mainloop
    
        final:
            ; exit(0)
            push    dword 0      ; push the parameter for exit onto the stack
            call    [exit]       ; call exit to terminate the program
