# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/16 15:42:20 by nguiard           #+#    #+#              #
#    Updated: 2022/02/16 09:42:57 by cjimenez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFT = libft/libft.a

FLAGS = -Wall -Wextra -Werror

SRC =	srcs/solong.c			\
		srcs/utils.c			\
		srcs/map_utils.c		\
		srcs/wall_parsing.c		\
		srcs/content_parsing.c	\
		srcs/init.c				\
		srcs/key.c				\
		srcs/movements.c		\

INC =   include/so_long.h		\

LIB = -L ./libft -lft -L ./mlx -lmlx -lXext -lX11

all: $(NAME)

$(NAME):
	make -C libft
	gcc $(FLAGS) -o $(NAME) $(SRC) $(LIB)

g: all
	gcc -g -fsanitize=address $(FLAGS) -o $(NAME) $(SRC) $(LIB)

skiperror:
	gcc -o $(NAME) $(SRC) -g $(LIB)

clean:
	@rm -rf *.o
	@rm -rf ./libft/*.o
	@echo "cleaning .o files"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf ./libft/*.a

re: fclean all