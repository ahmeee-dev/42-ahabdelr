/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:20:54 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/01/02 19:20:51 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_strjoin(char **result, char *str)
{
	int	res_len;
	int	str_len;
	int	counter;
	int	i;
	char	*result_str;

	i = 0;
	counter = 0;
	res_len = ft_strlen(*result);
	str_len = ft_strlen(str);
	result_str = (char *)malloc(res_len + str_len + 1);
	while (res_len > 0 && (*result)[counter] != '\0')
	{
		result_str[counter] = (*result)[counter];
		counter++;
	}
	while (str_len > 0 && str[i] != '\0')
	{
		result_str[counter] = str[i];
		counter++;
		i++;
	}
	result_str[counter] = '\0';
	// free(*result);
	// free(str);
	(*result) = result_str;
}

int	ft_strlen_till(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

void	new_line_in_rest(char **rest, int k, int *i)
{
	int	j;
	char	*new_rest;

	new_rest = (char *)malloc(ft_strlen(*rest) - k + 1);
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