/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:18:14 by ajones            #+#    #+#             */
/*   Updated: 2022/09/28 01:58:33 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

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
	data->got_map = 1;
	return (1);
}
