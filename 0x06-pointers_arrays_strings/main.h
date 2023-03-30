#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>

/* _putchar - writes the character c to stdout */
int _putchar(char c);

/* _islower - checks for lowercase character */
int _islower(int c);

/* _isalpha - checks for alphabetic character */
int _isalpha(int c);

/* _abs - computes the absolute value of an integer */
int _abs(int n);

/* _isdigit - checks for a digit (0 through 9) */
int _isdigit(int c);

/* _strlen - returns the length of a string */
int _strlen(char *s);

/* _strcpy - copies the string pointed to by src to dest */
char *_strcpy(char *dest, char *src);

/* _atoi - converts a string to an integer */
int _atoi(char *s);

/* _strcat - concatenates two strings */
char *_strcat(char *dest, char *src);

/* print_number - prints an integer */
void print_number(int n);

/* print_square - prints a square */
void print_square(int size);

/* print_triangle - prints a triangle */
void print_triangle(int size);

#endif /* MAIN_H */ 

