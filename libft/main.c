#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

#define TITLE(msg) printf("\n=== %s ===\n", msg)
#define CHECK(cond) do { \
    printf("[%s] %s\n", (cond) ? "OK" : "KO", #cond); \
} while (0)

#define SHOW_LEAKS() system("leaks -q my_program | grep LEAK")

// Funzione di segnale per SIGSEGV
void sigsegv(int signum)
{
    (void)signum;
    printf("[ERROR] Segmentation fault!\n");
    exit(1);
}

// Implementazione della tua ft_calloc
void *ft_calloc(size_t nmemb, size_t size)
{
    void *ptr;

    // Controllo overflow nella moltiplicazione
    if (nmemb != 0 && size != 0 && (size_t)-1 / nmemb < size)
        return (NULL);

    // Gestione 0 come fallback
    if (nmemb == 0 || size == 0)
        return (malloc(1));

    // Allocazione della memoria
    ptr = malloc(nmemb * size);
    if (!ptr)
        return (NULL);
    memset(ptr, 0, nmemb * size); // Azzeramento memoria
    return (ptr);
}

// Funzione principale con test
int main(void)
{
    signal(SIGSEGV, sigsegv); // Gestione SIGSEGV
    TITLE("ft_calloc Test Suite");

    void *p = ft_calloc(2, 2);
    char e[] = {0, 0, 0, 0};

    /* 1 */ CHECK(!memcmp(p, e, 4));
    /* 2 */ CHECK(p != NULL); free(p); SHOW_LEAKS();

    /* 3 */ CHECK(ft_calloc(SIZE_MAX, SIZE_MAX) == NULL); SHOW_LEAKS();

    /* 4 */ CHECK(ft_calloc(INT_MAX, INT_MAX) == NULL);

    /* 5 */ CHECK(ft_calloc(INT_MIN, INT_MIN) == NULL); SHOW_LEAKS();

    p = ft_calloc(0, 0);
    /* 6 */ CHECK(p != NULL); free(p); SHOW_LEAKS();

    p = ft_calloc(0, 5);
    /* 7 */ CHECK(p != NULL); free(p); SHOW_LEAKS();

    p = ft_calloc(5, 0);
    /* 8 */ CHECK(p != NULL); free(p); SHOW_LEAKS();

    /* 9 */ CHECK(ft_calloc(-5, -5) == NULL); SHOW_LEAKS();

    p = ft_calloc(0, -5);
    /* 10 */ CHECK(p != NULL); free(p); SHOW_LEAKS();

    p = ft_calloc(-5, 0);
    /* 11 */ CHECK(p != NULL); free(p); SHOW_LEAKS();

    /* 12 */ CHECK(ft_calloc(3, -5) == NULL); SHOW_LEAKS();

    /* 13 */ CHECK(ft_calloc(-5, 3) == NULL); SHOW_LEAKS();

    write(1, "\nAll tests completed!\n", 21);
    return (0);
}
