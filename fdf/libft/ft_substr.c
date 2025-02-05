/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:19:58 by ahabdelr          #+#    #+#             */
/*   Updated: 2024/12/16 16:16:24 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	size_t	str_len;
	size_t	j;
	char	*new;

	j = 0;
	str_len = ft_strlen(str);
	if (str_len == 0 || start >= str_len)
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
