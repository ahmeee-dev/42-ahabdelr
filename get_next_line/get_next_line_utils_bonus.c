/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:22:34 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/01/03 14:53:51 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_strjoin(char **result, char **str)
{
	int		res_len;
	int		str_len;
	int		counter;
	int		i;
	char	*result_str;

	i = 0;
	counter = 0;
	res_len = ft_strlen(*result, 1);
	str_len = ft_strlen(*str, 1);
	result_str = (char *)malloc(res_len + str_len + 1);
	while (res_len > 0 && (*result)[counter] != '\0')
	{
		result_str[counter] = (*result)[counter];
		counter++;
	}
	while (str_len > 0 && (*str)[i] != '\0')
	{
		result_str[counter] = (*str)[i];
		counter++;
		i++;
	}
	result_str[counter] = '\0';
	free(*result);
	(*result) = result_str;
}

void	new_line_in_rest(char **rest, int k, int *i)
{
	int		j;
	char	*new_rest;

	new_rest = (char *)malloc(ft_strlen(*rest, 1) - k + 1);
	j = 0;
	while ((*rest)[k + j] != '\0')
	{
		new_rest[j] = (*rest)[k + j];
		j++;
	}
	new_rest[j] = '\0';
	free(*rest);
	(*rest) = new_rest;
	(*i) = 1;
}

int	ft_strlen(char *str, int type)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (type == 1)
	{
		while (str[i] != '\0')
			i++;
		return (i);
	}
	else if (type == 2 || type == 3)
	{
		while (str[i] != '\0' && str[i] != '\n')
			i++;
		if (str[i] == '\n' && type == 2)
			i++;
		return (i);
	}
	else
		return (0);
}

int	first_call(int *i, int *n, int fd)
{
	if (fd > FOPEN_MAX)
		return (0);
	*i = -2;
	*n = -2;
	return (1);
}
