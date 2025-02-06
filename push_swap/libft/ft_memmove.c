/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:10:46 by ahabdelr          #+#    #+#             */
/*   Updated: 2024/12/15 22:20:43 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dest_i;
	char	*src_i;

	if (!dest || !src)
		return (NULL);
	dest_i = (char *)dest;
	src_i = (char *)src;
	i = 0;
	if (dest_i < src_i)
		ft_memcpy(dest_i, src_i, n);
	else
	{
		i = n;
		while (i > 0)
		{
			dest_i[i - 1] = src_i[i - 1];
			i--;
		}
	}
	return (dest);
}
