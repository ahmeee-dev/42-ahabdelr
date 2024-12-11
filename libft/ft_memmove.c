/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:10:46 by ahabdelr          #+#    #+#             */
/*   Updated: 2024/12/10 14:37:28 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"
#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dest_i;
	char	*src_i;

	dest_i = (char *)dest;
	src_i = (char *)src;
	i = 0;
	if (dest_i < src_i)
	{
		while (i < n)
		{
			dest_i[i] = src_i[i];
			i++;
		}
	}
	else if (dest_i >= src_i)
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
