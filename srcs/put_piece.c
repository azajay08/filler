/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 01:07:38 by ajones            #+#    #+#             */
/*   Updated: 2022/10/01 00:48:09 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	is_valid(t_filler *data, t_piece *piece, int y, int x)
{


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
				valid++;
		}
	}

	if (valid == 0)
		return (0);
	return (1);
}
