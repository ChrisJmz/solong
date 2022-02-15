/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:19:42 by cjimenez          #+#    #+#             */
/*   Updated: 2022/02/15 13:44:16 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

int ft_close(int keycode, t_img *img)
{
    if (keycode == 53 || keycode < 0)
    {
        mlx_destroy_window(img->mlx_ptr, img->mlx_win);
        exit(0);
    }
    return (0);
}

int ft_close_game(t_img *vars)
{
    mlx_destroy_window(vars->mlx_ptr, vars->mlx_win);
    printf("Goodbye!\n");
    exit(0);
}