/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:13:10 by ahabdelr          #+#    #+#             */
/*   Updated: 2024/12/10 18:28:05 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void *ft_memchr(void *s, int c, size_t n)
{
	size_t	i;
	unsigned char	*s_str;

	s_str = (unsigned char *)s;
	i = 0;
	while (s_str[i] != '\0' && i < n)
	{
		if (s_str[i] == (unsigned char)c)
			return (s + i);
		i++;
	}
	return (NULL);
}