/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 07:39:59 by cmsjus            #+#    #+#             */
/*   Updated: 2022/02/14 11:32:58 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

static int	ft_count_size(char *av)
{
	char    *str;
	int     i;
	int     fd;

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
	int	i;
	int	fd;
	int	size;

	i = 0;
	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("file not found\n");
		exit(0);
	}
	size = ft_count_size(av);
	map = malloc(sizeof(char) * (size + 1));
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
