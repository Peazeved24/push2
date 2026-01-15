/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:07:17 by peazeved          #+#    #+#             */
/*   Updated: 2026/01/15 18:43:51 by peazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void	ft_append(t_list **begin, void *data, size_t size)
{
	t_list	*new;
	t_list	*node;

	new = add_elem(data, size);
	if (!*begin)
	{
		*begin = new;
	}
	else
	{
		node = *begin;
		while (node->next)
			node = node->next;
		node->next = new;
	}
}

int	ft_list_size(t_list *begin)
{
	int	i;

	i = 0;
	while (begin)
	{
		begin = begin->next;
		i++;
	}
	return (i);
}

int	ft_is_sorted(t_list *node)
{
	int	val1;
	int	val2;

	if (!node)
		return (0);
	while (node->next)
	{
		val1 = *(int *)node->data;
		val2 = *(int *)node->next->data;
		if (val1 > val2)
			return (0);
		node = node->next;
	}
	return (1);
}
