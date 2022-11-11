/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 20:23:22 by ressalhi          #+#    #+#             */
/*   Updated: 2022/11/08 14:37:47 by abouchfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static void	ft_bzero(void *s, size_t n)
{
	char	*str;

	str = s;
	while (n > 0)
	{
		*str = 0;
		n--;
		str++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;

	s = alloc(count * size);
	if (!s)
		return (0);
	ft_bzero(s, (count * size));
	return (s);
}
