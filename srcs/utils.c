/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:06:01 by cmsjus            #+#    #+#             */
/*   Updated: 2022/02/15 13:44:16 by cjimenez         ###   ########.fr       */
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

	i = 0;
	while (file[i])
		i++;
	i--;
	if (file[i] != 'r' && file[i - 1] != 'e'
		&& file[i - 2] != 'b' && file[i - 3] != '.')
		return (ft_error("Usage: ./solong [map.ber] (from ft_file_name)\n"), 1);
	return (0);
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