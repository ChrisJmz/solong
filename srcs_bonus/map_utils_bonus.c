/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 07:39:59 by cmsjus            #+#    #+#             */
/*   Updated: 2022/03/01 14:58:36 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

static int	ft_count_size(char *av)
{
	char	*str;
	int		i;
	int		fd;

	i = 0;
	fd = open(av, O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		free(str);
		i++;
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
	return (i);
}

char	**ft_fill_map(char *av)
{
	char	**map;
	char	*str;
	int		i;
	int		fd;
	int		size;

	i = 0;
	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (NULL);
	size = ft_count_size(av);
	map = malloc(sizeof(char *) * (size + 1));
	if (!map)
		return (NULL);
	str = get_next_line(fd);
	while (str)
	{
		map[i] = str;
		str = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	free(str);
	close(fd);
	return (map);
}

void	*ft_put_img(t_data *data, char *path)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	return (mlx_xpm_file_to_image(data->img.mlx_ptr, path, &a, &b));
}

int	ft_error(char *str)
{
	ft_printf("\033[31m%s\033[0m\n", str);
	return (1);
}
