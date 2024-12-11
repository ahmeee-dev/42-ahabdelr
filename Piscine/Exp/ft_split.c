/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:56:45 by ahabdelr          #+#    #+#             */
/*   Updated: 2024/11/22 12:19:56 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_count_words(char *str)
{
	int	words = 0;
	while (*str)
	{
		while (*str && (*str == ' ' || *str == '\t' || *str == '\n'))
			str++;
		if (*str)
		{
			words++;
			while (*str && (*str != ' ' && *str != '\n' && *str != '\t'))
				str++;
		}
	}
	return (words);
}

int	ft_word_len(*str)
{
	int	letters;

	letters = 0;
	while (*str && (*str != ' ' && !(*str >= 9 && *str <= 13)))
	{
		str++;
		letters++;
	}
	return (letters);
}

char *copy(char *str, int len)
{
	int i = 0;
	char *dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return NULL;
	while (i < len)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char **ft_split(char *str)
{
	int	index = count_words(str);
	int	len = 0;
	int	i = 0;
	char	**tab = malloc(sizeof(char *) * (index + 1));
	if (!tab)
		return NULL;
	while (*str)
	{
		while (*str && (*str == ' ' || *str == '\t' || *str == '\n'))
			str++;
		if (*str)
		{
			len = ft_word_len(str);
			tab[i] = copy(str, len);
			i++;
			str += len;
		}
	}
	tab[i] = NULL;
	return (tab);
}
