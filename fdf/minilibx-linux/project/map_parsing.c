/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:14:49 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/01/24 18:49:07 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fdf.h"
#include <unistd.h>
#include <stdio.h>


int	find_occurrence(char *str)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' && i > 0 && (str[i - 1] != ' '))
			res++;
		i++;
	}
	if (i > 0 && !(str[i - 1] == ' '))
		res++;
	return (res);
}

// da gestire i free di gnl
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
		res = get_next_line(fd);
	}
	free(res);
	close(fd);
}

void	map_size(t_map *map)
{
	
	map->file = ft_strjoin(map->file, ".fdf");
	map->fd = open(map->file, O_RDONLY);
	map_size_xy(map->fd, map);
}

