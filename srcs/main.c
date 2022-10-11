/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:03:50 by ajones            #+#    #+#             */
/*   Updated: 2022/10/11 13:16:46 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	get_piece_data(t_filler *data, t_piece *piece, char *line)
{
	piece->p_height = ft_atoi(ft_strchr(line, ' '));
	piece->p_width = ft_atoi(ft_strrchr(line, ' '));
	if (!piece->p_height || !piece->p_width)
		return (0);
	manage_piece(piece, data, line);
	return (1);
}

int	get_map_data(t_filler *data, char *line)
{
	if (data->map == NULL)
	{
		data->m_height = ft_atoi(ft_strchr(line, ' '));
		data->m_width = ft_atoi(ft_strrchr(line, ' '));
		if (data->m_height < 1 || data->m_width < 1)
			return (0);
		data->map = make_map(data);
		if (data->map == NULL)
			return (0);
	}
	read_map(data);
	set_heatmap(data);
	return (1);
}

int	get_player_num(t_filler *data, char *line)
{
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
	return (1);
}

int	main(void)
{
	char		*line;
	t_filler	*data;
	t_piece		*piece;

	data = (t_filler *)malloc(sizeof(t_filler));
	if (!data)
		return (0);
	piece = (t_piece *)malloc(sizeof(t_piece));
	if (!piece)
	{
		free(data);
		return (0);
	}
	init_data(data, piece);
	while (get_next_line(0, &line) > 0)
	{
		if (!check_line(data, piece, line))
			return (wipe_down(data, piece, line));
	}
	return (wipe_down(data, piece, line));
}
