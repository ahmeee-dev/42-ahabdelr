/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 21:17:17 by ahabdelr          #+#    #+#             */
/*   Updated: 2024/12/15 22:21:58 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static size_t	ft_wordcounter(const char *s, const char c);
static char		**ft_ssalloc(const char *s, const char c);
static char		**ft_salloc(char **ss, const char *s, size_t *k, size_t cnt);
static void		*ft_ssdestroy(char **ss);

char	**ft_split(const char *s, char c)
{
	char	**ss;
	size_t	i;
	size_t	k;
	size_t	cnt;

	i = 0;
	k = 0;
	ss = ft_ssalloc(s, c);
	if (ss == NULL || *s == '\0')
		return (ss);
	while (s[i] != '\0')
	{
		cnt = 0;
		if (s[i] == c)
			i++;
		else
		{
			while (s[i + cnt] != '\0' && s[i + cnt] != c)
				cnt++;
			if (ft_salloc(ss, &(s[i]), &k, cnt) == NULL)
				return (ft_ssdestroy(ss));
		}
		i += cnt;
	}
	return (ss);
}

static size_t	ft_wordcounter(const char *s, const char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			words++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (words);
}

static char	**ft_ssalloc(const char *s, const char c)
{
	char	**ss;
	size_t	n;

	n = ft_wordcounter(s, c);
	ss = (char **)malloc(sizeof(char *) * (n + 1));
	if (ss == NULL)
		return (NULL);
	ss[n] = NULL;
	return (ss);
}

static char	**ft_salloc(char **ss, const char *s, size_t *k, size_t cnt)
{
	size_t	i;

	i = 0;
	if (s == NULL || cnt == 0)
		return (NULL);
	ss[*k] = (char *)malloc(sizeof(char) * (cnt + 1));
	if (ss[*k] == NULL)
		return (NULL);
	while (i < cnt)
	{
		ss[*k][i] = s[i];
		i++;
	}
	ss[*k][i] = '\0';
	*k += 1;
	return (ss);
}

static void	*ft_ssdestroy(char **ss)
{
	while (ss != NULL)
	{
		free(*ss);
		(*ss)++;
	}
	free(ss);
	return (NULL);
}
