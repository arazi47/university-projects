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
    sir db 1, 2, 3, 4, 5, 6
    len equ ($ - sir)
    format db "%d", 0
    suma_nr_pare dd 0
    doi db 2

; our code starts here
segment code use32 class=code
    start:
        mov esi, sir
        mov ecx, len
        
        repeta:
            lodsb
            
            cbw ; ax = al (pentru impartire)
            mov bx, ax ; salvam o copie
                       ; nr original va fi impartit la 2
            
            div byte [doi]
            
            cmp ah, 0 ; comparam restul cu 0
            jnz continua_repeta ; daca nu e 0, continuam iteratia
            
            add [suma_nr_pare], bx ; adaugam la suma numerelor pare copia numarului din sir
            
            continua_repeta:
        loop repeta
        
        ; printam suma
        push dword [suma_nr_pare]
        push dword format
        call [printf]
        add esp, 8
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
