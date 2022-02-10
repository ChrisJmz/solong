/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmsjus <cmsjus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:30:34 by cmsjus            #+#    #+#             */
/*   Updated: 2022/02/10 18:54:35 by cmsjus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

void    ft_checkarg(int ac, char **av)
{
    if (ac != 2)
    {
        ft_putendl_fd("Usage: ./solong [map.ber]", 2);
        exit(0);
    }
    if ((ft_strlen(av[1]) < 4) || (!ft_strrchr(av[1], '.')))
    {
        ft_putendl_fd("Usage: ./solong [map.ber]", 2);
        exit(0);
    }
    if (ft_strcmp(ft_strrchr(av[1], '.'), ".ber") != 0)
    {
        ft_putendl_fd("Usage: ./solong [map.ber]", 2);
        exit(0);
    }
}