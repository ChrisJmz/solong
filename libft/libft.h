/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 11:07:57 by cmsjus            #+#    #+#             */
/*   Updated: 2022/02/14 07:58:04 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE    500
#endif

int	ft_atoi(const char *str);
int	ft_isdigit(int c);
char	*ft_itoa(int n);
void    ft_putchar(char c);
void    ft_putstr(char *str);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
char	*ft_strncpy(char *str, int nb);
char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);
char	*get_next_line2(char *str);
char	*ft_strjoin(char *s1, char *s2);

#endif