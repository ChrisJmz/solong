/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:05:52 by cjimenez          #+#    #+#             */
/*   Updated: 2022/03/01 15:23:57 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
# define KEY_W          119
# define KEY_A          97
# define KEY_S          115
# define KEY_D          100
# define KEY_ESC        65307
# define GAMESIZE       32

typedef struct s_img
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*right;
	void	*wall;
	void	*floor;
	void	*exit;
	void	*collectible;
}	t_img;

typedef struct s_data
{
	int		x;
	int		y;
	int		x_size;
	int		y_size;
	char	**map;
	int		data1;
	int		data2;
	int		count;
	int		collnbr;
	int		collnbrmax;
	t_img	img;
}	t_data;

int		ft_file_name(char *file);
int		ft_error(char *str);
int		ft_strsize(char **str);
int		ft_get_nbr(char **str, char c);
char	**ft_fill_map(char *av);
int		ft_parse_map(char **map);
int		ft_content(char **str);
void	*ft_put_img(t_data *data, char *path);
void	ft_put_content(t_data *mlx, int x, int y, char **map);
void	ft_init(t_data *data);
int		ft_close_game(t_data *data);
int		ft_input(int keycode, t_data *data);
int		ft_move_right(t_data *data, int x, int y);
int		ft_move_left(t_data *data, int x, int y);
int		ft_move_up(t_data *data, int x, int y);
int		ft_move_down(t_data *data, int x, int y);
void	ft_end(char *str, t_data *data, int ret);
int		ft_replace_collectible_right(t_data *vars, int x, int y);
int		ft_replace_collectible_up(t_data *vars, int x, int y);
int		ft_replace_collectible_left(t_data *vars, int x, int y);
int		ft_replace_collectible_down(t_data *vars, int x, int y);
void	ft_freemap(char **map);

#endif
