/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:03:50 by ajones            #+#    #+#             */
/*   Updated: 2022/09/28 00:38:05 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	init_data(t_filler *data)
{
	data->player_num = 0;
	data->m_width = 0;
	data->m_height = 0;
	data->got_map = 1;
}

/* maybe need to make into int function for error returns*/

int	get_map_size(t_filler *data, char *line)
{
	char	*map_width;
	char	*map_height;

	map_height = ft_strchr(line, ' ');
	map_width = ft_strrchr(line, ' ');
	data->m_height = ft_atoi(map_height);
	data->m_width = ft_atoi(map_width);
	if (!data->m_height || !data->m_width)
		return (0);
	data->got_map = 1;
	return (1);
}

/* 	free(map_height);
	free(map_width);  ??? */

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
	int			ret;

	ret = 1;
	init_data(&data);
	while (ret == 1)
	{
		if (get_next_line(0, &line) != 1)
			break ;
		if (ret == 1 && ft_strstr(line, "$$$ exec") && !data.player_num)
			ret = get_player_num(&data, line);
		if (ret == 1 && ft_strstr(line, "Plateau") && !data.got_map)
			ret = get_map_size(&data, line);
		if (ret == 1 && !manage_map(line, &data))
			ret = 0;
		ft_strdel(&line);
	}
	wipe_down(&data, line, ret);
	return (0);
}
