/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:36:35 by ahabdelr          #+#    #+#             */
/*   Updated: 2024/12/10 16:38:30 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;	

	i = 0;
	dest_len =  0;
	src_len = 0;
	while (dest[dest_len] != '\0')
		dest_len++;
	if (dest_len >= size)
		return (dest_len + src_len - 1);
	while (src[src_len] != '\0')
		src_len++;
	while ((dest_len + i) < (size - 1) && src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len - 1);
}

