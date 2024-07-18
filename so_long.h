/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:43:11 by sranaivo          #+#    #+#             */
/*   Updated: 2024/06/13 13:43:14 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
//#include <mlx.h>
#include <math.h>
#include <fcntl.h>
#include "mlx_linux/mlx.h"
#include "mlx_linux/mlx_int.h"



//map.c
int		count_map_line(char *map);
char    **read_map(char *map);
void	free_map(char **map);
char	*get_map_content(char *file);

//ft_split
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);

#endif
