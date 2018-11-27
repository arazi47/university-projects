bits 32
global start

extern exit, printf, scanf
import exit msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll

segment data use32 class=data

; =====================================================================
; 21. Sa se citeasca de la tastatura doua numere a si b de tip word.
; Sa se afiseze in baza 16 numarul c de tip dword pentru care
; partea low este suma celor doua numere,
; iar partea high este diferenta celor doua numere.
; Exemplu:
; a = 574, b = 136
; c = 01B602C6h
; =====================================================================

    a dw 0
    b dw 0
    
    messa db "a= ", 0
    messb db "b= ", 0
    format db "%d", 0
    formatHex db "c = %Xh", 0
    
segment code use32 class=code
start:
    push dword messa
    call [printf]
    add esp, 4*1
    push dword a
    push dword format
    call [scanf]
    add esp, 4*2
    
    push dword messb
    call [printf]
    add esp, 4*1
    push dword b
    push dword format
    call [scanf]
    add esp, 4*2
    
    ; partea low
    mov edx, 0
    mov dx, [a]
    add dx, [b] ; a + b
    
    ; partea high
    mov eax, 0
    mov ax, [a]
    sub ax, [b] ; a - b
    
    shl eax, 16
    
    or eax, edx
    
    push dword eax
    push dword formatHex
    call [printf]
    add esp, 4*2
    
    push dword 0
    call [exit]