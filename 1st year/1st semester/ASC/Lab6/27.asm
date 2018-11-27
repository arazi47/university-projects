bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit,printf               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
                          import printf msvcrt.dll

; ==================================================================
; 27. Dandu-se un sir de cuvinte, sa se calculeze
; cel mai lung subsir de cuvinte ordonate crescator din acest sir.
; ==================================================================

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    sir DW 12h, 12h, 34h, 55h, 55h
    sirLen equ ($ - sir) / 2
    
    currIndexStart db 0
    currIndexEnd db 0
    
    maxIndexStart db 0
    maxIndexEnd db 0
    
    currIndex db 0
    
    format db "de la %d la %d", 0

; our code starts here
segment code use32 class=code
    start:
        mov esi, sir
        mov ecx, sirLen
        
        lodsw
        dec ecx
        mov bx, ax ; primul word in bx
        
        sirLoop:
            lodsw
            inc word [currIndex]
            
            cmp ax, bx
            ja sirLoopCont
            
            ; daca ax <= bx
            mov dl, [currIndexEnd]
            mov dh, [currIndexStart]
            sub dl, dh ; dl = currIndexEnd - currIndexStart
            
            mov bl, [maxIndexEnd]
            mov bh, [maxIndexStart]
            sub bl, bh ; bl = maxIndexEnd - maxIndexStart
            
            cmp dl, bl
            jb sirLoopCont2
            
            ; daca subsirul curent e mai lung
            ; decat subsirul maximal gasit pana acum
            ; subsirul maximal = cel curent
            
            mov dl, [currIndexEnd]
            mov [maxIndexEnd], dl
            
            mov dl, [currIndexStart]
            mov [maxIndexStart], dl
            
            mov dl, [currIndex]
            ;movzx dx, dl
            
            mov byte [currIndexStart], dl
            mov byte [currIndexEnd], dl
            
            jmp sirLoopCont2
            
            sirLoopCont:
                inc word [currIndexEnd]
                
                sirLoopCont2:
                    mov bx, ax
        loop sirLoop
        
        ; daca subsirul curent e crescator pana la final
        ; mai trebuie verificat o data daca e mai lung
        ; decat cel maximal gasit pana acum
        
        mov dl, [currIndexEnd]
        mov dh, [currIndexStart]
        sub dl, dh ; dl = currIndexEnd - currIndexStart
        
        mov bl, [maxIndexEnd]
        mov bh, [maxIndexStart]
        sub bl, bh ; bl = maxIndexEnd - maxIndexStart
        
        cmp dl, bl
        
        jb afisareFinal
        
        ; daca subsirul curent e mai lung
        ; decat subsirul maximal gasit pana acum
        ; subsirul maximal = cel curent
        
        mov dl, [currIndexEnd]
        mov [maxIndexEnd], dl
        
        mov dl, [currIndexStart]
        mov [maxIndexStart], dl
        
        ; --------------------------
        
        afisareFinal:
        
        mov dl, [maxIndexStart]
        movzx edx, dl
        
        mov al, [maxIndexEnd]
        movzx eax, al
        
        push dword eax
        push dword edx
        push dword format
        call [printf]
        add esp, 4*3
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program