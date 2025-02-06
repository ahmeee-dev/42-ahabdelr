/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:56:16 by ahabdelr          #+#    #+#             */
/*   Updated: 2024/12/15 22:30:31 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dest_i;
	char	*src_i;

	dest_i = (char *)dest;
	src_i = (char *)src;
	i = 0;
	while (i < n)
	{
		dest_i[i] = src_i[i];
		i++;
	}
	return (dest);
}
