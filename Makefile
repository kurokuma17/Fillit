# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/03 10:36:32 by deelliot          #+#    #+#              #
#    Updated: 2022/03/07 16:03:02 by deelliot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CFLAGS = -Wall -Wextra -Werror

SRCS = main.c ft_handle_errors.c ft_validate_tetri.c create_grid.c \
	ft_translate_pieces.c ft_check_fit.c ft_solve.c ft_print_array.c \

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