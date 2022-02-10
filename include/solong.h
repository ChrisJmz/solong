/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmsjus <cmsjus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:05:52 by cjimenez          #+#    #+#             */
/*   Updated: 2022/02/10 18:49:03 by cmsjus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "../mlx/mlx.h"
# include "libft.h"
# define WINDOW_WIDTH   600
# define WINDOW_HEIGHT  300
# define KEY_W          119
# define KEY_A          97
# define KEY_S          115
# define KEY_D          100
# define KEY_UP         65362
# define KEY_LEFT       65361
# define KEY_DOWN       65364
# define KEY_RIGHT      65363
# define KEY_ESC        65307
# define MLX_ERROR      1

void    ft_checkarg(int ac, char **av);

#endif