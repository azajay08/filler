/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 00:59:12 by ajones            #+#    #+#             */
/*   Updated: 2022/09/30 01:30:41 by ajones           ###   ########.fr       */
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

void	piece_value(t_filler *data, int y, char *line)
{
	int	x;

	x = 0;
	while (x < data->p_width)
	{
		if (line[x] == '*')
		{
			data->piece[y][x] = 1; /* needs changing */
		}
		x++;
	}
}

void	read_piece(t_filler *data)
{
	char	*line;
	int		line_count;

	line_count = 0;
	while (get_next_line(0, &line) > 0 && line_count < data->p_height)
	{
		piece_value(data, line_count, line);
		ft_strdel(&line);
		line_count++;
	}
}

int	**make_piece(t_filler *data)
{
	int	**piece;
	int	x;
	int	y;

	y = 0;
	piece = (int **)malloc(sizeof(int *) * data->p_height);
	if (!piece)
		return (NULL);
	while (y < data->p_height)
	{
		piece[y] = (int *)malloc(sizeof(int) * data->p_width);
		if (!piece[y])
			return (NULL);
		x = 0;
		while (x < data->p_width)
		{
			piece[y][x] = 0;
			x++;
		}
		y++;
	}
	return (piece);
}

int	manage_piece(t_filler *data)
{
	data->piece = make_piece(data);
	if (!data->piece)
		return (0);
	read_piece(data);
	return (1);
}

void	reset_piece(t_filler *data)
{
	if (data->piece)
		free(data->piece);
	data->piece = NULL;
	data->p_height = 0;
	data->p_width = 0;
}
