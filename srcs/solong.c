/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:05:56 by cjimenez          #+#    #+#             */
/*   Updated: 2022/02/09 15:25:02 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

int key_touched(int keycode, t_data *data)
{
    if (keycode == KEY_ESC)
    {
        mlx_destroy_window(data->mlx_ptr, data->mlx_win);
        exit(0);
    }
    else if (keycode == KEY_RIGHT)
    {
        mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, 0, 0);
    }
    printf("%d\n", keycode);
    return (0);
}

int main(int ac, char **av)
{
    t_data  data;
    t_img   params;
    
    /* INIT MLX */
    if (ac == 2)
    {
        if (verif_file_name(av[1]) == 0)
        {
            data.mlx_ptr = mlx_init();
            if (data.mlx_ptr == NULL)
                return (MLX_ERROR);
            data.mlx_win = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "Legends Of League");
            if (data.mlx_win == NULL)
            {
                free(data.mlx_win);
                return (MLX_ERROR);
            }
            /* INIT IMAGE*/
            data.img = mlx_xpm_file_to_image(data.mlx_ptr, av[1], &params.img_width, &params.img_height);
            if (data.img == NULL)
            {
                printf("Image not found\n");
                return (MLX_ERROR);
            }
            /* HOOK SETUP */
            mlx_key_hook(data.mlx_win, &key_touched, &data);
            
            /* LOOP WINDOW */
            mlx_loop(data.mlx_ptr);

            /* FREE, DESTROY ETC...*/
            mlx_destroy_display(data.mlx_ptr);
            free(data.mlx_ptr);
            return (0);
        }
    }
    else if (ac < 2)
    {
        printf("Usage : ./solong [map]\n");
        return (1);
    }
}