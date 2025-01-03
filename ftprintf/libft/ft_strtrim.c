/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:29:55 by ahabdelr          #+#    #+#             */
/*   Updated: 2024/12/20 11:29:37 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	sep_check(char c, char const *sep)
{
	int	i;

	i = 0;
	if (sep == NULL)
		return (0);
	while (sep[i] != '\0')
	{
		if (c == sep[i])
			return (1);
		i++;
	}
	return (0);
}

static int	fullcheck(char const *s1, char const *sep)
{
	int	j;

	j = 0;
	if (s1 == NULL || sep == NULL)
		return (1);
	while (sep_check(s1[j], sep) == 1)
		j++;
	if (s1[j] == '\0')
		return (1);
	else
		return (0);
}

static char	*returner(void)
{
	char	*str;

	str = (char *)malloc(1);
	str[0] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	int		start;
	int		end;
	int		index;
	char	*dest;

	len = -1;
	start = 0;
	end = 0;
	index = 0;
	if (fullcheck(s1, set) == 1)
		return (returner());
	while (s1[++len] != '\0')
		if ((sep_check(s1[len], set) == 1) && start == len)
			start++;
	while (sep_check(s1[len - end - 1], set) == 1)
		end++;
	dest = (char *)malloc(len - end - start + 1);
	while ((start + index) < len - end)
	{
		dest[index] = s1[start + index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}
