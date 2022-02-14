/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:05:52 by cjimenez          #+#    #+#             */
/*   Updated: 2022/02/14 10:18:58 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
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

typedef struct s_img
{
    void    *img_background;
    void    *img_player;
    void    *img_exit;
    void    *img_wall;
    void    *img_collectible;
    int     width;
    int     height;
    char    *player;
    char    *background;
    char    *wall;
    char    *collectible;
    char    *exit;
}   t_img;

typedef struct s_content
{
    char    exit;
    char    collectible;
    char    player;
    char    wall;
    char    space;
    int     count_p;
    int     count_e;
    int     count_c;
}   t_content;

typedef struct s_pos
{
    int x;
    int y;
}   t_pos;

typedef struct s_data
{
    void        *mlx_ptr;
    void        *mlx_win;
    int         width;
    int         height;
    char        **map;
    t_content   content;
    t_img       img;
    t_pos       pos;
    int         count;
}   t_data;

int   ft_file_name(char *file);
int	ft_error(char *str);
char    **ft_fill_map(char *av);
int ft_parse_map(char **map);
int ft_content(char **str);

#endif