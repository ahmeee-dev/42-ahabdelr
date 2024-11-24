/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:56:29 by ahabdelr          #+#    #+#             */
/*   Updated: 2024/11/19 12:18:46 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char	*ft_join(int size, char **strs, char *sep, char *dest)
{
	int	i;
	int	d;
	int	s;
	int	j;

	i = -1;
	d = -1;
	while (++i < size)
	{
		j = -1;
		while (strs[i][++j] != '\0')
			dest[++d] = strs[i][j];
		if (i < size - 1)
		{
			s = -1;
			while (sep[++s] != '\0')
				dest[++d] = sep[s];
		}
	}
	dest[++d] = '\0';
	return (dest);
}

char	*ft_destruction(char *dest)
{
	dest = (char *)malloc(1);
	dest[0] = '\0';
	return (dest);
} 

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		n;
	char	*dest;
	int		total;
	
	if (size == 0)
		return (ft_destruction(dest));
	total = 0;
	n = 0;
	i = 0;
	while (sep[n] != '\0')
		n++;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
			j++;
		total += j;
		i++;
	}
	dest = (char *)malloc(total + n * (size - 1) + 1);
	dest = ft_join(size, strs, sep, dest);
	return (dest);
}
/*
#include <stdio.h>

int	main(void)
{
	// Test 1: Unire alcune parole con uno spazio come separatore
	char *words1[] = {"Hello", "World", "This", "is", "C"};
	char *result1 = ft_strjoin(5, words1, " ");
	printf("Test 1: '%s'\n", result1);
	free(result1);

	// Test 2: Unire parole senza separatore
	char *words2[] = {"Apple", "Banana", "Cherry"};
	char *result2 = ft_strjoin(3, words2, "");
	printf("Test 2: '%s'\n", result2);
	free(result2);

	// Test 3: Unire parole con un separatore specifico
	char *words3[] = {"John", "Doe", "is", "learning", "C"};
	char *result3 = ft_strjoin(5, words3, "-");
	printf("Test 3: '%s'\n", result3);
	free(result3);

	// Test 4: Caso con un solo elemento
	char *words4[] = {"Single"};
	char *result4 = ft_strjoin(1, words4, ",");
	printf("Test 4: '%s'\n", result4);
	free(result4);

	return (0);
}*/
