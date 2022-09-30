/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_map2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 23:27:39 by ajones            #+#    #+#             */
/*   Updated: 2022/09/30 23:10:15 by ajones           ###   ########.fr       */
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

/*
** This comes into this function with the coordinates of the empty place
** and compares it with the coordinates of an enemy place. Depending on 
** what the coordinate values are for each, it gets the heatmap value using the
** temp_calc function. the smallest value form the calculations will be set
** as that empty spaces heatmap value
*/

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
				if (temp < value || value == NO_VALUE)
					value = temp;
			}
			x++;
		}
		y++;
	}
	return (value);
}

/*
** This checks for places in the map that has the value of 0 (empty), so that
** it can give it a heatmap value in the next function
*/

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
