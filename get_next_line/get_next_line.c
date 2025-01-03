/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:20:56 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/01/03 14:52:48 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

int		ft_strchr(char *s, int c);
void	ft_strjoin(char **result, char *str);
void	new_line_in_rest(char **rest, int k, int *i);
int		ft_strlen(char *str, int type);

void	rest_creation(char **rest, char **str, int i)
{
	char	*new_temp;
	int		n;

	n = 0;
	new_temp = (char *)malloc(ft_strlen(*str, 1) - i);
	i++;
	while ((*str)[i + n] != '\0')
	{
		new_temp[n] = (*str)[i + n];
		n++;
	}
	new_temp[n] = '\0';
	(*str)[i] = '\0';
	(*rest) = new_temp;
}

void	rest_copy(char **rest, char **result, int *i)
{
	int	j;
	int	size;

	j = 0;
	size = ft_strlen(*rest, 2);
	if (size == 0)
		(*result) = NULL;
	else
	{
		(*result) = (char *)malloc(size + 1);
		while (j < size)
		{
			(*result)[j] = (*rest)[j];
			j++;
		}
		(*result)[j] = '\0';
		if ((*rest)[j - 1] == '\n')
			new_line_in_rest(rest, j, i);
		else
			free(*rest);
	}
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*result;
	char		*str;
	int			i;
	int			n;

	i = -2;
	n = -2;
	rest_copy(&rest, &result, &i);
	if (i == -3)
		return (result);
	str = (char *)malloc(BUFFER_SIZE + 1);
	while (i == n)
	{
		n = read(fd, str, BUFFER_SIZE);
		str[n] = '\0';
		if (n < 0)
			return (NULL);
		else if (n > 0)
		{
			i = ft_strchr(str, '\n');
			if (i != n && i >= 0 && i < n - 1)
				rest_creation(&rest, &str, i);
		}
		else if (n == 0 && i == -2 && result == NULL)
			return (NULL);
		ft_strjoin(&result, str);
	}
	return (result);
}

// int	main(void)
// {
// 	int fd;

// 	fd = open("file.txt", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	return (0);
// }