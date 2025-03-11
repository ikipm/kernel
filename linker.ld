ENTRY(_start)

SECTIONS {
    . = 1M;
    .text : { *(.multiboot) *(.text) }
    . = ALIGN(4);
    .commands : {
        __start_commands = .;
        KEEP(*(commands))
        __stop_commands = .;
    }
    .data : { *(.data) }
    .bss  : { *(.bss)  }
}
