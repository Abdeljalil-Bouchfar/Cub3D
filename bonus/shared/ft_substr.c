/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:16:56 by abouchfa          #+#    #+#             */
/*   Updated: 2022/11/07 12:35:55 by abouchfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_l;
	char	*res;

	if (!s)
		return (NULL);
	i = 0;
	s_l = ft_strlen(s);
	while (i < s_l && i < len)
		i++;
	res = malloc (sizeof(char) * i + 1);
	if (!res)
		return (0);
	i = -1;
	while (++i < len && start < s_l)
		res[i] = s[start++];
	res[i] = 0;
	return (res);
}
