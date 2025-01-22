/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:14:49 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/01/22 16:52:26 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fdf.h"
#include <unistd.h>
#include <stdio.h>

void	map_size_xy(int fd, t_map *map)
{
	char	*res;

	map->map_x = 0;
	map->map_y = 0;
	while (res != NULL)
	{
		res = get_next_line(fd);
		if (res)
		{
			map->map_x = ft_strlen(res);
			map->map_y++;
		}
	}
	close(fd);
}

void	map_placement(int fd, t_map *map)
{
	int	i;

	map->map_row = (char **)malloc(sizeof(char *) * map->map_y);
	while (i < map->map_y)
	{
		map->map_row[i] = get_next_line(fd);
		i++;
	}
}

void map_size(char *file, t_map *map)
{
	int	fd;

	file = ft_strjoin("testmaps/", file);
	file = ft_strjoin(file, ".fdf");
	fd = open(file, O_RDONLY);
	map_size_xy(fd, map);
	fd = open(file, O_RDONLY);
	map_placement(fd, map);
	close(fd);
}

