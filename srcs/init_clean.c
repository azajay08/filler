/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_clean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:43:16 by ajones            #+#    #+#             */
/*   Updated: 2022/10/04 14:11:41 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	free_piece(t_piece *piece)
{
	int	p;

	p = 0;
	if (piece->p_map)
	{
		while (p < piece->p_height)
		{
			free(piece->p_map[p]);
			p++;
		}
		free(piece->p_map);
	}
	piece->p_map = NULL;
}

void	reset_data(t_filler *data, t_piece *piece)
{
	free_piece(piece);
	piece->p_map = NULL;
	piece->p_height = 0;
	piece->p_width = 0;
	piece->best_val = -1;
	piece->best_y = -1;
	piece->best_x = -1;
	piece->overlap = 0;
	data->h_boundary = 0;
	data->w_boundary = 0;
	data->map_val = 0;
}

void	init_piece(t_piece *piece)
{
	piece->p_map = NULL;
	piece->p_height = 0;
	piece->p_width = 0;
	piece->best_val = -1;
	piece->best_y = -1;
	piece->best_x = -1;
	piece->overlap = 0;
}

void	init_data(t_filler *data, t_piece *piece)
{
	init_piece(piece);
	data->player_num = 0;
	data->m_width = 0;
	data->m_height = 0;
	data->h_boundary = 0;
	data->w_boundary = 0;
	data->map_val = 0;
	data->map = NULL;
}

int	wipe_down(t_filler *data, t_piece *piece, char *line)
{
	int	m;

	m = 0;
	if (line)
		ft_strdel(&line);
	if (piece->p_map)
		free_piece(piece);
	if (data->map)
	{
		while (m < data->m_height)
		{
			free(data->map[m]);
			m++;
		}
		free(data->map);
	}
	data->map = NULL;
	free(data);
	free(piece);
	ft_printf("0 0\n");
	return (0);
}
