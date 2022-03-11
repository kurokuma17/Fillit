# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/03 10:36:32 by deelliot          #+#    #+#              #
#    Updated: 2022/03/11 14:23:42 by deelliot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CFLAGS = -Wall -Wextra -Werror

SRCS = 1_main.c
SRCS += ft_handle_errors.c
SRCS += 2_validate_tetri.c
SRCS += 3_create_grid.c
SRCS += 4_translate_pieces.c
SRCS += 5_check_fit.c
SRCS += 6_solve.c
SRCS += ft_print_array.c

INCLS = fillit.h

all: $(NAME)

$(NAME):
	make -C libft
	gcc $(CFLAGS) -o $(NAME) $(SRCS) -I fillit.h -L./libft -lft

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
