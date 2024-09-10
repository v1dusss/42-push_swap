# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/14 14:14:38 by vsivanat          #+#    #+#              #
#    Updated: 2024/09/10 20:27:30 by vsivanat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -I includes
INC = -I . -I libft -I parsing
OBJDIR := obj
BONUS_NAME = checker

VPATH =	\
		src \
		src/parsing \
		src/operation \
		src/sort

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
	@make -C libft

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(INC) -o $(NAME) $(OBJ) -L libft -lft
	@echo "\033[1;32m ✅ [push_swap created]\033[0m"

$(BONUS_NAME): $(BONUS_OBJ)
	@$(CC) $(CFLAGS) $(INC) -o $(BONUS_NAME) $(BONUS_OBJ) -L libft -lft
	@echo "\033[1;32m ✅ [checker created]\033[0m"

clean:
	@rm -rf $(OBJDIR)
	@make -C libft clean

fclean:
	@echo "\033[1;33m 🗑️  Deleting the obj directory and executable... 🗑️\033[0m"
	@make clean
	@rm -f $(NAME) $(BONUS_NAME)
	@echo "\033[0;37m 🧹 [push_swap deleted]\033[0m"
	@make -C libft fclean

re: fclean all

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

visualizer:
	@if [ ! -d "push_swap_visualizer" ]; then \
		echo "Cloning repository..."; \
		git clone https://github.com/o-reo/push_swap_visualizer; \
		echo "\033[1;32m 💾 [Visualizer cloned]\033[0m"; \
		echo "Building visualizer..."; \
		mkdir -p push_swap_visualizer/build; \
		cd push_swap_visualizer/build && cmake .. >/dev/null 2>&1 && make >/dev/null 2>&1; \
		echo "\033[1;32m ✅ [Visualizer built]\033[0m"; \
	else \
		echo "\033[1;32m ✅ [Visualizer already cloned]\033[0m"; \
	fi
	@echo "Running visualizer..."
	@cd push_swap_visualizer/build && ./bin/visualizer


.PHONY: all clean fclean re libft
