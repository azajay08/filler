/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:18:14 by ajones            #+#    #+#             */
/*   Updated: 2022/09/29 13:55:21 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/* 
** map_value checks for the the character concerning each player, uppercase and
** lowercase. If it see the '.' then it will have a value of 0. If the
** character is the one that I have been assigned, it will be given the value
** of -1. The enemies character will be given -2
*/

void	map_value(t_filler *data, int y, char *line)
{
	int	x;

	x = 0;
	while (x < data->m_width)
	{
		if (line[x] == data->goody || line[x] == data->goody + 32)
			data->map[y][x] = -1;
		else if (line[x] == data->baddy || line[x] == data->baddy + 32)
			data->map[y][x] = -2;
		else
			data->map [y][x] = 0;
		y++;
	}
}

/*
** This will read the lines until it is at the actual grid and disregard the 
** numbers before the grid on each line. Because it is a 2D array, it will loop
** through each line sending the the line to the next function.
*/

void	read_map(t_filler *data)
{
	char	*line;
	int		line_count;

	line_count = 0;
	get_next_line(0, &line);
	ft_strdel(&line);
	while (get_next_line(0, &line) > 0 && line_count < data->m_height)
	{
		line = ft_strchr(line, ' ') + 1;
		map_value(data, line_count, line);
		ft_strdel(&line);
		line_count++;
	}
}

/*
** Standard mallocing for a 2D int array using map height and width
*/

int	**make_map(t_filler *data)
{
	int	**map;
	int	x;
	int	y;

	y = 0;
	map = (int **)malloc(sizeof(int *) * data->m_height);
	if (!map)
		return (NULL);
	while (y < data->m_height)
	{
		map[y] = (int *)malloc(sizeof(int) * data->m_width);
		if (!map[y])
			return (NULL);
		x = 0;
		while (x < data->m_width)
		{
			map[y][x] = 0;
			x++;
		}
		y++;
	}
	return (map);
}

/* 
** the got_map variable is basically a switch that tells us whether
** this is the first time coming into this function or not. If it is
** the first time. It will be the only time that the map will be malloced 
*/

int	manage_map(t_filler *data)
{
	if (data->got_map == 0)
		data->map = make_map(data);
	if (!data->map)
		return (0);
	read_map(data);
	if (!data->map)
		return (0);
	set_heatmap(data);
	data->got_map = 1;
	return (1);
}
