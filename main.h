#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

/*FUNCTIONS IN _PRINTF.C*/
int _printf(const char *format, ...);
#define BUFFER_SIZE 1024
int solve_print(const char *ftm, int *m, va_list args, char buffer, int flag, int width, int precise, int size);
int get_flag(const char *format, int m);
int get_flags(const char *format, int *m);
int get_width(const char *format, int *m, va_list list);
int get_precision(const char *format, int *m, va_list list);
int get_size(const char *format, int *m);
void buffer_print(char buffer[], int *buffer_index); 
