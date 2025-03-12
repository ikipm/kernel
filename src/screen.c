#include "screen.h"

#define VGA_WIDTH 80
#define VGA_HEIGHT 25
#define VGA_ADDRESS 0xB8000

unsigned short* vga_buffer = (unsigned short*)VGA_ADDRESS;
unsigned char color = 0x0F; // White and black
unsigned int cursor_x = 0;
unsigned int cursor_y = 0;

unsigned int get_cursor_y(){ return cursor_y; }

void slide_text(const int y) {
    for (int i = 0; i < VGA_HEIGHT - y; i++) {
        for (int x = 0; x < VGA_WIDTH; x++) {
            vga_buffer[i * VGA_WIDTH + x] = vga_buffer[(y + i) * VGA_WIDTH + x];
        }
    }
    for (int i = VGA_HEIGHT-y; i < VGA_HEIGHT; i++) {
        for (int x = 0; x < VGA_WIDTH; x++) {
            vga_buffer[i*VGA_WIDTH + x] = 0x20;
        }
    }
    cursor_y -= y;
}

void change_color(const char bg, const char front) {
    color = (bg << 4) | (front << 4);
}

void print_char(const char c) {
    if (cursor_y >= VGA_HEIGHT) slide_text(1);
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

int clear_character() {
    if (cursor_x > 1) {
        cursor_x--;
        vga_buffer[cursor_y * VGA_WIDTH + cursor_x] = 0x20;
        return 1;
    }
    return 0;
}
