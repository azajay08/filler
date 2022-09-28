/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:18:14 by ajones            #+#    #+#             */
/*   Updated: 2022/09/28 15:07:25 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	map_value(t_filler *data, int x, char *line)
{
	int	y;

	y = 0;
	while (y < data->m_width)
	{
		if (line[y] == data->goody || line[y] == data->goody + 32)
			data->map[x][y] = -1;
		else if (line[y] == data->baddy || line[y] == data->baddy + 32)
			data->map[x][y] = -2;
		else
			data->map [x][y] = 0;
		y++;
	}
}

/*if (check_x(line[y]) && check_x(data->goody))
			data->map[x][y] = -1;
		else if (check_o(line[y]) && check_o(data->baddy))
			data->map[x][y] = -1;*/

void	read_map(t_filler *data)
{
	char	*line;
	int		line_count;

	line_count = 0;
	get_next_line(0, &line);
	ft_strdel(&line);
	while (get_next_line(0, &line) > 0 && line_count < data->m_height)
	{
		line = ft_strchr(line, ' ' + 1);
		map_value(data, line_count, line);
		line_count++;
	}
}

int	**make_map(t_filler *data)
{
	int	**map;
	int	x;
	int	y;

	x = 0;
	map = (int **)malloc(sizeof(int *) * data->m_height);
	if (!map)
		return (NULL);
	while (x < data->m_height)
	{
		map[x] = (int *)malloc(sizeof(int) * data->m_width);
		if (!map[x])
			return (NULL);
		y = 0;
		while (y < data->m_width)
		{
			map[x][y] = 0;
			y++;
		}
		x++;
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
	
	data->got_map = 1;
	return (1);
}
