#ifndef COMMANDS_H
#define COMMANDS_H
#include <stdbool.h>
extern const char* background_color[];
extern const char* text_color[];
void echo(const char* printval);
void new(char* specifier);
void dump(char *specifier);
void md(char* specifier);
void funny();
void clr();
void change_text_color(const char* CLR);
void change_background_color(const char* CLR);
bool id_and_execute(char *commandbuffer, char mode);
#endif