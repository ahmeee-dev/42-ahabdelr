/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:36:31 by ahabdelr          #+#    #+#             */
/*   Updated: 2024/12/24 00:24:59 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_external(char c, va_list *jul);
int		ft_printf(const char *str, ...);
void	ft_ptr(unsigned long ptr);
void	ptr_count(unsigned long ptr, int *i);
void	unsigned_count(unsigned int n, int *i, int q);
void	ft_unsigned(unsigned int n, int q);

#endif