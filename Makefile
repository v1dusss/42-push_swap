# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MAKEFILE                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/14 14:14:38 by vsivanat          #+#    #+#              #
#    Updated: 2024/04/14 15:14:27 by vsivanat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
INC = -I . -I libft -I parsing

VPATH = parsing

SRC = main.c \
	parsing.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

libft:
	make -C libft

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(CFLAGS) $(INC) -o $(NAME) $(OBJ) -L libft -lft

$(OBJDIR)%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJDIR)*.o
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
