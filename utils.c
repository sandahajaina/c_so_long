/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:40:52 by sranaivo          #+#    #+#             */
/*   Updated: 2024/07/18 15:40:53 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
