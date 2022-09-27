/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:15:34 by ajones            #+#    #+#             */
/*   Updated: 2022/09/28 01:16:31 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# define TRUE 1
# define FALSE 0

# include "../libft/libft.h"

typedef struct s_coords
{
	int 		x;
	int			y;
}				t_coords;

typedef struct s_map
{
	int			grid;
	char		*m_grid;
}				t_map;

typedef struct s_piece
{
	int			p_height;
	int			p_width;
	char		**p_piece;
}				t_piece;

typedef struct s_filler
{
	int			player_num;
	char		goody;
	char		baddy;
	int			m_height;
	int			m_width;
	int			got_map;
	t_piece		*piece;
	t_map		*map;
}				t_filler;

int				main(void);
void			wipe_down(t_filler *data, char *line, int ret);
int				manage_map(t_filler *data, char *line);
int				get_piece_data(t_filler *data, char *line);


int				check_piece(t_filler *data);

int				game_over(t_filler *data, char *line, int ret);

#endif