/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 11:29:51 by cmsjus            #+#    #+#             */
/*   Updated: 2022/02/21 18:04:33 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

static void	ft_mlx_put(t_data *mlx, void *path, int f, int g)
{
	mlx_put_image_to_window(mlx->img.mlx_ptr, mlx->img.mlx_win, path, GAMESIZE * f, GAMESIZE * g);
}

static void ft_put_content2(t_data *mlx, int x, int y, char **map)
{
    int k;
    int l;

    k = 1;
    while (k < x - 1)
    {
        l = 1;
        while (l < y - 1)
        {
            if (map[l][k] == '1')
                ft_mlx_put(mlx, mlx->content.wall, k, l);
            if (map[l][k] == '0')
                ft_mlx_put(mlx, mlx->content.floor, k, l);
            if (map[l][k] == 'C')
                ft_mlx_put(mlx, mlx->content.collectible, k, l);
            if (map[l][k] == 'E')
                ft_mlx_put(mlx, mlx->content.exit, k, l);
            l++;
        }
        k++;
    }
}

void    ft_put_content(t_data *mlx, int x, int y, char **map)
{
    int i;
    int j;

    i = -1;
    j = -1;
    mlx->content.wall = ft_put_img(mlx, "xpm/wall.xpm");
    mlx->content.floor = ft_put_img(mlx, "xpm/floor.xpm");
    mlx->content.collectible = ft_put_img(mlx, "xpm/collectible.xpm");
    mlx->content.exit = ft_put_img(mlx, "xpm/exit.xpm");
    while(++i < y)
    {
        mlx_put_image_to_window(mlx->img.mlx_ptr, mlx->img.mlx_win,
                                    mlx->content.wall, 0, GAMESIZE * i);
        mlx_put_image_to_window(mlx->img.mlx_ptr, mlx->img.mlx_win,
                                    mlx->content.wall, (x - 1) * GAMESIZE, GAMESIZE * i);
    }
    while(++j < x)
    {
        ft_mlx_put(mlx, mlx->img.wall, j, 0);
        ft_mlx_put(mlx, mlx->img.wall, j, (y - 1));
    }
    ft_put_content2(mlx, x, y, map);
}

int main(int ac, char **av)
{
    t_data data;
    int     i;
    i = 0;
    
    if (ac == 2)
    {
        if (ft_file_name(av[1]) == 0)
        {
            data.map = ft_fill_map(av[1]);
            if (ft_parse_map(data.map) == 0 && ft_content(data.map) == 0)
            {
                ft_printf("\033[32mMap found :\033[00m\n\n");
                while (data.map[i] != 0)    
                {
                    ft_printf("%s", data.map[i]);
                    i++;
                }
                ft_printf("\n\n");
                ft_init(&data);
            }
        }
    }
    else
    {
        ft_printf("Usage : ./so_long [map.ber]\n");
        exit(1);
    }
    return (0);
}