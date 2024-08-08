;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;1.1-Shellcode
;
; _______           _______  _        _        _______  _______  ______   _______ 
;(  ____ \|\     /|(  ____ \( \      ( \      (  ____ \(  ___  )(  __  \ (  ____ \
;| (    \/| )   ( || (    \/| (      | (      | (    \/| (   ) || (  \  )| (    \/
;| (_____ | (___) || (__    | |      | |      | |      | |   | || |   ) || (__    
;(_____  )|  ___  ||  __)   | |      | |      | |      | |   | || |   | ||  __)   
;      ) || (   ) || (      | |      | |      | |      | |   | || |   ) || (      
;/\____) || )   ( || (____/\| (____/\| (____/\| (____/\| (___) || (__/  )| (____/\
;\_______)|/     \|(_______/(_______/(_______/(_______/(_______)(______/ (_______/
;
;
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;



global studentfunction1
global _start

section .data
    strMsg db "/bin/sh"
    
section .text

_start:
    call studentfunction1

;
; implement a function that when called pops a shell to read the contents of the
; file `flag.txt`.
;
; HINT: exec_ve
;
studentfunction1:
    mov ebx, strMsg
    xor rax, rax
    mov rax, 11
    int 0x80
    ret

; End studentfunction1