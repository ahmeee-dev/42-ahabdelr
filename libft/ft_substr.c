/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:19:58 by ahabdelr          #+#    #+#             */
/*   Updated: 2024/12/15 22:33:23 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

char	*ft_substr(char *str, unsigned int start, size_t len)
{
	size_t	str_len;
	size_t	j;
	char	*new;

	j = 0;
	str_len = 0;
	while (str[str_len] != '\0')
	{
		str_len++;
	}
	if (start >= str_len)
		len = 0;
	else if (start + len > str_len)
		len = str_len - start;
	new = (char *)malloc(len + 1);
	if (!new)
		return (NULL);
	while (j < len)
	{
		new[j] = str[start + j];
		j++;
	}
	new[j] = '\0';
	return (new);
}
