/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:10:18 by ahabdelr          #+#    #+#             */
/*   Updated: 2024/11/25 20:08:21 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
		{
			if (c == charset[i])
				return (1);
			i++;
		}
	return (0);
}

void	ft_position(char *str, char **dest, char *charset)
{
	int	i;
	int	count;
	int	dest_count;

	dest_count = 0;
        count = 0;
        i = 0;
        while (str[i] != '\0')
        {
        	if (is_sep(str[i], charset) == 1 && count != 0)
			{
				dest[dest_count] = (char *)malloc(count + 1);
				count = 0;
				dest_count++;
			}
        	else if (str[i+1] == '\0' && count != 0)
			{
				dest[dest_count] = (char *)malloc(count + 1);
				count = 0;
				dest_count++; 
			}
            else if (is_sep(str[i], charset) == 0)
                count++;
            i++;
        }
}

void	putstr(char *str, char *charset, char **dest)
{
	int		i;
	int		count;
	int		j;

	j = 0;
	i = 0;
	count = 0;
	while (str[j] != 0)
	{
		if (is_sep(str[j], charset) == 1 && count != 0)
		{
			dest[i][count] = '\0';
			count = 0;
			i++;
		}
		else if (is_sep(str[j], charset) == 0)
		{
			dest[i][count] = str[j];
			count++;
		}
		j++;
	}
	*dest[i] = '\0';
}

char	**ft_split(char *str, char *charset)
{
	int	i;
	int	words;
	char	**dest;
	int	count;

	count = 0;
	words = 0;
	i = 0;
	while (str[i])
	{
		if (is_sep(str[i], charset) == 1 && count != 0)
		{
			words++;
			count = 0;
		}
		else if (str[i+1] == '\0' && count != 0)
		{
			count++;
			words++;
		}
		else if (is_sep(str[i], charset) == 0)
			count++;
		i++;
	}
	*dest = (char *)malloc(words+1);
	ft_position(str, dest, charset);
	putstr(str, charset, dest);
}