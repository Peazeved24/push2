/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opRadix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 12:44:58 by peazeved          #+#    #+#             */
/*   Updated: 2026/01/15 17:48:19 by peazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void	ft_index(t_list *node)
{
	t_list	*i;
	t_list	*j;
	int		index;

	i = node;
	while (i != NULL)
	{
		index = 0;
		j = node;
		while (j != NULL)
		{
			if (*(int *)j->data < *(int *)i->data)
				index++;
			j = j->next;
		}
		i->index = index;
		i = i->next;
	}
}

void	ft_radix2(int size, t_list **stacka, t_list **stackb, int bits)
{
	int	j;
	int	num;
	int	i;

	j = 0;
	num = 0;
	i = 0;
	while (i < bits)
	{
		j = 0;
		while (j < size)
		{
			num = (*stacka)->index;
			if (((num >> i) & 1) == 0)
				ft_pb(stacka, stackb);
			else
				ft_ra(stacka);
			j++;
		}
		while (*stackb != NULL)
			ft_pa (stacka, stackb);
		i++;
	}
}

void	ft_radixsort(t_list **stacka, t_list **stackb, int size)
{
	int	b;

	b = 0;
	while ((size - 1) >> b)
		b++;
	ft_radix2(size, stacka, stackb, b);
}
