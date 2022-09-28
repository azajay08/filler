/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 00:59:12 by ajones            #+#    #+#             */
/*   Updated: 2022/09/29 01:59:01 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	piece_value(t_filler *data, int y, char *line)
{
	int	x;

	x = 0;
	while (x < data->p_width)
	{
		if (line[x] == '*')
	}
}

void	read_piece(t_filler *data)
{
	char	*line;
	int		line_count;

	line_count = 0;
	while(get_next_line(0, &line) > 0 && line_count < data->p_height)
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

void	reset_piece(t_filler *data)
{
	if (data->piece)
		free(data->piece);
	data->piece = NULL;
	data->p_height = 0;
	data->p_width = 0;
}

int	manage_piece(t_filler *data)
{
	data->piece = make_piece(data);
	if (!data->piece)
		return (0);
	read_piece(data);
	return (1);
}