/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:13:10 by ahabdelr          #+#    #+#             */
/*   Updated: 2024/12/15 22:32:46 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_str;

	if (n == 0)
		return (NULL);
	s_str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (s_str[i] == (unsigned char)c)
			return (s + i);
		i++;
	}
	return (NULL);
}
