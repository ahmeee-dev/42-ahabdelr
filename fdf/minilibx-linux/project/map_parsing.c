/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin@42.fr <ahabdelr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:14:49 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/02/05 13:42:28 by marvin@42.f      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include <stdio.h>
#include <unistd.h>

int	find_occurrence(char *str)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		if (str[i] == ' ' && i > 0 && (str[i - 1] != ' '))
			res++;
		i++;
	}
	if (i > 0 && !(str[i - 1] == ' '))
		res++;
	return (res);
}

void	map_size_xy(int fd, t_map *map)
{
	char	*res;

	map->map_x = 0;
	map->map_y = 0;
	res = get_next_line(fd);
	map->map_x = find_occurrence(res);
	while (res != NULL)
	{
		if (res)
			map->map_y++;
		if (ft_strlen(res) > 1 && find_occurrence(res) != map->map_x)
		{
			ft_printf("Errore durante la lettura della mappa: uneven map");
			free(res);
			exit(0);
		}
		free(res);
		res = get_next_line(fd);
	}
	free(res);
	close(fd);
}

void	map_size(t_map *map)
{
	map->fd = open(map->file, O_RDONLY);
	if (map->fd <= 0)
	{
		ft_printf("Errore all'apertura del file: No such file or directory");
		exit(0);
	}
	map_size_xy(map->fd, map);
}
