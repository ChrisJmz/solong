/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:05:52 by cjimenez          #+#    #+#             */
/*   Updated: 2022/02/09 15:25:01 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "../mlx/mlx.h"
# include "get_next_line.h"
# define WINDOW_WIDTH   600
# define WINDOW_HEIGHT  300
# define KEY_W          119
# define KEY_A          97
# define KEY_S          115
# define KEY_D          100
# define KEY_UP         65362
# define KEY_LEFT       65361
# define KEY_DOWN       65364
# define KEY_RIGHT      65363
# define KEY_ESC        65307
# define MLX_ERROR      1

typedef struct s_data
{
    void    *mlx_ptr;
    void    *mlx_win;
}   t_data;

typedef struct s_map
{
    char    **map;
    int     fd;
    int     width;
    int     height;
    int     col;
    int     row;
}   t_map;

typedef struct s_module
{
    t_data  *data;
    t_map   *map;

}   t_module;

int ft_error(int error, char *message);
int verif_file_name(char *filename);
int ft_verif_str(char *str, char *content, int i);

#endif