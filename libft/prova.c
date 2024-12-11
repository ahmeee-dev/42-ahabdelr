/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prova.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:50:45 by ahabdelr          #+#    #+#             */
/*   Updated: 2024/12/11 10:45:43 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include "ft_lib.h"

#include <stdio.h>

// Dichiarazione delle funzioni
int ft_isalnum(int c);
int ft_isalpha(int c);
int ft_isascii(int c);
int ft_isprint(int c);
int ft_isdigit(int c);
int ft_strlen(char *str);
void *ft_memset(void *ptr, int value, size_t num);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);
size_t  ft_strlcat(char *dest, const char *src, size_t size);
int ft_toupper(int c);
int ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(char *str, int c);
int	ft_strncmp(char *s1, char *s2, size_t size);
char *ft_memchr(const void *s, int c, size_t n);
int	ft_memcmp(void *s1, void *s2, size_t n);
char	*ft_strnstr(char *big, char *little, size_t len);
int ft_atoi(char *str);


int main() {
    char test_char = 'A';
    char test_non_alnum = '@';
    char test_digit = 5;
    char test_ascii = 127; 
    char test_printable = ' ';
    char *test_string = "Hello, 42!";

    printf("ft_isalnum('%c'): %d\n", test_char, ft_isalnum(test_char));
    printf("ft_isalnum('%c'): %d\n", test_non_alnum, ft_isalnum(test_non_alnum));

    printf("ft_isalpha('%c'): %d\n", test_char, ft_isalpha(test_char));
    printf("ft_isalpha('%c'): %d\n", test_non_alnum, ft_isalpha(test_non_alnum));

    printf("ft_isascii(%d): %d\n", test_ascii, ft_isascii(test_ascii));
    printf("ft_isascii(65): %d\n", ft_isascii(65));

    printf("ft_isprint('%c'): %d\n", test_printable, ft_isprint(test_printable));
    printf("ft_isprint('\\n'): %d\n", ft_isprint('\n'));

    printf("ft_isdigit('%c'): %d\n", test_digit, ft_isdigit(test_digit));
    printf("ft_isdigit('%c'): %d\n", test_char, ft_isdigit(test_char));

    printf("ft_strlen(\"%s\"): %d\n", test_string, ft_strlen(test_string));
    printf("ft_strlen(\"\"): %d\n", ft_strlen(""));

    char buffer[20] = "Initial string here";
    printf("\nBuffer prima di ft_memset: \"%s\"\n", buffer);

    
    ft_memset(buffer, '*', 10); // Riempie i primi 10 byte con '*'
    printf("Buffer dopo ft_memset: \"%s\"\n", buffer);

    char overlap_buffer[] = "Overlap example";
    printf("\nPrima di ft_memmove: \"%s\"\n", overlap_buffer);
    ft_memmove(overlap_buffer + 3, overlap_buffer, 7); // Sovrapposizione: sposta i primi 7 caratteri di 3 posizioni
    printf("Dopo ft_memmove: \"%s\"\n", overlap_buffer);
    

   // Test di ft_strlcpy
    char strlcpy_src[] = "42 School is awesome!";
    char strlcpy_dest[20];
    size_t strlcpy_result;

    printf("\nPrima di ft_strlcpy: src = \"%s\", dest = \"%s\"\n", strlcpy_src, strlcpy_dest);
    strlcpy_result = ft_strlcpy(strlcpy_dest, strlcpy_src, sizeof(strlcpy_dest));
    printf("Dopo ft_strlcpy: src = \"%s\", dest = \"%s\", lunghezza totale = %zu\n", strlcpy_src, strlcpy_dest, strlcpy_result);

    // Prova con un buffer troppo piccolo
    char small_dest[5];
    strlcpy_result = ft_strlcpy(small_dest, strlcpy_src, sizeof(small_dest));
    printf("Buffer troppo piccolo: dest = \"%s\", lunghezza totale = %zu\n", small_dest, strlcpy_result);


    char dest[10] = "Hello";
    char src[] = " World!";
    size_t result = ft_strlcat(dest, src, 50);
    printf("Dest: %s\n", dest);  // "HelloWor"
    printf("Result: %zu\n", result);  // 11 (lunghezza totale di "HelloWorld!")
    

    printf("to upper: '%c' after ft_toupper", (char)ft_toupper('a'));
    printf("to lower: '%c' after ft_tolower", (char)ft_tolower('A'));
    

    char str[] = "maresciallo";
    printf("\nstrchr test: 'a' = %p", ft_strchr(str, 'a'));

    printf("\nstrrchr test : 'a' = %p", ft_strrchr(str, 'a'));

    printf("\nstrncmp test: 'ciao' and 'ciau' = %d", ft_strncmp("cia", "cia", 4));

    printf("\nmemchr test : 'a' in 'maresciallo' = %p", ft_memchr(str, 'a', 1));

    printf("\nmemcmp test: 'abaco' & 'abaci' in size 5 = %d", ft_memcmp("abaco", "abaci", 6));

    printf("\nstrnstr test: 'aresciallo' in 'maresciallo' = %p", ft_strnstr(str, "aresciallo", 9));

    printf("\natoi test: '456' = '%d'", ft_atoi("–2147483648"));
    
    return 0;
}
