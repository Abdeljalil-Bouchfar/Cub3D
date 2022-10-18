/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ressalhi <ressalhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:58:06 by ressalhi          #+#    #+#             */
/*   Updated: 2022/09/06 11:49:39 by ressalhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1 || !s2)
		return (0);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (0);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*str;

	str = malloc(ft_strlen(s) + 1);
	if (!str)
		return (0);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	slen;
	size_t	i;
	size_t	j;

	if (!s)
		return (0);
	slen = ft_strlen((char *)s);
	if (start > slen)
		return (ft_strdup(""));
	if (slen - start >= len)
		str = malloc(len + 1);
	else
		str = malloc(slen - start + 1);
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (s[start] && j < len)
	{
		str[i++] = s[start++];
		j++;
	}
	str[i] = '\0';
	return (str);
}
