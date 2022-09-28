/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_map2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 23:27:39 by ajones            #+#    #+#             */
/*   Updated: 2022/09/29 00:44:01 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	temp_calc(int y, int x, int co_y, int co_x)
{
	int	value_y;
	int	value_x;

	value_y = 0;
	value_x = 0;
	if (y > co_y)
		value_y = y - co_y;
	else
		value_y = co_y - y;
	if (x > co_x)
		value_x = x - co_x;
	else
		value_x = co_x - x;
	return (value_y + value_x);
}

int	heatmap_value(t_filler *data, int co_y, int co_x)
{
	int	temp;
	int	value;
	int	y;
	int	x;

	temp = 0;
	value = 0;
	y = 0;
	while (y < data->m_height)
	{
		x = 0;
		while (x < data->m_width)
		{
			if (data->map[y][x] == -2)
			{
				temp = temp_calc(y, x, co_y, co_x);
				if (temp < value || value == 0)
					value = temp;
			}
			x++;
		}
		y++;
	}
	return (value);
}

void	set_heatmap(t_filler *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->m_height)
	{
		x = 0;
		while (x < data->m_width)
		{
			if (data->map[y][x] == 0)
				data->map[y][x] = heatmap_value(data, y, x);
			x++;
		}
		y++;
	}
}
