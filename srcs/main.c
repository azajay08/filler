/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:03:50 by ajones            #+#    #+#             */
/*   Updated: 2022/10/01 01:54:51 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int get_piece_data(t_filler *data, t_piece *piece, char *line)
{
	reset_data(data, piece);
	piece->p_height = ft_atoi(ft_strchr(line, ' '));
	piece->p_width = ft_atoi(ft_strrchr(line, ' '));
	if (!piece->p_height || !piece->p_width)
		return (0);
	if (manage_piece(piece, data))
		return (1);
	return (0);
}

int	get_map_data(t_filler *data, char *line)
{
	if (data->got_map == 0)
	{
		data->m_height = ft_atoi(ft_strchr(line, ' '));
		data->m_width = ft_atoi(ft_strrchr(line, ' '));
		if (!data->m_height || !data->m_width)
			return (0);
		return (1);
	}
	if (manage_map(data))
		return (1);
	return (0);
}

int	get_player_num(t_filler *data, char *line)
{
	char	*player;

	player = ft_strchr(line, 'p');
	player++;
	data->player_num = ft_atoi(player);
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

int	main(void)
{
	char		*line;
	t_filler	data;
	t_piece		piece;
	int			ret;

	ret = 1;
	init_data(&data, &piece);
	while (ret == 1)
	{
		if (get_next_line(0, &line) != 1)
			break ;
		if (ret == 1 && ft_strstr(line, "$$$ exec") && !data.player_num)
			ret = get_player_num(&data, line);
		if (ret == 1 && ft_strstr(line, "Plateau"))
			ret = get_map_data(&data, line);
		if (ret == 1 && ft_strstr(line, "Piece"))
			ret = get_piece_data(&data, &piece, line);
		if (ret == 1 && !check_piece(&data, &piece))
			return (game_over(&data, line, ret));
		ft_strdel(&line);
	}
	wipe_down(&data, line, ret);
	return (0);
}
