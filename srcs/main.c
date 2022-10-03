/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:03:50 by ajones            #+#    #+#             */
/*   Updated: 2022/10/03 20:40:01 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	get_piece_data(t_filler *data, t_piece *piece, char *line)
{
	//reset_data(data, piece);
	piece->p_height = ft_atoi(ft_strchr(line, ' '));
	piece->p_width = ft_atoi(ft_strrchr(line, ' '));
	if (!piece->p_height || !piece->p_width)
		return (0);
	if (manage_piece(piece, data, line))
		return (1);
	return (0);
}

int	get_map_data(t_filler *data, char *line)
{
	if (data->map == NULL)
	{
		data->m_height = ft_atoi(ft_strchr(line, ' '));
		data->m_width = ft_atoi(ft_strrchr(line, ' '));
		if (!data->m_height || !data->m_width)
			return (0);
		data->map = make_map(data);
		if (data->map == NULL)
			return (0);
		//data->got_map = 1;
	}
	if (manage_map(data))
		return (1);
	return (0);
}

int	get_player_num(t_filler *data, char *line)
{
	// char	*player;

	// player = ft_strchr(line, 'p') + 1;
	// player++;
	data->player_num = ft_atoi(ft_strchr(line, 'p') + 1);
	if (data->player_num == 1)
	{
		data->goody = 'O';
		data->baddy = 'X';
		return (1);
	}
	else if (data->player_num == 2)
	{
		data->goody = 'X';
		data->baddy = 'O';
		return (1);
	}
	return (0);
}

int	check_line(t_filler *data, t_piece *piece, char *line)
{
	if (ft_strstr(line, "$$$ exec"))
	{
		if (!get_player_num(data, line))
			return (0);
	}
	else if (ft_strstr(line, "Plateau"))
	{
		if (!get_map_data(data, line))
			return (0);
	}
	else if (ft_strstr(line, "Piece"))
	{
		reset_data(data, piece);
		if (!get_piece_data(data, piece, line))
			return (0);
		if (!check_piece(data, piece))
			return (0);
	}
	ft_strdel(&line);
	//free(line);
	return (0);
}

int	main(void)
{
	char		*line;
	t_filler	*data;
	t_piece		*piece;

	data = (t_filler *)malloc(sizeof(t_filler));
	piece = (t_piece *)malloc(sizeof(t_piece));
	init_data(data, piece);
	while (get_next_line(0, &line) > 0)
	{
		if (!check_line(data, piece, line))
			wipe_down(data, piece, line);
		//ft_strdel(&line); /* free in clean up if still exsist? */
		//free(line);
	}
	wipe_down(data, piece, line);
	return (0);
}
