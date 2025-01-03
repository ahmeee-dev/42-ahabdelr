/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:00:47 by ahabdelr          #+#    #+#             */
/*   Updated: 2024/12/23 09:23:40 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>
#include "../libft/libft.h"

void	ft_ptr(unsigned long ptr)
{
	char	*set;
	int		c;

	set = "0123456789abcdef";
	if (ptr >= 16)
		ft_ptr(ptr / 16);
	c = ptr % 16;
	write(1, &set[c], 1);
}

void	ptr_count(unsigned long ptr, int *i)
{
	if (ptr >= 16)
		ptr_count(ptr / 16, i);
	(*i)++;
}

void	ft_unsigned(unsigned int n, int q)
{
	char	*set;
	int		c;

	if (q == 1)
	{
		if (n >= 10)
			ft_unsigned(n / 10, q);
		c = (n % 10) + '0';
		write (1, &c, 1);
	}
	else if (q == 2)
	{
		set = "0123456789abcdef";
		if (n >= 16)
			ft_unsigned(n / 16, q);
		write(1, &set[n % 16], 1);
	}
	else if (q == 3)
	{
		set = "0123456789ABCDEF";
		if (n >= 16)
			ft_unsigned(n / 16, q);
		write(1, &set[n % 16], 1);
	}
}

void	unsigned_count(unsigned int n, int *i, int q)
{
	if (q == 1)
	{
		if (n >= 10)
			unsigned_count(n / 10, i, 1);
		(*i)++;
	}
	else if (q == 2)
	{
		if (n >= 16)
			unsigned_count(n / 16, i, 2);
		(*i)++;
	}
}
