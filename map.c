/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 13:57:50 by sranaivo          #+#    #+#             */
/*   Updated: 2024/07/21 13:57:52 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_map_content(int fd)
{
	char	*buf;
	char	*content;
	char	*temp;
	int		r;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	content = NULL;
	temp = NULL;
	r = 1;
	while (r != 0)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r < 0)
			return (free(buf), NULL);
		buf[r] = '\0';
		temp = ft_strjoin(content, buf);
		free(content);
		content = temp;
	}
	free(buf);
	close(fd);
	return (content);
}

char	**read_map(char *file)
{
	char	**map;
	char	*map_content;
	int		fd;

	if (!check_extension(file))
	{
		return (NULL);
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		return (NULL);
	}
	map_content = get_map_content(fd);
	map = ft_split(map_content, '\n');
	free(map_content);
	return (map);
}
