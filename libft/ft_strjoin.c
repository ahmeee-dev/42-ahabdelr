/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:00:21 by ahabdelr          #+#    #+#             */
/*   Updated: 2024/12/15 22:28:42 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	int		k;
	char	*new;

	i = 0;
	j = 0;
	k = -1;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	new = (char *)malloc(i + j + 1);
	if (!new)
		return (NULL);
	while (s1[++k] != '\0')
		new[k] = s1[k];
	i = k;
	k = -1;
	while (s2[++k] != '\0')
		new[k + i] = s2[k];
	new[i + k] = '\0';
	return (new);
}
