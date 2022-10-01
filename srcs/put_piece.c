/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 01:07:38 by ajones            #+#    #+#             */
/*   Updated: 2022/10/01 03:23:10 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	check_placement(t_filler *data, t_piece *piece, int y, int x)
{
	if (data->map[y][x] == -2)
		return (NOT_VALID);
	
}

int	in_bounds(t_filler *data, int y, int x)
{
	if (y >= data->m_height)
		return (0);
	if (x >= data->m_height)
		return (0);
	return (1);
}

int	is_valid(t_filler *data, t_piece *piece, int y, int x)
{
	int	y_off;
	int	x_off;
	//int	valid;

	//valid = 0;
	y_off = 0;
	while (y_off < piece->p_height)
	{
		x_off = 0;
		while (x_off < piece->p_width)
		{
			if (piece->p_map[y_off][x_off] == 1)
			{
				if (in_bounds(data, y + y_off, x + x_off)) /* cant do this, needs to be within check placement*/
				{
					if (!check_placement(data, piece, y + y_off, x + x_off))
						return (NOT_VALID);
				}
			}
			x_off++;
		}
		y_off++;
	}
	//if (!valid) /* valid check here? */
	//	return (0);
	return (1);
}

int	check_piece(t_filler *data, t_piece *piece)
{
	int	valid;
	int	y;
	int	x;

	y = 0;
	valid = 0;
	while ((y - piece->min_y) < data->h_boundary)
	{
		x = 0;
		while ((x - piece->min_x) < data->w_boundary)
		{
			if (is_valid(data, piece, y - piece->min_y, x - piece->min_x))
			{
				valid++;
			}	
			x++;
		}
		y++;;
	}
	if (valid == 0)
		return (0);
	return (1);
}
