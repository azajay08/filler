/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:15:34 by ajones            #+#    #+#             */
/*   Updated: 2022/09/30 01:04:58 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# define TRUE 1
# define FALSE 0

# include "../libft/libft.h"

typedef struct s_filler
{
	int			player_num;
	char		goody;
	char		baddy;
	int			m_height;
	int			m_width;
	int			p_height;
	int			p_width;
	int			got_map;
	int			**piece;
	int			**map;

	int			best_y;
	int			best_x;
	int			best_val;
	
}				t_filler;

int				main(void);

int				manage_map(t_filler *data);

void			set_heatmap(t_filler *data);

void			reset_piece(t_filler *data);

int				manage_piece(t_filler *data);

int				check_piece(t_filler *data);

int				game_over(t_filler *data, char *line, int ret);

void			wipe_down(t_filler *data, char *line, int ret);

#endif















// typedef struct s_coords
// {
// 	int 		x;
// 	int			y;
// }				t_coords;

// typedef struct s_map
// {
// 	int			grid;
// 	char		*m_grid;
// }				t_map;

// typedef struct s_piece
// {
// 	int			p_height;
// 	int			p_width;
// 	char		**p_piece;
// }				t_piece;