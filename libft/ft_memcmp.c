/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 08:55:35 by ahabdelr          #+#    #+#             */
/*   Updated: 2024/12/11 09:34:39 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(void *s1, void *s2, size_t n)
{
	size_t	i;
	unsigned char	*s1_str;
	unsigned char	*s2_str;

	if (n == 0)
		return (0);
	s1_str = (unsigned char *)s1;
	s2_str = (unsigned char *)s2;
	i = 0;
	while ((s1_str[i] == s2_str[i]) && 1 < n)
	{
		i++;
	}
	return (s1_str[i] - s2_str[i]);
}