/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 08:50:52 by cjimenez          #+#    #+#             */
/*   Updated: 2022/03/01 14:37:25 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_strsize(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	ft_check_walls(char **str)
{
	int		i;
	char	*last;
	char	*first;

	i = 0;
	first = str[0];
	last = str[ft_strsize(str) - 1];
	if (ft_strsize(str) - 1 < 1)
		return (1);
	if (first[0] != '1')
		return (1);
	while (first[i + 1])
	{
		if (first[i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (last[i])
	{
		if (last[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

static int	ft_check_line(char *str)
{
	int	i;

	i = 0;
	if (str[0] != '1')
		return (1);
	i++;
	while (str[i])
		i++;
	i = 0;
	while (str[i + 1])
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != 'C'
			&& str[i] != 'P' && str[i] != 'E')
			return (1);
		i++;
	}
	if (str[i - 1] != '1')
		return (1);
	return (0);
}

static int	ft_check_rectangle(char **str)
{
	int	i;
	int	length;
	int	line;

	i = 1;
	length = ft_strlen(str[0]) - 1;
	while (str[i])
	{
		line = ft_strlen(str[i]) - 1;
		if (str[i + 1] == NULL)
			line += 1;
		if (line != length)
			return (1);
		i++;
	}
	return (0);
}

int	ft_parse_map(char **map)
{
	int	i;

	i = 0;
	if (ft_check_walls(map) == 1 || ft_check_rectangle(map) == 1)
	{
		ft_freemap(map);
		return (ft_error("Problems with top/bottom walls."));
	}
	i++;
	while (map[i])
	{
		if (ft_check_line(map[i]) == 1)
		{
			ft_freemap(map);
			return (ft_error("Problems with side walls."));
		}
		i++;
	}
	return (0);
}
