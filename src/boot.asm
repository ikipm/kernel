section .multiboot
align 4
dd 0x1BADB002     ; Multiboot identifier
dd 0x00           ; Flags (0 - default config)
dd - (0x1BADB002 + 0x00) ; Checksum

section .text
global _start
extern main            ; Defined in file kernel.c
_start:
    cli                ; Disable interruptions
    mov esp, stack_space + 8192 ; set stack pointer
    call main          ; Starts C code
    hlt                ; Stop system

section .bss
align 16
stack_space resb 8192  ; 8KB for stack