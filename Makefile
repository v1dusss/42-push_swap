# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/14 14:14:38 by vsivanat          #+#    #+#              #
#    Updated: 2024/04/28 17:11:00 by vsivanat         ###   ########.fr        #
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
	make -C libft

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INC) -o $(NAME) $(OBJ) -L libft -lft

$(BONUS_NAME): $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(INC) -o $(BONUS_NAME) $(BONUS_OBJ) -L libft -lft

clean:
	rm -rf $(OBJDIR)
	make -C libft clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	make -C libft fclean

re: fclean all

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

.PHONY: all clean fclean re libft
