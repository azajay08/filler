/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:43:16 by ajones            #+#    #+#             */
/*   Updated: 2022/09/29 23:11:06 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	wipe_down(t_filler *data, char *line, int ret)
{
	if (ret == 1)
		ft_strdel(&line);
	if (data)
	{
		
	}
	/* free and delete everything in struct now if it exists */
	
}

int	game_over(t_filler *data, char *line, int ret)
{
	/* printf statement for the 0, 0 coords to say im out the game */
	wipe_down(data, line, ret);
	ft_printf("[%i, %i]", 0, 0);
	return (0);
}

