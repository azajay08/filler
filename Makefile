# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajones <ajones@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/07 14:18:25 by ajones            #+#    #+#              #
#    Updated: 2022/09/28 23:28:41 by ajones           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS := main.c clean.c manage_map.c manage_map2.c manage_piece.c put_piece.c \


NAME := ajones.filler
FLAGS := -c -Wall -Werror -Wextra
SRC_P := srcs/
INCL := libft/libft.a
F_SRC := $(addprefix $(SRC_P), $(SRCS))
O_FILES := $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	@make -C libft
	@gcc $(FLAGS) $(F_SRC) $(INCL) -o $(NAME)

clean:
	@rm -f $(O_FILES)
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all