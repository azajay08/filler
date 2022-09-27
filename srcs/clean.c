/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:43:16 by ajones            #+#    #+#             */
/*   Updated: 2022/09/28 00:35:56 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	wipe_down(t_filler *data, char *line, int ret)
{
	if (ret == 1)
		ft_strdel(&line);
	/* free and delete everything in struct now if it exists */
	
}