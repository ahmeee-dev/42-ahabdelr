/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 20:59:14 by ahabdelr          #+#    #+#             */
/*   Updated: 2024/12/15 22:18:37 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static size_t	ft_nbr_to_len(int n);
static void		ft_nbr_to_str(char *s, int n, int new_len);

char	*ft_itoa(int n)
{
	char	*new;
	size_t	new_len;

	new_len = ft_nbr_to_len(n);
	new = (char *)malloc(sizeof(char) * (new_len + 1));
	if (new == NULL)
		return (NULL);
	new[new_len] = '\0';
	ft_nbr_to_str(new, n, (new_len - 1));
	return (new);
}

static size_t	ft_nbr_to_len(int n)
{
	size_t			i;
	long long int	nbr;

	nbr = (long long int)n;
	i = 0;
	if (nbr <= 0)
	{
		i++;
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

static void	ft_nbr_to_str(char *s, int n, int new_len)
{
	long long int	nbr;

	nbr = (long long int)n;
	if (nbr < 0)
	{
		nbr = -nbr;
		s[0] = '-';
	}
	if (nbr > 9)
		ft_nbr_to_str(s, (nbr / 10), (new_len - 1));
	s[new_len] = nbr % 10 + '0';
}
