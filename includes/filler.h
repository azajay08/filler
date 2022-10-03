/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:15:34 by ajones            #+#    #+#             */
/*   Updated: 2022/10/04 00:56:51 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# define NO_VALUE 0
# define NOT_SET -1
# define NOT_VALID 0

# include "../libft/libft.h"

typedef struct s_piece
{
	int			**p_map;
	int			p_height;
	int			p_width;
	int			best_val;
	int			best_y;
	int			best_x;
	int			overlap;
}				t_piece;

typedef struct s_filler
{
	int			**map;
	int			player_num;
	char		goody;
	char		baddy;
	int			m_height;
	int			m_width;
	int			map_val;
	int			h_boundary;
	int			w_boundary;
}				t_filler;

int				main(void);
int				**make_map(t_filler *data);
void			read_map(t_filler *data);
void			set_heatmap(t_filler *data);
void			init_piece(t_piece *piece);
void			init_data(t_filler *data, t_piece *piece);
void			reset_data(t_filler *data, t_piece *piece);
int				manage_piece(t_piece *piece, t_filler *data, char *line);
int				**make_piece(t_piece *piece);
void			piece_value(t_piece *piece, int y, char *line);
void			free_piece(t_piece *piece);
int				check_piece(t_filler *data, t_piece *piece);
int				wipe_down(t_filler *data, t_piece *piece, char *line);

#endif
