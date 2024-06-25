/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:11:16 by sranaivo          #+#    #+#             */
/*   Updated: 2024/04/09 15:46:07 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line_static(char **str)
{
	char	*line;
	char	*temp;
	char	*p;

	p = ft_strchr(*str, '\n');
	if (p)
	{
		line = ft_substr(*str, 0, (p - *str) + 1);
		temp = ft_substr(*str, (p - *str) + 1, -1);
		free(*str);
		*str = temp;
	}
	else
	{
		line = ft_substr(*str, 0, -1);
		free(*str);
		*str = NULL;
	}
	if (!(*line))
		return (free(line), NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*static_line;
	char		*line;
	char		*temp;
	char		*buf;
	int			r;

	r = 1;
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (r != 0 && !ft_strchr(static_line, '\n'))
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r < 0)
		{
			free(static_line);
			static_line = NULL;
			return (free(buf), NULL);
		}
		buf[r] = '\0';
		temp = ft_strjoin(static_line, buf);
		free(static_line);
		static_line = temp;
	}
	free(buf);
	line = get_line_static(&static_line);
	return (line);
}
