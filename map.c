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

char	*get_map_content(char *file)
{
	char	*buf;
	int		fd;
	char	*content;
	char	*temp;
	int		r;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	fd = open(file, O_RDONLY);
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

int		count_map_line(char *content)
{
	int	i;
	int	line;

	i = -1;
	line = 0;
	while(content[++i])
		if(content[i] == '\n')
			line++;
	line++;
	return (line);
}

char	**read_map(char *file)
{
	char	**map;

	char *map_content = get_map_content(file);
	map = ft_split(map_content, '\n');
	return(map);
}
