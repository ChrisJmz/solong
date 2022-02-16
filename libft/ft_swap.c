/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 09:49:16 by cjimenez          #+#    #+#             */
/*   Updated: 2022/02/16 09:51:15 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_swap(char *s1, char *s2)
{
    char tmp;

    tmp = *s1;
    *s1 = *s2;
    *s2 = tmp;
}