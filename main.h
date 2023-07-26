#ifndef MAIN_nH
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct operation
 *
 * @fmt: The format.
 * @fn: The function association.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/

/* Funtions to display chars together with strings */
int print_char_alpha(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_string_values(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_percent_output(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to display numbers */
int print_int_values(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_binary_values(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned_values(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_octal_values(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa_upper_output(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_hexa_values(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function to display non printable characters */
int print_non_printable_values(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funcion to display memory address */
int print_pointer_values(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funciotns that  handles other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);
int get_flags_values(const char *format, int *i);

/*Function to display string in their reverse order*/
int print_reverse_values(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/*Function  displaying string in rot 13*/
int print_rot13string_output(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* width handler */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

/****************** UTILS ******************/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */
