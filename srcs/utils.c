/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:06:01 by cmsjus            #+#    #+#             */
/*   Updated: 2022/02/21 17:18:13 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

int	ft_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	return (0);
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
		printf("File type not supported!\n");
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

int	ft_end(char *str, t_data *data)
{
	int i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	mlx_destroy_image(data->img.mlx_ptr, data->content.wall);
	mlx_destroy_image(data->img.mlx_ptr, data->content.exit);
	mlx_destroy_image(data->img.mlx_ptr, data->content.floor);
	mlx_destroy_image(data->img.mlx_ptr, data->content.collectible);
	mlx_destroy_window(data->img.mlx_ptr, data->img.mlx_win);
	mlx_destroy_image(data->img.mlx_ptr, data->img.left);
	mlx_destroy_image(data->img.mlx_ptr, data->img.right);
	mlx_destroy_image(data->img.mlx_ptr, data->img.moves);
	mlx_destroy_image(data->img.mlx_ptr, data->img.floor);
	mlx_destroy_image(data->img.mlx_ptr, data->img.wall);
	mlx_destroy_display(data->img.mlx_ptr);
	free(data->img.mlx_ptr);
	printf("%s", str);
	exit(0);
}