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

SRCS_BONUS =	srcs_bonus/solong_bonus.c				\
				srcs_bonus/utils_bonus.c				\
				srcs_bonus/map_utils_bonus.c			\
				srcs_bonus/wall_parsing_bonus.c			\
				srcs_bonus/content_parsing_bonus.c		\
				srcs_bonus/init_bonus.c					\
				srcs_bonus/key_bonus.c					\
				srcs_bonus/movements_bonus.c			\
				srcs_bonus/collectible_bonus.c			\

OBJS = $(SRC:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CC = gcc

RM = rm -rf

INC =   include

LIB = -L ./libft -lft -L ./mlx -lmlx -lXext -lX11

.c.o:
	$(CC) $(FLAGS) -I$(INC) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME):	$(OBJS)
	make -C libft
	$(CC) $(FLAGS) -I$(INC) -o $(NAME) $(OBJS) $(LIB)

bonus:	$(OBJS_BONUS)
	make -C libft
	$(CC) $(FLAGS) -I$(INC) -o $(NAME) $(OBJS_BONUS) $(LIB)

clean:
	make clean -C libft
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)

fclean: clean
	$(RM) $(LIBFT)
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re