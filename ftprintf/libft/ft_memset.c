/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:02:07 by ahabdelr          #+#    #+#             */
/*   Updated: 2024/12/11 11:36:07 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *ptr, int value, size_t num)
{
	size_t	i;
	char	*ptr_int;

	i = 0;
	ptr_int = (char *)ptr;
	while (i < num)
	{
		ptr_int[i] = (char)value;
		i++;
	}
	return (ptr);
}
