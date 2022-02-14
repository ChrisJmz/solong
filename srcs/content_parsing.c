/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:13:32 by cjimenez          #+#    #+#             */
/*   Updated: 2022/02/14 11:11:40 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

static int ft_check_player(char **str)
{
    int i;
    int j;
    int player;

    player = 0;
    i = 0;
    while(str[i])
    {
        j = 0;
        while (str[i][j])
        {
            if (str[i][j] == 'P')
                player++;
            j++;
        }
        i++;
    }
    return (player);
}

static int ft_check_collectible(char **str)
{
    int i;
    int j;
    int collectible;

    collectible = 0;
    i = 0;
    while(str[i])
    {
        j = 0;
        while (str[i][j])
        {
            if (str[i][j] == 'C')
                collectible++;
            j++;
        }
        i++;
    }
    return (collectible);
}

static int ft_check_exit(char **str)
{
    int i;
    int j;
    int exit;

    exit = 0;
    i = 0;
    while(str[i])
    {
        j = 0;
        while (str[i][j])
        {
            if (str[i][j] == 'E')
                exit++;
            j++;
        }
        i++;
    }
    return (exit);
}

int ft_content(char **str)
{
    if (ft_check_player(str) < 1 || ft_check_collectible(str) < 1 || ft_check_exit(str) < 1)
        return (ft_error("Something's missing inside the map\n"), 1);
    return (0);
}
