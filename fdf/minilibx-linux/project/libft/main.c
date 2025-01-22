#include "libft.h"
#include <stdarg.h>

int main()
{
    int fd = open("file.txt", O_RDWR);
   ft_printf("res:\t %s", get_next_line(fd));
    return 0;
}