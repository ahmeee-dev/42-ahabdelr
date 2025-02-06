/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:00:21 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/01/22 09:53:04 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*god(const char *s1, const char *s2)
{
	char	*new;
	int		i;

	i = 0;
	if (!s1)
		return (NULL);
	else if (!s2)
	{
		new = (char *)malloc(ft_strlen(s1) + 1);
		while (i < ft_strlen(s1))
		{
			new[i] = s1[i];
			i++;
		}
		new[i] = '\0';
		return (new);
	}
	return (NULL);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	int		k;
	char	*new;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	k = 0;
	if (!s1 || !s2)
		return (god(s1, s2));
	new = (char *)malloc(i + j + 1);
	while (s1[k] != '\0')
	{
		new[k] = s1[k];
		k++;
	}
	i = k;
	k = 0;
	while (s2 && s2[k] != '\0')
	{
		new[k + i] = s2[k];
		k++;
	}
	new[i + k] = '\0';
	return (new);
}
