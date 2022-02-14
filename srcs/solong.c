/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 11:29:51 by cmsjus            #+#    #+#             */
/*   Updated: 2022/02/14 11:38:23 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

int main(int ac, char **av)
{
    t_data data;
    int     i;
    i = 0;
    
    if (ac == 2)
    {
        data.map = ft_fill_map(av[1]);
        if (ft_file_name(av[1]) == 0 && ft_parse_map(data.map) == 0 && ft_content(data.map) == 0)
        {
            printf("Map found :\n");
            while (data.map[i] != 0)    
            {
                printf("%s", data.map[i]);
                i++;
            }
            printf("\n");
        }
    }
    else
    {
        printf("Usage: ./solong [map.ber] (from main)\n");
        exit(0);
    }
    return (1);
}