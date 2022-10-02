/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 01:07:38 by ajones            #+#    #+#             */
/*   Updated: 2022/10/02 21:58:13 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*void	put_coords(t_piece *piece)
{
	
}
*/

void	free_piece(t_piece *piece)
{
	int	p;

	p = 0;
	while (p < piece->p_height)
	{
		free(piece->p_map[p]);
		p++;
	}
	free(piece);
}

void	best_values(t_filler *data, t_piece *piece, int y, int x)
{
	if (piece->best_val == -1 || data->map_val < piece->best_val)
	{
		piece->best_val = data->map_val;
		piece->best_y = y;
		piece->best_x = x;
	}
}

int	check_placement(t_filler *data, t_piece *piece, int y, int x)
{
	if (data->map[y][x] == -2)
		return (NOT_VALID);
	else if (data->map[y][x] == -1)
	{
		piece->overlap++;
		if (piece->overlap > 1)
			return (NOT_VALID);
	}
	else
		data->map_val += data->map[y][x];
	return (1);
}

int	is_valid(t_filler *data, t_piece *piece, int y_off, int x_off)
{
	int	y;
	int	x;

	data->map_val = 0;
	piece->overlap = 0;
	y = 0;
	while (y < piece->p_height)
	{
		x = 0;
		while (x < piece->p_width)
		{
			if (piece->p_map[y][x] == 1)
			{
				if (!check_placement(data, piece, y + y_off, x + x_off))
					return (NOT_VALID);
			}
			x++;
		}
		y++;
	}
	if (piece->overlap != 1)
		return (NOT_VALID);
	return (1);
}

int	check_piece(t_filler *data, t_piece *piece)
{
	int	valid;
	int	y;
	int	x;

	y = 0;
	valid = 0;
	while (y <= data->h_boundary)
	{
		x = 0;
		while (x <= data->w_boundary)
		{
			if (is_valid(data, piece, y, x))
			{
				valid++;
				best_values(data, piece, y, x);
			}	
			x++;
		}
		y++;
	}
	if (valid == 0)
		return (0);
	ft_printf("%i %i", piece->best_y, piece->best_x);
	return (1);
}

/*int	check_placement(t_filler *data, t_piece *piece, int y, int x)
{
	if (data->map[y][x] == -2)
		return (NOT_VALID);
	return (1);
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
				if (in_bounds(data, y + y_off, x + x_off))  cant do this, needs to be within check placement
				{
					if (!check_placement(data, piece, y + y_off, x + x_off))
						return (NOT_VALID);
				}
			}
			x_off++;
		}
		y_off++;
	}
	//if (!valid)
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
*/