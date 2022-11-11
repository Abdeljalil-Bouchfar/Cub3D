/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:46:50 by abouchfa          #+#    #+#             */
/*   Updated: 2022/11/08 18:23:57 by abouchfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	ft_rotateleft(t_game *g)
{
	g->pa -= 3;
	if (g->pa < 0)
		g->pa += 360;
	g->pdx = cos(degtorad(g->pa)) * P_SPEED;
	g->pdy = sin(degtorad(g->pa)) * P_SPEED;
}

int	red_cross(void)
{
	ft_error("EXIT\n");
	return (0);
}

void	ft_error(char *str)
{
	printf("%s", str);
	ft_lstclear();
	exit (1);
}
