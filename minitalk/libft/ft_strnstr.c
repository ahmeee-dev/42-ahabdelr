/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 09:37:12 by ahabdelr          #+#    #+#             */
/*   Updated: 2024/12/15 22:24:49 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(char *big, char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!big)
		return (NULL);
	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] != '\0')
	{
		j = 0;
		while ((big[i + j] == little[j]) && (i + j) < len)
		{
			if (little[j + 1] == '\0' || j + i == len)
				return (big + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
