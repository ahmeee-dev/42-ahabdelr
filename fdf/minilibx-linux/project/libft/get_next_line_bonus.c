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

#include "libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

void	ft_strjoin_line(char **result, char **str);
void	new_line_in_rest(char **rest, int k, int *i);
int		ft_strlen_type(char *str, int type);
int		first_call(int *i, int *n, int fd);

char	*last_call(char **str, char **result)
{
	free(*str);
	return (*result);
}

char	*ft_free(char **str)
{
	if (*str && str)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}

void	rest_creation(char **rest, char **str, int i)
{
	char	*new_temp;
	int		n;

	n = 0;
	new_temp = (char *)malloc(ft_strlen_type(*str, 1) - i);
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
	size = ft_strlen_type(*rest, 2);
	if (size == 0)
		(*result) = ft_free(rest);
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
		else if (rest && *rest)
			ft_free(rest);
	}
}

char	*get_next_line(int fd)
{
	static char	*rest[FOPEN_MAX];
	char		*result;
	char		*str;
	int			i;
	int			n;

	if (!first_call(&i, &n, fd))
		return (NULL);
	rest_copy(&rest[fd], &result, &i);
	str = (char *)malloc(BUFFER_SIZE + 1);
	while (i == n)
	{
		n = read(fd, str, BUFFER_SIZE);
		if (n < 0 || (n == 0 && result == NULL))
			return (ft_free(&str));
		str[n] = '\0';
		if (n > 0)
		{
			i = ft_strlen_type(str, 3);
			if (i != n && i >= 0 && i < n - 1)
				rest_creation(&rest[fd], &str, i);
		}
		ft_strjoin_line(&result, &str);
	}
	return (last_call(&str, &result));
}
