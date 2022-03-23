/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 10:38:35 by cjimenez          #+#    #+#             */
/*   Updated: 2022/03/01 14:38:38 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

int	ft_replace_collectible_right(t_data *vars, int x, int y)
{
	vars->map[y][x + 1] = 'P';
	vars->map[y][x] = '0';
	vars->collnbr++;
	return (0);
}

int	ft_replace_collectible_left(t_data *vars, int x, int y)
{
	vars->map[y][x - 1] = 'P';
	vars->map[y][x] = '0';
	vars->collnbr++;
	return (0);
}

int	ft_replace_collectible_up(t_data *vars, int x, int y)
{
	vars->map[y - 1][x] = 'P';
	vars->map[y][x] = '0';
	vars->collnbr++;
	return (0);
}

int	ft_replace_collectible_down(t_data *vars, int x, int y)
{
	vars->map[y + 1][x] = 'P';
	vars->map[y][x] = '0';
	vars->collnbr++;
	return (0);
}
