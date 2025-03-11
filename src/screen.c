#include "screen.h"

#define VGA_WIDTH 80
#define VGA_HEIGHT 25
#define VGA_ADDRESS 0xB8000

unsigned short* vga_buffer = (unsigned short*)VGA_ADDRESS;
unsigned char color = 0x0F; // White and black
unsigned int cursor_x = 0;
unsigned int cursor_y = 0;

void change_color(const char bg, const char front) {
    color = (bg << 4) | (front << 4);
}

void print_char(const char c) {
    if (c == '\n') {
        cursor_x = 0;
        cursor_y++;
    } else {
        vga_buffer[cursor_y * VGA_WIDTH + cursor_x] = (color << 8) | c;
        cursor_x++;
    }
}

void print_string(const char *str) {
    while (*str) {
        print_char(*str++);
    }
}

void clear_screen() {
    cursor_x = 0;
    cursor_y = 0;
    for (int i = 0; i < VGA_WIDTH*VGA_HEIGHT; i++) {
        vga_buffer[i] = 0x20;
    }
}
