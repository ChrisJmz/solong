/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 11:29:51 by cmsjus            #+#    #+#             */
/*   Updated: 2022/02/25 15:31:56 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

static void	ft_mlx_put(t_data *data, void *path, int f, int g)
{
	mlx_put_image_to_window(data->img.mlx_ptr, data->img.mlx_win, path, GAMESIZE * f, GAMESIZE * g);
}

static void ft_put_content2(t_data *data, int x, int y, char **map)
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
                ft_mlx_put(data, data->img.wall, k, l);
            if (map[l][k] == '0')
                ft_mlx_put(data, data->img.floor, k, l);
            if (map[l][k] == 'C')
                ft_mlx_put(data, data->img.collectible, k, l);
            if (map[l][k] == 'E')
                ft_mlx_put(data, data->img.exit, k, l);
            if (map[l][k] == 'X')
                ft_mlx_put(data, data->img.enemy, k, l);
            l++;
        }
        k++;
    }
}

void    ft_put_content(t_data *data, int x, int y, char **map)
{
    int i;
    int j;

    i = -1;
    j = -1;
    while(++i < y)
    {
        ft_mlx_put(data, data->img.wall, 0, i);
        ft_mlx_put(data, data->img.wall, (x - 1), i);
    }
    while(++j < x)
    {
        ft_mlx_put(data, data->img.wall, j, 0);
        ft_mlx_put(data, data->img.wall, j, (y - 1));
    }
    ft_put_content2(data, x, y, map);
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