# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/03 10:36:32 by deelliot          #+#    #+#              #
#    Updated: 2022/02/21 10:31:16 by deelliot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CFLAGS = -Wall -Wextra -Werror

SRCS = fillit.c ft_validate_tetri.c main.c ft_handle_errors.c \
	ft_print_array.c ft_translate_pieces.c ft_find_height_width.c

INCLS = fillit.h

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME):
	make -C libft
	gcc -c $(SRCS) $(CFLAGS)
	gcc $(CFLAGS) -o $(NAME) $(OBJS) -L./libft -lft

clean:
	rm -f $(OBJS)
	make fclean -C libft/

fclean: clean
	rm -f $(NAME)
	rm -f a.out

re: fclean all

.PHONY: all fclean clean re

test: re
	./$(NAME)

$(V).SILENT: