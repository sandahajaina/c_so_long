/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 13:58:17 by sranaivo          #+#    #+#             */
/*   Updated: 2024/07/21 13:58:19 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (s == 0)
	{
		return (0);
	}
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = malloc(len_s1 + len_s2 + 1);
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (j < len_s1)
		str[i++] = s1[j++];
	j = 0;
	while (j < len_s2)
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

int	check_extension(const char *filename)
{
	const char	*extension = ".ber";
	size_t		len_filename;
	size_t		len_extension;

	len_filename = strlen(filename);
	len_extension = 4;
	if (len_filename > 4 && filename[len_filename - 5] != '/')
	{
		if (ft_strncmp(filename + len_filename - len_extension, extension,
				len_extension) == 0)
		{
			return (1);
		}
		else
		{
			return (0);
		}
	}
	return (0);
}

void	ft_error(char **map, char *error_message)
{
	free_map(map);
	ft_printf("Error: %s\n", error_message);
	exit(0);
}
