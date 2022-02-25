/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:06:01 by cmsjus            #+#    #+#             */
/*   Updated: 2022/02/25 12:50:55 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

int	ft_error(char *str)
{
	ft_printf("\033[31m%s\033[0m\n", str);
	return (1);
}

int	ft_file_name(char *file)
{
	int	i;

	i = ft_strlen(file);
	i--;
	if ((file[i] == 'r' && file[i - 1] == 'e'
		&& file[i - 2] == 'b' && file[i - 3] == '.'))
		return (0);
	else
	{
		ft_error("File type not supported!");
		return (1);
	}
}

int	ft_get_nbr(char **str, char c)
{
	int	res;
	int	i;
	int	j;

	i = 0;
	res = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == c)
				res++;
			j++;
		}
		i++;
	}
	return (res);
}

void	ft_end(char *str, t_data *data, int ret)
{
	ft_freemap(data->map);
	mlx_destroy_window(data->img.mlx_ptr, data->img.mlx_win);
	mlx_destroy_image(data->img.mlx_ptr, data->img.left);
	mlx_destroy_image(data->img.mlx_ptr, data->img.right);
	mlx_destroy_image(data->img.mlx_ptr, data->img.moves);
	mlx_destroy_image(data->img.mlx_ptr, data->img.floor);
	mlx_destroy_image(data->img.mlx_ptr, data->img.wall);
	mlx_destroy_image(data->img.mlx_ptr, data->img.collectible);
	mlx_destroy_image(data->img.mlx_ptr, data->img.exit);
	mlx_destroy_image(data->img.mlx_ptr, data->img.enemy);
	mlx_destroy_display(data->img.mlx_ptr);
	free(data->img.mlx_ptr);
	ft_printf("\033[33m%s\033[0m", str);
	exit(ret);
}

void	ft_freemap(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}