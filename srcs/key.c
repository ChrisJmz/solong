/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:19:42 by cjimenez          #+#    #+#             */
/*   Updated: 2022/02/21 18:04:50 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

int ft_input(int keycode, t_data *data)
{
    int x;
    int y;
    char    *cmove;
    static int move = 0;
    x = data->x_size;
    y = data->y_size;
    if (keycode == KEY_ESC)
    {
        mlx_destroy_window(data->img.mlx_ptr, data->img.mlx_win);
        exit(0);
    }
    else if ((keycode == KEY_W || keycode == KEY_UP) && ft_move_up(data, x, y) == 0)
        ft_printf("moves: %d       pos:%d\n", ++move, data->map[y][x] + data->map[y - 1][x]);
    else if ((keycode == KEY_A || keycode == KEY_LEFT) && ft_move_left(data, x, y) == 0)
        ft_printf("moves: %d       pos:%d\n", ++move, data->map[y][x] + data->map[y][x - 1]);
    else if ((keycode == KEY_S || keycode == KEY_DOWN) && ft_move_down(data, x, y) == 0)
        ft_printf("moves: %d       pos:%d\n", ++move, data->map[y][x] + data->map[y + 1][x]);
    else if ((keycode == KEY_D || keycode == KEY_RIGHT) && ft_move_right(data, x, y) == 0)
        ft_printf("moves: %d       pos:%d\n", ++move, data->map[y][x] + data->map[y][x + 1]);
    mlx_put_image_to_window(data->img.mlx_ptr, data->img.mlx_win, data->img.wall, 0, 0);
    cmove = ft_itoa(move);
    if (cmove != NULL)
    {
        mlx_put_image_to_window(data->img.mlx_ptr, data->img.mlx_win, data->img.moves, 0, 0);
        mlx_string_put(data->img.mlx_ptr, data->img.mlx_win, 10, 19, 0x009ACD32, cmove);
    }
    free(cmove);
    return (0);
}

int ft_close_game(t_img *vars)
{
    mlx_destroy_window(vars->mlx_ptr, vars->mlx_win);
    printf("Goodbye!\n");
    exit(0);
}