# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/14 14:14:38 by vsivanat          #+#    #+#              #
#    Updated: 2024/05/05 14:51:29 by vsivanat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
INC = -I . -I libft -I parsing
OBJDIR := obj
BONUS_NAME = checker

VPATH =	parsing \
		operation \
		sort

SRC = \
		parsing.c \
		ft_lst_utils.c \
		swap_functions.c \
		push_functions.c \
		rotate_functions.c \
		reverse_functions.c \
		bubble_sort.c \
		my_own_sort.c \
		k_sort.c \
		sort_utils.c \
		utils.c

BONUS_SRC := $(SRC)
BONUS_SRC += checker.c

SRC += main.c

OBJ	:=	$(addprefix $(OBJDIR)/, $(SRC:.c=.o))
BONUS_OBJ := $(addprefix $(OBJDIR)/, $(BONUS_SRC:.c=.o))

all: libft $(NAME)

bonus: libft $(BONUS_NAME)

libft:
	@if [ ! -d libft ]; then \
		echo "Cloning repository..."; \
		git clone https://github.com/v1dusss/42-Libft.git libft; \
	fi
	@make -C libft

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(INC) -o $(NAME) $(OBJ) -L libft -lft
	@echo "\033[1;32m✅ [push_swap created]\033[0m"

$(BONUS_NAME): $(BONUS_OBJ)
	@$(CC) $(CFLAGS) $(INC) -o $(BONUS_NAME) $(BONUS_OBJ) -L libft -lft
	@echo "\033[1;32m✅ [checker created]\033[0m"

clean:
	@rm -rf $(OBJDIR)
	@make -C libft clean

fclean:
	@echo "\033[1;33m🗑️  Deleting the obj directory and executable... 🗑️\033[0m"
	@make clean
	@rm -f $(NAME) $(BONUS_NAME)
	@make -C libft fclean

re: fclean all

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

visualizer:
	@if [ ! -d "push_swap_visualizer" ]; then \
		echo "Cloning repository..."; \
		git clone https://github.com/o-reo/push_swap_visualizer; \
		echo "Building visualizer..."; \
		mkdir -p push_swap_visualizer/build; \
		cd push_swap_visualizer/build && cmake .. >/dev/null 2>&1 && make >/dev/null 2>&1; \
	else \
		echo "Visualizer already exists."; \
	fi
	@echo "Running visualizer..."
	@./push_swap_visualizer/build/bin/visualizer

.PHONY: all clean fclean re libft
