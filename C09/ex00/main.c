#include <stdio.h>

void ft_putchar(char c);
void ft_swap(int *a, int *b);
void ft_putstr(char *str);
int ft_strlen(char *str);
int ft_strcmp(char *s1, char *s2);

int main() {
    // Test ft_putchar
    ft_putchar('A');
    ft_putchar('\n');

    // Test ft_swap
    int x = 10, y = 20;
    printf("Before swap: x = %d, y = %d\n", x, y);
    ft_swap(&x, &y);
    printf("After swap: x = %d, y = %d\n", x, y);

    // Test ft_putstr
    char str[] = "Hello, world!";
    ft_putstr(str);
    ft_putchar('\n');

    // Test ft_strlen
    int length = ft_strlen(str);
    printf("Length of string \"%s\": %d\n", str, length);

    // Test ft_strcmp
    char str1[] = "Hello";
    char str2[] = "Hello";
    char str3[] = "World";
    int result1 = ft_strcmp(str1, str2);  // Should return 0 (same)
    int result2 = ft_strcmp(str1, str3);  // Should return a negative value (different)
    printf("ft_strcmp(str1, str2): %d\n", result1);
    printf("ft_strcmp(str1, str3): %d\n", result2);

    return 0;
}
