#ifndef SCREEN_H
#define SCREEN_H

unsigned int get_cursor_y();

void slide_text(const int y);
void change_color(const char bg, const char front);
void print_char(const char c);
void print_string(const char *message);
void clear_screen();
int clear_character();

#endif
