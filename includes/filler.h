/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:15:34 by ajones            #+#    #+#             */
/*   Updated: 2022/10/03 20:37:36 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# define NO_VALUE 0
# define NOT_SET -1
# define NOT_VALID 0

# include <fcntl.h>
# include "../libft/libft.h"

typedef struct s_piece
{
	int			**p_map;
	int			p_height;
	int			p_width;
	int			got_piece;
	int			best_val;
	int			best_y;
	int			best_x;
	int			overlap;
	int			not_valid;
}				t_piece;


typedef struct s_filler
{
	int			player_num;
	char		goody;
	char		baddy;
	int			m_height;
	int			m_width;
	int			got_map;
	int			**map;
	int			map_val;
	int			h_boundary;
	int			w_boundary;
	int			got_piece;
}				t_filler;

int				main(void);

int				manage_map(t_filler *data);

void			set_heatmap(t_filler *data);

int				manage_piece(t_piece *piece, t_filler *data, char *line);

int				check_piece(t_filler *data, t_piece *piece);

void			wipe_down(t_filler *data, t_piece *piece, char *line);

void			init_piece(t_piece *piece);

void			init_data(t_filler *data, t_piece *piece);

void			reset_data(t_filler *data, t_piece *piece);

void			free_piece(t_piece *piece);

int				**make_map(t_filler *data);

int				**make_piece(t_piece *piece);

void			piece_value(t_piece *piece, int y, char *line);



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