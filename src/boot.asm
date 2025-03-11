section .multiboot
align 4
dd 0x1BADB002     ; Multiboot identifier
dd 0x00           ; Flags
dd - (0x1BADB002 + 0x00) ; Checksum

section .text
global _start
extern main
_start:
    cli                ; Disable interruptions
    call main          ; Starts C code
    hlt                ; Stop system
