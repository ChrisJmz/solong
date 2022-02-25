# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/16 15:42:20 by nguiard           #+#    #+#              #
#    Updated: 2022/02/25 15:32:11 by cjimenez         ###   ########.fr        #
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
		srcs/collectible.c		\

SRCS_BONUS =	srcs_bonus/solong.c				\
				srcs_bonus/utils.c				\
				srcs_bonus/map_utils.c			\
				srcs_bonus/wall_parsing.c		\
				srcs_bonus/content_parsing.c	\
				srcs_bonus/init.c				\
				srcs_bonus/key.c				\
				srcs_bonus/movements.c			\
				srcs_bonus/collectible.c		\

INC =   include

LIB = -L ./libft -lft -L ./mlx -lmlx -lXext -lX11

all: $(NAME)

$(NAME):
	make -C libft
	gcc $(FLAGS) -I$(INC) -o $(NAME) $(SRC) $(LIB)

bonus:
	make -C libft
	gcc $(FLAGS) -I$(INC) -o $(NAME) $(SRCS_BONUS) $(LIB)

clean:
	@rm -rf *.o
	@rm -rf ./libft/*.o
	@echo "cleaning .o files"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf ./libft/*.a

re: fclean all

.PHONY: all bonus clean fclean re