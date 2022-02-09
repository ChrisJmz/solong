/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:04:47 by cjimenez          #+#    #+#             */
/*   Updated: 2022/02/09 15:24:59 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

int verif_map_width(t_module *module, char *content, int height)
{
    if (module->map->width < 4)
        return(ft_error(2, "Map too small!\n"));
    if (ft_verif_str(content, "1", module->map->width) == 0)
    {
        if (((int)ft_strlen(content)) != module->map->width && height > 0)
            return (ft_error(2, "Invalid map!\n"));
        content[module->map->width] = '\0';
        return (0);
    }
    if (ft_verif_str(content, "10PCE", module->map->width) == 0)
    {
        if (content[0] != '1' || content[module->map->width - 1] != '1')
            return (ft_error(2, "Invalid map!\n"));
        if ((int)ft_strlen(content) - 1 != module->map->width)
            return (ft_error(2, "Invalid map!\n"));
        content[module->map->width] = '\0';
        return 0;
    }
    return (ft_error(2, "Invalid map!\n"));
}


int verif_file_name(char *filename)
{
    int len;

    len = ft_strlen(filename);
    if (filename[len - 1] == 'r' && filename[len - 2] == 'e' && filename[len - 3] == 'b' && filename[len - 4] == '.')
        return (0);
    else
    {
        printf("File not supported, please use .ber\n");
        return (1);
    }
}
