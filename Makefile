# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MAKEFILE                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/14 14:14:38 by vsivanat          #+#    #+#              #
#    Updated: 2024/04/14 16:10:04 by vsivanat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
INC = -I . -I libft -I parsing
OBJDIR := obj

VPATH = parsing

SRC =	main.c \
		parsing.c

OBJ	:=	$(addprefix $(OBJDIR)/, $(SRC:.c=.o))

all: libft $(NAME)

libft:
	make -C libft

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INC) -o $(NAME) $(OBJ) -L libft -lft

clean:
	rm -rf $(OBJDIR)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

.PHONY: all clean fclean re libft

# NAME = push_swap

# CC = cc
# CFLAGS = -Wall -Wextra -Werror
# INC = -I . -I libft -I parsing
# OBJDIR	:=	obj

# VPATH = parsing

# SRC =	main.c \
# 		parsing.c

# OBJ	:=	$(addprefix $(OBJDIR)/, $(SRC:.c=.o))

# all: $(NAME)

# libft:
# 	make -C libft

# $(NAME): libft $(OBJ) 
# 	$(CC) $(CFLAGS) $(INC) -o $(NAME) $(OBJ) -L libft -lft

# clean:
# 	rm -rf $(OBJDIR)
# 	make -C libft clean

# fclean: clean
# 	rm -f $(NAME)
# 	make -C libft fclean

# re: fclean all

# $(OBJDIR)/%.o: %.c
# 	@mkdir -p $(OBJDIR)
# 	$(CC) $(CFLAGS) $(INC) -c $< -o $@

# .PHONY: all clean fclean re libft
