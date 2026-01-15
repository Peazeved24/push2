/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opSort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 18:03:42 by peazeved          #+#    #+#             */
/*   Updated: 2026/01/15 18:09:28 by peazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

static void	ft_shortbreak(t_list **stack, t_list *node, int size)
{
	int		pos;
	t_list	*tmp;

	pos = 0;
	tmp = *stack;
	while (tmp && tmp != node)
	{
		tmp = tmp->next;
		pos++;
	}
	if (pos <= size / 2)
		while (*stack != node)
			ft_ra (stack);
	else
		while (*stack != node)
			ft_rra (stack);
}

void	ft_sort2(t_list **stacka)
{
	t_list	*node;

	if (!stacka)
		return ;
	node = *stacka;
	if (*(int *)node->data > *(int *) node->next->data)
		ft_sa (stacka);
}

void	ft_sort3(t_list **stacka)
{
	int	first;
	int	second;
	int	third;

	if (!stacka)
		return ;
	first = *(int *)(*stacka)->data;
	second = *(int *)(*stacka)->next->data;
	third = *(int *)(*stacka)->next->next->data;
	if (first > second && second < third && first < third)
		ft_sa(stacka);
	else if (first > second && second > third)
		(ft_sa(stacka), ft_rra(stacka));
	else if (first > second && second < third && first > third)
		ft_ra(stacka);
	else if (first < second && second > third && first < third)
		(ft_sa(stacka), ft_ra(stacka));
	else if (first < second && second > third && first > third)
		ft_rra(stacka);
}

void	ft_sort4(t_list **stacka, t_list **stackb)
{
	t_list	*tmp;
	t_list	*max;

	if (!stacka)
		return ;
	tmp = *stacka;
	max = *stacka;
	while (tmp)
	{
		if (*(int *)max->data > *(int *)tmp->data)
			max = tmp;
		tmp = tmp->next;
	}
	ft_shortbreak (stacka, max, ft_list_size(*stacka));
	ft_pb (stacka, stackb);
	ft_sort3 (stacka);
	ft_pa (stacka, stackb);
}

void	ft_sort5(t_list **stacka, t_list **stackb)
{
	t_list	*min;
	t_list	*tmp;
	int		i;

	if (!stacka)
		return ;
	i = 0;
	while (i++ < 2)
	{
		tmp = *stacka;
		min = tmp;
		while (tmp)
		{
			if (*(int *)tmp->data < *(int *)min->data)
				min = tmp;
			tmp = tmp->next;
		}
		ft_shortbreak (stacka, min, ft_list_size(*stacka));
		ft_pb (stacka, stackb);
	}
	ft_sort3 (stacka);
	ft_pa (stacka, stackb);
	ft_pa (stacka, stackb);
}
