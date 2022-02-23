/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:15:10 by cjimenez          #+#    #+#             */
/*   Updated: 2022/02/21 17:51:09 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

int ft_content_pos_x(char **map, char c)
{
    int i;
    int j;

    i = 0;
    while(map[i])
    {
        j = 0;
        while(map[i][j])
        {
            if (map[i][j] == c)
                return(j);
            j++;
        }
        i++;
    }
    return (0);
}

int ft_content_pos_y(char **map, char c)
{
    int i;
    int j;

    i = 0;
    while(map[i])
    {
        j = 0;
        while(map[i][j])
        {
            if (map[i][j] == c)
                return(i);
            j++;
        }
        i++;
    }
    return (0);
}

void    *init_content(t_data *data)
{
    data->content.collnbr = 0;
    data->x = ft_strlen(data->map[1]) - 1;
    data->y = ft_strsize(data->map);
    data->x_size = ft_content_pos_x(data->map, 'P');
    data->y_size = ft_content_pos_y(data->map, 'P');
    data->content.collnbrmax = ft_get_nbr(data->map, 'C');
    data->data1 = (data->x_size % data->x * GAMESIZE);
    data->data2 = (data->y_size % data->y * GAMESIZE);
    data->img.mlx_ptr = mlx_init();
    if (data->img.mlx_ptr == NULL)
    {
        free(data->img.mlx_ptr);
        return (NULL);
    }
    data->img.wall = ft_put_img(data, "xpm/wall.xpm");
    data->img.right = ft_put_img(data, "xpm/right.xpm");
    data->img.left = ft_put_img(data, "xpm/left.xpm");
    data->img.floor = ft_put_img(data, "xpm/floor.xpm");
    data->img.moves = ft_put_img(data, "xpm/TEST.xpm");
    data->img.mlx_win = mlx_new_window(data->img.mlx_ptr, data->x * GAMESIZE, data->y * GAMESIZE, "solong");
    return (data);
}

void    ft_init(t_data *data)
{
    data = init_content(data);
    if (data == NULL)
        return ;
    ft_put_content(data, data->x, data->y, data->map);
    mlx_put_image_to_window(data->img.mlx_ptr, data->img.mlx_win, data->img.right, data->data1, data->data2);
    mlx_hook(data->img.mlx_win, 17, 0L, ft_close_game, data);
    mlx_key_hook(data->img.mlx_win, ft_input, data);
    mlx_loop(data->img.mlx_ptr);
}