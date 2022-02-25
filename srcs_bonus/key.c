/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:19:42 by cjimenez          #+#    #+#             */
/*   Updated: 2022/02/25 15:28:03 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

int ft_input(int keycode, t_data *data)
{
    int x;
    int y;
    static int move = 0;
    
    char    *cmove;
    x = data->x_size;
    y = data->y_size;
    if (keycode == KEY_ESC)
        ft_end("Goodbye!\n", data, 1);
    else if (keycode == KEY_W && ft_move_up(data, x, y) == 0)
        ft_printf("moves: \033[33m%d\033[0m\n", ++move);
    else if (keycode == KEY_A && ft_move_left(data, x, y) == 0)
        ft_printf("moves: \033[33m%d\033[0m\n", ++move);
    else if (keycode == KEY_S && ft_move_down(data, x, y) == 0)
        ft_printf("moves: \033[33m%d\033[0m\n", ++move);
    else if (keycode == KEY_D && ft_move_right(data, x, y) == 0)
        ft_printf("moves: \033[33m%d\033[0m\n", ++move);
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

int ft_close_game(t_data *data)
{
    ft_end("\nGoodbye!\n", data, 1);
    return (1);
}