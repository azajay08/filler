/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_clean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:43:16 by ajones            #+#    #+#             */
/*   Updated: 2022/10/02 03:28:34 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	reset_data(t_filler *data, t_piece *piece)
{
	if (piece->p_map)
		free_piece(piece);
	piece->p_map = NULL;
	piece->p_val = 0;
	piece->p_height = 0;
	piece->p_width = 0;
	piece->best_val = -1;
	piece->best_y = -1;
	piece->best_x = -1;
	piece->min_y = -1;
	piece->max_y = -1;
	piece->min_x = -1;
	piece->max_x = -1;
	piece->overlap = 0;
	piece->got_piece = 0;
	data->h_boundary = 0;
	data->w_boundary = 0;
	data->map_val = 0;
}

void	init_piece(t_piece *piece)
{
	piece->p_map = NULL;
	piece->p_val = 0;
	piece->p_height = 0;
	piece->p_width = 0;
	piece->best_val = -1;
	piece->best_y = -1;
	piece->best_x = -1;
	piece->min_y = -1;
	piece->max_y = -1;
	piece->min_x = -1;
	piece->max_x = -1;
	piece->overlap = 0;
	piece->got_piece = 0;
}

void	init_data(t_filler *data, t_piece *piece)
{
	init_piece(piece);
	data->player_num = 0;
	data->m_width = 0;
	data->m_height = 0;
	data->got_map = 0;
	data->h_boundary = 0;
	data->w_boundary = 0;
	data->map_val = 0;
	data->map = NULL;
}

void	wipe_down(t_filler *data, t_piece *piece, char *line, int ret)
{
	int	m;

	m = 0;
	if (ret == 1)
		ft_strdel(&line);
	if (data->map)
	{
		while (m < data->m_height)
		{
			free(data->map[m]);
			m++;
		}
		free(data->map);
		free(data);
	}
	if (piece->p_map)
		free_piece(piece);
	/* free and delete everything in struct now if it exists */
}

int	game_over(t_filler *data, t_piece *piece, char *line, int ret)
{
	/* printf statement for the 0, 0 coords to say im out the game */
	
	//ft_printf("0 0\n");
	// if (data->map == NULL)
	// 	ft_printf("%i %i", data->m_height, data->m_width);
	// else
	// 	ft_printf("6 6");
	ft_printf("0 0\n");
	wipe_down(data, piece, line, ret);
	return (0);
}

