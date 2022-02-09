# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/16 15:42:20 by nguiard           #+#    #+#              #
#    Updated: 2022/02/09 15:25:09 by cjimenez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	srcs/solong.c		\
		srcs/map_verif.c	\
		srcs/utils.c		\

CFLAGS = -Wall -Werror -Wextra

OBJ = ${SRC:.c=.o}

NAME = solong

CC = gcc

MLX = mlx/libmlx_Linux.a -lXext -lX11 -Imlx/include/

MATH = -lm

INCLUDE = -Imlx/include/ -Iinclude/

INC_DIR = include

all: ${NAME}

nb:=1

n:=0

a:=0

.c.o:
	@${CC} ${INCLUDE} ${CFLAGS} -c -I $(INC_DIR) $< -o ${<:.c=.o}
	$(eval n=$(shell echo $$(($(nb)/5 * 70))))
	$(eval a=$(shell echo $$((202 - $(n)))))
	@printf "\033[0;38;5;%dm" "${a}"
	@echo -n "\rCompilation de l'objet" ${nb} "terminee\033[0m"
	$(eval nb=$(shell echo $$(($(nb)+1))))

${NAME}: ${OBJ}
	@echo -n "\n"
	@make -C mlx
	@echo -n "\n"
	@${CC} ${INCLUDE} ${OBJ} ${MLX} ${MATH} -o ${NAME}
	@echo "Tout est carre"

bonus: all

clean:
	@rm -f ${OBJ}
	@echo "clean ok!"

fclean:
	@rm -f ${OBJ} ${NAME}
	@echo "fclean ok!"

re: fclean all

.PHONY: all clean fclean re normal renormal bonus
