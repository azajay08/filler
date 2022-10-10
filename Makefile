# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajones <ajones@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/07 14:18:25 by ajones            #+#    #+#              #
#    Updated: 2022/10/10 22:23:03 by ajones           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS := main.c init_clean.c manage_map.c manage_map2.c manage_piece.c \
put_piece.c 

NAME := ajones.filler
FLAGS := -Wall -Werror -Wextra
SRC_P := srcs/
INCL := includes/
LIB := libft/libft.a
F_SRC := $(addprefix $(SRC_P), $(SRCS))
O_FILES := $(SRCS:.c=.o)
RED := '\033[2;3;31m'
RESET := \033[0m

all: $(NAME)

$(NAME):
	@make -C libft
	@gcc $(FLAGS) -c $(F_SRC) -I $(INCL)
	@gcc $(FLAGS) -I $(INCL) $(O_FILES) $(LIB) -o $(NAME)

clean:
	@rm -f $(O_FILES)
	@make -C libft clean

fclean: clean
	@echo ${RED}"Removing ajones.filler...${RESET}"
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all