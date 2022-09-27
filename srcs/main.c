/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:03:50 by ajones            #+#    #+#             */
/*   Updated: 2022/09/27 14:47:58 by ajones           ###   ########.fr       */
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

void	get_map_size(t_filler *data, char *line)
{
	char	*map_width;
	char	*map_height;

	map_height = ft_strchr(line, ' ');
	map_width = ft_strrchr(line, ' ');
	data->m_height = ft_atoi(map_height);
	data->m_width = ft_atoi(map_width);
	data->got_map = 1;
}

void	get_player_num(t_filler *data, char *line)
{
	char	*player;

	player = ft_strchr(line, 'p');
	player++;
	data->player_num = ft_atoi(player);
	if (data->player_num == 1)
	{
		data->goody = 'O';
		data->baddy = 'X';
	}
	else if (data->player_num == 2)
	{
		data->goody = 'X';
		data->baddy = 'O';
	}
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
		if (get_next_line(0, &line) == -1)
			wipe_down(&data, line);
		if (ft_strstr(line, "$$$ exec") && !data.player_num)
			get_player_num(&data, line);
		if (ft_strstr(line, "Plateau") && !data.got_map)
			get_map_size(&data, line);
		if (!manage_map(line, &data))
			wipe_down(&data, line);
		free(line);
		

	}
	wipe_down(&data, line);
	return (0);
}
