/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:01:52 by sranaivo          #+#    #+#             */
/*   Updated: 2024/07/18 15:01:55 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	if (start >= ft_strlen(s))
		len = 0;
	else if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	i = 0;
	while (start + i < ft_strlen(s) && i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static size_t	count_word(const char *s, char c)
{
	size_t	nb_strings;

	nb_strings = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			while (*s != '\0' && *s != c)
				s++;
			nb_strings++;
			continue ;
		}
		s++;
	}
	return (nb_strings);
}

static void	ft_loop(char const *s, char **str, char c)
{
	size_t	i;
	size_t	j;
	size_t	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		j = 0;
		if (s[i] != c)
		{
			while ((s[i + j] != c) && (s[i + j] != 0))
				j++;
			str[word++] = ft_substr(s, i, j);
		}
		else
			i++;
		i += j;
	}
	str[word] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**str;

	str = malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!str)
		return (NULL);
	ft_loop(s, str, c);
	return (str);
}
