/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:09:50 by ahabdelr          #+#    #+#             */
/*   Updated: 2024/11/21 18:58:47 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"


void	ft_putchar(char c)
{
	write(1, &c, 1);
}