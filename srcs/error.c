/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:51:16 by cjimenez          #+#    #+#             */
/*   Updated: 2022/02/09 15:25:03 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

int ft_verif_str(char *str, char *content, int i)
{
    int a;
    
    a = 0;
    if (str == NULL || content == NULL)
        return (1);
    while (*str != 0 && a <= i && ft_strchr(content, *str))
    {
        str++;
        a++;
    }
    if (a == content)
        return (0);
    return (1);
}

int ft_error(int error, char *message)
{
    ft_printf("Error\n");
    if (error > 0 && message != NULL)
        ft_printf("%s:%s", message, strerror(error));
    else
        perror(strerror(26));
    return (-1);
}