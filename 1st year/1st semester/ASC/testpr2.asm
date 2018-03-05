;Problema. Se da un sir de valori numerice intregi reprezentate pe quadworduri.
;Sa se determine suma cifrelor numarului multiplilor de 8 din sirul octetilor 
;inferiori ai cuvintelor superioare ai dublucuvintelor superioare din elementele sirului de quadworduri.

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
    sir dq  123110110abcb0h,1116adcb5a051ad2h,4120ca11d730cbb0h
    len equ ($ - sir) / 8
    
    format db "%X", 0
    
    opt db 8
    suma dd 0
    zece dd 10
    
    ; B0 BC 0A 11  10 31 12 00

; our code starts here
segment code use32 class=code
    start:
        mov esi, sir
        mov ecx, len
        
        mov ebx, 0 ; contorul de multiplii
        
        cld
        
        repeta:
            lodsd
            lodsw
            lodsb
            
            ;cbw
            ;cwd
            ;cwde
            
            ;push ecx
            
            ;push dword eax
            ;push dword format
            ;call [printf]
            ;add esp, 8
            
            ;pop ecx
            
            cbw ; ax = al
            
            div byte [opt]
            
            cmp ah, 0
            jnz continua_repeta
            
            inc ebx
            
            continua_repeta:
            lodsb
        loop repeta
        
        mov eax, ebx ; pentru impartire
        mov edx, 0
        suma_cifre:
            div dword [zece]
            
            add dword [suma], edx
            
            cmp eax, 0
            je finish
            mov edx, 0
        jmp suma_cifre
            
        finish:
            push dword [suma]
            push dword format
            call [printf]
            add esp, 8
            
            ; exit(0)
            push    dword 0      ; push the parameter for exit onto the stack
            call    [exit]       ; call exit to terminate the program
