/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:05:52 by cjimenez          #+#    #+#             */
/*   Updated: 2022/02/16 10:07:11 by cjimenez         ###   ########.fr       */
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
# define GAMESIZE       32

typedef struct s_img
{
    void    *mlx_ptr;
    void    *mlx_win;
    void    *left;
    void    *right;
    void    *up;
    void    *down;
    void    *wall;
    void    *collectible;
    void    *floor;
}   t_img;

typedef struct s_content
{
    void    *wall;
    void    *collectible;
    void    *floor;
    void    *exit;
    int     collnbr;
    int     collnbrmax;
}   t_content;

typedef struct s_data
{
    int     x;
    int     y;
    int     x_size;
    int     y_size;
    char    **map;
    int     data1;
    int     data2;
    int     count;
    t_content   content;
    t_img       img;
}   t_data;

int   ft_file_name(char *file);
int	ft_error(char *str);
int ft_strsize(char **str);
int	ft_get_nbr(char **str, char c);
char    **ft_fill_map(char *av);
int ft_parse_map(char **map);
int ft_content(char **str);
void	*ft_put_img(t_data *data, char *path);
void    ft_put_content(t_data *mlx, int x, int y, char **map);
void    ft_init(t_data *data);
int ft_close_game(t_img *vars);
int ft_input(int keycode, t_data *data);
int ft_move_right(t_data *data, int x, int y);
int ft_move_left(t_data *data, int x, int y);
int ft_move_up(t_data *data, int x, int y);
int ft_move_down(t_data *data, int x, int y);
int	ft_end(t_data *data);

#endif