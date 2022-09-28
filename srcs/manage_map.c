/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:18:14 by ajones            #+#    #+#             */
/*   Updated: 2022/09/28 23:32:33 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

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

int	manage_map(t_filler *data, char *line)
{
	if (data->got_map == 0)
		data->map = make_map(data);
	if (!data->map)
		return (0);
	read_map(data);
	if (!data->map)
		return (0);
	heatmap_value(data);
	data->got_map = 1;
	return (1);
}
