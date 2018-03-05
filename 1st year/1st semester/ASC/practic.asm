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

extern fprintf
import fprintf msvcrt.dll

extern fclose
import fclose msvcrt.dll


; our data is declared here (the variables needed by our program)
segment data use32 class=data
    n dd 0 ; numarul ce trebuie citit
    cuvant times 21 db 0
    
    format_int db "%d", 0
    format_str db "%s", 0
    format_chr db "%c", 0
    format_spatiu db " ", 0
    
    fileName db "fis.txt", 0
    accessRights db "w", 0
    descriptor dd -1
    
    testtext db "test", 0

; our code starts here
segment code use32 class=code
    start:
        push dword n
        push dword format_int
        call [scanf]
        add esp, 8
        
        ;push dword [n]
        ;push dword format_int
        ;call [printf]
        ;add esp, 8
        
        push dword accessRights
        push dword fileName
        call [fopen]
        add esp, 8
        
        cmp eax, 0
        je final
        
        mov [descriptor], eax
        
        citesteCuvant:
            push dword cuvant
            push dword format_str
            call [scanf]
            add esp, 8
            
            cmp byte [cuvant], '#'
            je final
            
            mov esi, cuvant
            mov ebx, 0
            
            loopCuvant:
                lodsb
                   
                cmp al, 0
                je continua
                
                cmp al, 'a'
                jne cont1
                
                inc ebx
                jmp loopCuvant
                
                cont1:
                cmp al, 'e'
                jne cont2
                
                inc ebx
                jmp loopCuvant
                
                cont2:
                cmp al, 'i'
                jne cont3
                
                inc ebx
                jmp loopCuvant
                
                cont3:
                cmp al, 'o'
                jne cont4
                
                inc ebx
                jmp loopCuvant
                
                cont4:
                cmp al, 'u'
                jne loopCuvant
                
                inc ebx
            jmp loopCuvant
            
            continua:
            
            ;pushad
            
            ;push dword ebx
            ;push dword format_int
            ;call [printf]
            ;add esp, 8
            
            ;popad
            
            cmp ebx, [n]
            jb citesteCuvant
            
            pushad
            
            push dword cuvant
            push dword [descriptor]
            call [fprintf]
            add esp, 8
            
            push dword format_spatiu
            push dword [descriptor]
            call [fprintf]
            add esp, 8
            
            popad
            
        jmp citesteCuvant
            
        final:
            push dword [descriptor]
            call [fclose]
            add esp, 4
        
            ; exit(0)
            push    dword 0      ; push the parameter for exit onto the stack
            call    [exit]       ; call exit to terminate the program
