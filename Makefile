# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajones <ajones@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/07 14:18:25 by ajones            #+#    #+#              #
#    Updated: 2022/10/11 12:26:31 by ajones           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS := main.c init_clean.c manage_map.c manage_map2.c manage_piece.c \
put_piece.c 

NAME := ajones.filler
FLAGS := -Wall -Werror -Wextra
SRC_P := ./srcs/
F_INC := -I./includes/
L_INC := -I./libft/
LIBFT := libft/libft.a
LIB := -L./libft/ -lft
F_SRC := $(addprefix $(SRC_P), $(SRCS))
O_FILES := $(SRCS:%.c=%.o)
O_PATH := ./obj/
O_DIR := $(addprefix $(O_PATH), $(O_FILES))
GREEN := '\033[1;3;32m'
CYAN := '\033[2;3;36m'
RED := '\033[2;3;31m'
RESET := \033[0m

all: $(NAME)

$(NAME): $(LIBFT) $(O_PATH) $(O_DIR)
	@echo ${CYAN}"Making player: ajones.filler...${RESET}"
	@gcc $(FLAGS) $(F_INC) $(L_INC) $(O_DIR) $(LIB) -o $(NAME)
	@echo ${GREEN}"Player successfully made${RESET}"

$(LIBFT):
	@make -C libft

$(O_PATH):
	@mkdir -p $(O_PATH)

$(O_PATH)%.o: $(SRC_P)%.c
	@gcc -c $(FLAGS) $(F_INC) $(L_INC)  -o $@ $<

clean:
	@echo ${RED}"Removing obj directory...${RESET}"
	@rm -rf $(O_PATH)
	@make -C libft clean

fclean: clean
	@echo ${RED}"Removing ajones.filler...${RESET}"
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all

.PHONY := all re clean fclean make