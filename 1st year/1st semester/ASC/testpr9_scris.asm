bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
extern printf
import printf msvcrt.dll

; sa se tipareasca in baza 16 catul si resul impartirii fara semn A/B, unde A = maximul valorilor octetilor inferiori din sir, B = minimul valorilor 
; octetilor superiori
; our data is declared here (the variables needed by our program)
segment data use32 class=data
    format_hex db "%X", 10, 13, 0
    finalstr db "cat: %X, rest: %X", 10, 13, 0
    
    sir dw 21520, -6, "xy", 0F5B2h, -129
    
    len equ ($ - sir) / 2
    
    ; 5410h FFFAh, 7978h, 0F5B2h, FF7Fh
    
    ; 10 54, FA FF, 78 79, B2 F5, 7F FF

; our code starts here
segment code use32 class=code
    start:
        mov esi, sir
        mov ecx, len
        
        jecxz final
        
        mov bh, 0 ; max dintre inferiori
        mov bl, 255 ; min dintre superiori
        
        cld
        
        mainLoop:
            lodsb ; byte superior!
            
            cmp al, bh
            jna loopCont
            
            mov bh, al
            
            loopCont:
                lodsb ; byte inferior!
                
                cmp al, bl
                ja mainLoopCont
                
                mov bl, al
                
            mainLoopCont:
        loop mainLoop
        
        mov al, bh ; al = max
        movzx ax, al
        mov dx, 0
        
        movzx bx, bl
        
        div bx
        
        ; dx - rest
        ; ax - cat
        
        movzx edx, dx
        movzx eax, ax
        
        pushad
        
        push dword edx
        push dword eax
        push dword finalstr
        call [printf]
        add esp, 12
        
        popad
    
        final:
            ; exit(0)
            push    dword 0      ; push the parameter for exit onto the stack
            call    [exit]       ; call exit to terminate the program
