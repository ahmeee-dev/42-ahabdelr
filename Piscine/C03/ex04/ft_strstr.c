/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:25:41 by ahabdelr          #+#    #+#             */
/*   Updated: 2024/11/12 14:57:25 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	n;
	int	j;

	j = 0;
	if (to_find[j] == '\0')
		return (&str[j]);
	while (str[j] != '\0')
	{
		n = 0;
		while (to_find[n] == str[j + n])
		{
			if (to_find[n + 1] == '\0')
			{
				return (&str[j]);
			}
			n++;
		}
		j++;
	}
	return (0);
}
