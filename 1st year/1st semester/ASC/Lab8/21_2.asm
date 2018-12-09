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
    text db "123a456ioti12"
    textLen equ $ - text
    currIndex db 0

    format_x db "X", 0
    
    fileName db "fis.txt", 0
    accessRights db "w", 0
    descriptor dd -1
    
    letter times 2 db 0
    
    doi db 2

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
        
        mov esi, text
        mov ecx, textLen
        
        mainLoop:
            lodsb
            
            mov bl, al ; bl = curr character
            
            mov al, [currIndex]
            movzx ax, al ; ax = currIndex
            div byte [doi]
            
            mov al, bl
            
            cmp ah, 1 ; vedem daca restul e impar
            jne mainLoopCont

            cmp al, '0'
            je printX
            
            cmp al, '1'
            je printX
            
            cmp al, '2'
            je printX
            
            cmp al, '3'
            je printX
            
            cmp al, '4'
            je printX
            
            cmp al, '5'
            je printX
            
            cmp al, '6'
            je printX
            
            cmp al, '7'
            je printX
            
            cmp al, '8'
            je printX
            
            cmp al, '9'
            jne mainLoopCont
            
            
            printX:
                pushad
                
                push dword format_x
                push dword [descriptor]
                call [fprintf]
                add esp, 4*2
                
                popad
                
                jmp mainLoopContFinal
            
            mainLoopCont:
                pushad
                
                mov [letter], al
                
                push dword letter
                push dword [descriptor]
                call [fprintf]
                add esp, 4*2
                
                popad
            
            mainLoopContFinal:
                inc byte [currIndex]
        loop mainLoop
            
        final:
            push dword [descriptor]
            call [fclose]
            add esp, 4
        
            ; exit(0)
            push    dword 0      ; push the parameter for exit onto the stack
            call    [exit]       ; call exit to terminate the program