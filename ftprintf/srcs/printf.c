/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:42:37 by ahabdelr          #+#    #+#             */
/*   Updated: 2024/12/23 09:58:26 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_printf.h"
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

void	ft_ptr(unsigned long ptr);
void	ptr_count(unsigned long ptr, int *i);
void	unsigned_count(unsigned int n, int *i, int q);
void	ft_unsigned(unsigned int n, int q);

void	int_count(int n, int *count)
{
	if (n == -2147483648)
	{
		(*count) += 11;
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		(*count)++;
	}
	if (n >= 10)
		int_count(n / 10, count);
	(*count)++;
}

void	str_count(va_list *jul, int *count)
{
	const char	*str;

	str = va_arg(*jul, const char *);
	if (!str)
		(*count) += 6;
	else
		(*count) += ft_strlen((const char *)str);
}

void	ft_count(char c, va_list *jul, int *count)
{
	if (c == 's')
		str_count(jul, count);
	else if (c == '%')
		(*count)++;
	else if (c == 'c')
	{
		va_arg(*jul, char *);
		(*count)++;
	}
	else if (c == 'd' || c == 'i')
		int_count(va_arg(*jul, int), count);
	else if (c == 'p')
	{
		write(1, "0x", 2);
		ptr_count(va_arg(*jul, unsigned long), count);
		(*count) += 2;
	}
	else if (c == 'u')
		unsigned_count(va_arg(*jul, unsigned int), count, 1);
	else if (c == 'x' || c == 'X')
		unsigned_count(va_arg(*jul, unsigned int), count, 2);
}

void	ft_checks(char c, va_list *jul)
{
	char	*str;

	if (c == 'c')
		ft_putchar_fd(va_arg(*jul, int), 1);
	else if (c == 's')
	{
		str = va_arg(*jul, char *);
		if (str == NULL)
			write(1, "(null)", 6);
		else
			ft_putstr_fd(str, 1);
	}
	else if (c == 'd' || c == 'i')
		ft_putnbr_fd(va_arg(*jul, int), 1);
	else if (c == 'p')
		ft_ptr((unsigned long)va_arg(*jul, void *));
	else if (c == 'u')
		ft_unsigned(va_arg(*jul, unsigned int), 1);
	else if (c == 'x')
		ft_unsigned(va_arg(*jul, unsigned int), 2);
	else if (c == 'X')
		ft_unsigned(va_arg(*jul, unsigned int), 3);
	else if (c == '%')
		write(1, "%", 1);
}

int	ft_printf(const char *str, ...)
{
	int	count;
	int	i;

	va_list(jul);
	va_list(copy);
	va_start(jul, str);
	va_copy(copy, jul);
	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i] + 1)
		{
			ft_count(str[i + 1], &copy, &count);
			ft_checks(str[i + 1], &jul);
			i += 2;
		}
		if (str[i] != '\0' && str[i] != '%')
		{
			write(1, &str[i], 1);
			i++;
			count++;
		}
	}
	return (count);
}
