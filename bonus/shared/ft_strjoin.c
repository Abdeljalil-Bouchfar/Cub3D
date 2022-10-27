/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ressalhi <ressalhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:27:58 by abouchfa          #+#    #+#             */
/*   Updated: 2022/10/27 15:27:42 by ressalhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	size_t	size;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen((char *) s1) + ft_strlen((char *) s2) + 1;
	res = malloc(sizeof(char) * size);
	if (!res)
		return (0);
	i = 0;
	j = 0;
	while (s1[j])
		res[i++] = s1[j++];
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = 0;
	return (res);
}
