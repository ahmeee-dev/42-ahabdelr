
#include "../libft/libft.h"
#include "../includes/ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

// Dichiarazione della tua ft_printf
int ft_printf(const char *str, ...);

int main()
{
    // int i = 42;
    // int neg = -42;
    // unsigned int u = 12345;
    // char c = 'A';
    // char *str = "Hello, World!";
    // void *ptr = &i;

    // Test con un carattere
    // printf(" %d %d %d %d %d %d %d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

    // Test con una stringa
    ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
    // printf("" %%%% "");

    return 0;
}
