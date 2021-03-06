/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 09:31:29 by cjimenez          #+#    #+#             */
/*   Updated: 2022/03/01 15:00:23 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

int	ft_collision(int current, int next)
{
	int	res;

	res = current + next;
	if (res == 129)
		return (1);
	else if (res == 147)
		return (2);
	else if (res == 149)
		return (42);
	else if (res == 168)
		return (84);
	return (0);
}

int	ft_move_right(t_data *data, int x, int y)
{
	if (ft_collision(data->map[y][x], data->map[y][x + 1]) == 1)
		return (1);
	else if (ft_collision(data->map[y][x], data->map[y][x + 1]) == 2)
		ft_replace_collectible_right(data, x, y);
	else if (ft_collision(data->map[y][x], data->map[y][x + 1]) == 42)
	{
		if (data->collnbr == data->collnbrmax)
			ft_end("\033[32m\nYou won!\033[0m\n", data, 0);
		else
			return (1);
	}
	else if (ft_collision(data->map[y][x], data->map[y][x + 1]) == 84)
		ft_end("\nYou lost\n", data, 1);
	else
		ft_swap(&data->map[y][x + 1], &data->map[y][x]);
	mlx_put_image_to_window(data->img.mlx_ptr, data->img.mlx_win,
		data->img.floor, data->data1, data->data2);
	data->x_size = ft_content_pos_x(data->map, 'P');
	data->y_size = ft_content_pos_y(data->map, 'P');
	data->data1 = (data->x_size % data->x * GAMESIZE);
	data->data2 = (data->y_size % data->y * GAMESIZE);
	mlx_put_image_to_window(data->img.mlx_ptr, data->img.mlx_win,
		data->img.right, data->data1, data->data2);
	return (0);
}

int	ft_move_left(t_data *data, int x, int y)
{
	if (ft_collision(data->map[y][x], data->map[y][x - 1]) == 1)
		return (1);
	else if (ft_collision(data->map[y][x], data->map[y][x - 1]) == 2)
		ft_replace_collectible_left(data, x, y);
	else if (ft_collision(data->map[y][x], data->map[y][x - 1]) == 42)
	{
		if (data->collnbr == data->collnbrmax)
			ft_end("\033[32m\nYou won!\033[0m\n", data, 0);
		else
			return (1);
	}
	else if (ft_collision(data->map[y][x], data->map[y][x - 1]) == 84)
		ft_end("\nYou lost\n", data, 1);
	else
		ft_swap(&data->map[y][x - 1], &data->map[y][x]);
	mlx_put_image_to_window(data->img.mlx_ptr, data->img.mlx_win,
		data->img.floor, data->data1, data->data2);
	data->x_size = ft_content_pos_x(data->map, 'P');
	data->y_size = ft_content_pos_y(data->map, 'P');
	data->data1 = (data->x_size % data->x * GAMESIZE);
	data->data2 = (data->y_size % data->y * GAMESIZE);
	mlx_put_image_to_window(data->img.mlx_ptr, data->img.mlx_win,
		data->img.left, data->data1, data->data2);
	return (0);
}

int	ft_move_up(t_data *data, int x, int y)
{
	if (ft_collision(data->map[y][x], data->map[y - 1][x]) == 1)
		return (1);
	else if (ft_collision(data->map[y][x], data->map[y - 1][x]) == 2)
		ft_replace_collectible_up(data, x, y);
	else if (ft_collision(data->map[y][x], data->map[y - 1][x]) == 42)
	{
		if (data->collnbr == data->collnbrmax)
			ft_end("\033[32mYou won!\033[0m\n", data, 0);
		else
			return (1);
	}
	else if (ft_collision(data->map[y][x], data->map[y - 1][x]) == 84)
		ft_end("\nYou lost\n", data, 1);
	else
		ft_swap(&data->map[y - 1][x], &data->map[y][x]);
	mlx_put_image_to_window(data->img.mlx_ptr, data->img.mlx_win,
		data->img.floor, data->data1, data->data2);
	data->x_size = ft_content_pos_x(data->map, 'P');
	data->y_size = ft_content_pos_y(data->map, 'P');
	data->data1 = (data->x_size % data->x * GAMESIZE);
	data->data2 = (data->y_size % data->y * GAMESIZE);
	mlx_put_image_to_window(data->img.mlx_ptr, data->img.mlx_win,
		data->img.right, data->data1, data->data2);
	return (0);
}

int	ft_move_down(t_data *data, int x, int y)
{
	if (ft_collision(data->map[y][x], data->map[y + 1][x]) == 1)
		return (1);
	else if (ft_collision(data->map[y][x], data->map[y + 1][x]) == 2)
		ft_replace_collectible_down(data, x, y);
	else if (ft_collision(data->map[y][x], data->map[y + 1][x]) == 42)
	{
		if (data->collnbr == data->collnbrmax)
			ft_end("\033[32m\nYou won!\033[0m\n", data, 0);
		else
			return (1);
	}
	else if (ft_collision(data->map[y][x], data->map[y + 1][x]) == 84)
		ft_end("\nYou lost\n", data, 1);
	else
		ft_swap(&data->map[y + 1][x], &data->map[y][x]);
	mlx_put_image_to_window(data->img.mlx_ptr, data->img.mlx_win,
		data->img.floor, data->data1, data->data2);
	data->x_size = ft_content_pos_x(data->map, 'P');
	data->y_size = ft_content_pos_y(data->map, 'P');
	data->data1 = (data->x_size % data->x * GAMESIZE);
	data->data2 = (data->y_size % data->y * GAMESIZE);
	mlx_put_image_to_window(data->img.mlx_ptr, data->img.mlx_win,
		data->img.right, data->data1, data->data2);
	return (0);
}
