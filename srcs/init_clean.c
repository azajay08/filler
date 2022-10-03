/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_clean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:43:16 by ajones            #+#    #+#             */
/*   Updated: 2022/10/03 22:18:25 by ajones           ###   ########.fr       */
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
	piece->got_piece = 0;
	piece->not_valid = 0;
	data->got_piece = 0;
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
	piece->got_piece = 0;
	piece->not_valid = 0;
}

void	init_data(t_filler *data, t_piece *piece)
{
	init_piece(piece);
	data->got_piece = 0;
	data->p_height = 0;
	data->p_width = 0;
	data->player_num = 0;
	data->m_width = 0;
	data->m_height = 0;
	data->got_map = 0;
	data->h_boundary = 0;
	data->w_boundary = 0;
	data->map_val = 0;
	data->map = NULL;
}

void	wipe_down(t_filler *data, t_piece *piece, char *line)
{
	int	m;

	
	m = 0;
	if (line)
		m = 0;
	if (piece->p_map)
		m = 0;
	if (data->map)
		m = 0;
	//if (piece->not_valid == 1)
	ft_printf("0 0\n");
	/*{
		while (m < data->m_height)
		{
			free(data->map[m]);
			m++;
		}
		free(data->map);
	}*/
	//free(data);
	//free(piece);
}
