/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:27:48 by sranaivo          #+#    #+#             */
/*   Updated: 2024/06/28 15:27:50 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char    **read_map(char *file)
{
    int fd;

    printf("%s\n", file);

    fd = open(file, O_RDONLY);
    char **res;
    res = malloc(sizeof(char **));
    char *tmp = malloc(5);
    int i = 0;
    while(file[i])
    {
        tmp[i] = file[i];
        i++;
    }
    (void) fd;
    res[0] = tmp;
    return (res);
}
