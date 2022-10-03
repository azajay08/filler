/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 00:59:12 by ajones            #+#    #+#             */
/*   Updated: 2022/10/04 00:46:21 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/* decide what value to assgin pieces
** get the max and min x and y for the piece, use
** as a comparison on valid places
**
** check everything about it being valid first
**
** check the overall value
**
** assign its overall value into best_value
** assign coords into best_x best_y
**
** move along to the next valid place and only
** replace the values if new value is smaller than
** best_value
 */

void	piece_value(t_piece *piece, int y, char *line)
{
	int	x;

	x = 0;
	while (x < piece->p_width)
	{
		if (line[x] == '*')
		{
			piece->p_map[y][x] = 1;
		}
		else
			piece->p_map[y][x] = 0;
		x++;
	}
}

void	read_piece(t_piece *piece, char *line)
{
	int		line_count;

	line_count = 0;
	while (line_count < piece->p_height && get_next_line(0, &line) > 0)
	{
		piece_value(piece, line_count, line);
		line_count++;
	}
}

int	**make_piece(t_piece *piece)
{
	int	**p_map;
	int	x;
	int	y;

	y = 0;
	p_map = (int **)malloc(sizeof(int *) * piece->p_height);
	if (!p_map)
		return (NULL);
	while (y < piece->p_height)
	{
		p_map[y] = (int *)malloc(sizeof(int) * piece->p_width);
		if (!p_map[y])
			return (NULL);
		x = 0;
		while (x < piece->p_width)
		{
			p_map[y][x] = 0;
			x++;
		}
		y++;
	}
	return (p_map);
}

int	manage_piece(t_piece *piece, t_filler *data, char *line)
{
	piece->p_map = make_piece(piece);
	if (!piece->p_map)
		return (0);
	read_piece(piece, line);
	data->h_boundary = data->m_height - piece->p_height;
	data->w_boundary = data->m_width - piece->p_width;
	return (1);
}
