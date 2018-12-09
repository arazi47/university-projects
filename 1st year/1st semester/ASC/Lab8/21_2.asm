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

; ===========================================================================
; 21. A file name and a text (defined in the data segment) are given.
; The text contains lowercase letters, digits and spaces.
; Replace all the digits on odd positions with the character ‘X’.
; Create the file with the given name and write the generated text to file.
; ===========================================================================

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    fileName db "fis.txt", 0
    accessRights db "r", 0
    descriptor dd -1

; our code starts here
segment code use32 class=code
    start:
        push dword accessRights
        push dword fileName
        call [fopen]
        add esp, 4*2
        
        cmp eax, 0
        je final
        
        mov [descriptor], eax
        
        ;mainLoop:
            
            
        ;loop mainLoop
            
        final:
            push dword [descriptor]
            call [fclose]
            add esp, 4
        
            ; exit(0)
            push    dword 0      ; push the parameter for exit onto the stack
            call    [exit]       ; call exit to terminate the program