/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:22:43 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/01/03 11:04:48 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

void	new_line_in_rest(char **rest, int k, int *i);
void	ft_strjoin(char **result, char *str);
int	ft_strlen_till(char *str);

void	rest_creation(char **temp, char **str, int n, int i)
{
	char	*new_temp;
	int	j;

	j = 0;
	(*str)[i] = '\n';
	i++;
	(*str)[n] = '\0';
	new_temp = (char *)malloc(n - i + 1);
	while((*str)[i + j] != '\0')
	{
		new_temp[j] = (*str)[i + j];
		j++;
	}
	(*str)[i] = '\0';
	new_temp[j] = '\0';
	(*temp) = new_temp;
}

void	rest_copy(char **rest,char **result, int *i)
{
	int	j;
	int	size;

	j = 0;
	size = ft_strlen_till(*rest);
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
	}
}
char	*get_next_line(int fd)
{
	char	*str;
	static char	*rest;
	char	*result;
	int	i;
	int	n;

	n = BUFFER_SIZE;
	i = 0;
	if (fd < 0)
		return (NULL);
	rest_copy(&rest, &result, &i);
	if (i != 0)
	return (result);
	str = (char *)malloc(BUFFER_SIZE + 1);
	while (n == BUFFER_SIZE)
	{
		n = read(fd, str, BUFFER_SIZE);
		if (n > 0)
			str[n] = '\0';
		while (n > 0 && str[i] != '\0')
		{
			if (str[i] == '\n' && i < n -1)
			{
				rest_creation(&rest, &str, n, i);
				n = -2;
			}
			else if (str[i] == '\0')
				n = -3;
			i++;
		}
		i = 0;
		if (i != -3)
			ft_strjoin(&result, str);
	}
	return (result);
}

int	main()
{
	int	fd;

	fd = open("file.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	close(fd);
	return (0);
}