/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:32:04 by ahabdelr          #+#    #+#             */
/*   Updated: 2024/12/23 21:48:56 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *s, size_t t)
{
	size_t			i;
	unsigned char	*s_char;

	s_char = (unsigned char *)s;
	i = 0;
	if (t == 0 || !s)
		return ;
	while (i < t)
	{
		s_char[i] = '\0';
		i++;
	}
}
