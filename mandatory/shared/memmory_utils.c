/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmory_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 01:22:42 by abouchfa          #+#    #+#             */
/*   Updated: 2022/11/08 18:21:20 by abouchfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_lstclear(void)
{
	t_allocs	*temp;

	while (*g_allocs)
	{
		temp = (*g_allocs)->next;
		if (*g_allocs && (*g_allocs)->content)
			free((*g_allocs)->content);
		if (*g_allocs)
			free(*g_allocs);
		(*g_allocs) = temp;
	}
}

t_allocs	*ft_lstnew(void *content)
{
	t_allocs	*list;

	list = malloc(sizeof(t_allocs));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

void	ft_lstadd_front(t_allocs	*new)
{
	if (!new)
		return ;
	if (*g_allocs)
		new->next = *g_allocs;
	*g_allocs = new;
}

void	*alloc(size_t size)
{
	void	*content;

	content = malloc(size);
	if (!content)
	{
		perror("");
		ft_lstclear();
		exit(1);
	}
	ft_lstadd_front(ft_lstnew(content));
	return (content);
}
