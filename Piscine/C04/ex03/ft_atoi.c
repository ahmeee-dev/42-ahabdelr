/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:28:51 by ahabdelr          #+#    #+#             */
/*   Updated: 2024/11/14 20:55:38 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i])
	{
		if (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)
			|| str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-' && (i >= 0) \
					&& (!(str[i - 1] >= '0' && str[i - 1] <= '9')))
				sign *= -1;
			else if ((i > 0) && (str[i - 1] >= '0' && str[i - 1] <= '9'))
				return (res * sign);
		}
		else if (str[i] >= '0' && str[i] <= '9')
			res = res * 10 + (str[i] - '0');
		else
			return (res * sign);
		i++;
	}
	return (res * sign);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	if (ac == 2)
		printf("%d", ft_atoi(av[1]));
	return (0);
}

int     ft_atoi(char *str);

int main() {
    // 1. Spazi all'inizio e alla fine della stringa
    char *str1 = " ---+--+1234+ab567";
    int result1 = ft_atoi(str1);
    printf("Test 1: %d\n", result1); // Risultato atteso: 456

    // 2. Spazi multipli all'interno della stringa
    char *str2 = "   4  5  6   ";
    int result2 = ft_atoi(str2);
    printf("Test 2: %d\n", result2); // Risultato atteso: 456

    // 3. Tabulazione all'inizio della stringa
    char *str3 = "\t456";
    int result3 = ft_atoi(str3);
    printf("Test 3: %d\n", result3); // Risultato atteso: 456

    // 4. Avanzamento di riga all'inizio della stringa
    char *str4 = "\n456";
    int result4 = ft_atoi(str4);
    printf("Test 4: %d\n", result4); // Risultato atteso: 456

    // 5. Caratteri di controllo all'inizio della stringa
    char *str5 = "\v456";
    int result5 = ft_atoi(str5);
    printf("Test 5: %d\n", result5); // Risultato atteso: 456

    // 6. Combinazione di spazi e caratteri di controllo all'inizio della stringa
    char *str6 = "   \t\n\v456";
    int result6 = ft_atoi(str6);
    printf("Test 6: %d\n", result6); // Risultato atteso: 456

    // 7. Stringa vuota
    char *str7 = "";
    int result7 = ft_atoi(str7);
    printf("Test 7: %d\n", result7); // Risultato atteso: 0

    // 8. Numero intero massimo
    char *str8 = "2147483647";
    int result8 = ft_atoi(str8);
    printf("Test 8: %d\n", result8); // Risultato atteso: 2147483647

    // 9. Numero intero minimo
    char *str9 = "-2147483648";
    int result9 = ft_atoi(str9);
    printf("Test 9: %d\n", result9); // Risultato atteso: -2147483648

    // 10. Overflow positivo
    char *str10 = "2147483648";
    int result10 = ft_atoi(str10);

    // 11. Overflow negativo
    char *str11 = "-2147483649";
    int result11 = ft_atoi(str11);
    printf("Test 11: %d\n", result11); // Risultato
}
*/
