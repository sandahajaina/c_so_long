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

int	count_map_line(char *map)
{
	int		line;
	int		fd;
	int		r;
	char	*buf;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		perror("error");
	r = 1;
	line = 1;
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (free(buf), 0);
	while (r != 0)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r < 0)
			return (free(buf), 0);
		buf[r] = '\0';
		if (ft_strchr(buf, '\n'))
			line++;
	}
	free(buf);
	close(fd);
	return (line);
}

char	**read_map(char *file)
{
	int		fd;
	int		line;
	int		i;
	char	**map;

	line = count_map_line(file);
	map = malloc(sizeof(char *) * line);
	if (!map)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		perror("error");
	i = 0;
	while (i < line)
		map[i++] = ft_strjoin("", get_next_line(fd));
	return (map);
}
