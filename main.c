/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:24:30 by peazeved          #+#    #+#             */
/*   Updated: 2026/01/20 14:39:08 by peazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

static void	ft_picksort(t_list **stacka, t_list **stackb, int size)
{
	if (ft_is_sorted(*stacka))
		return ;
	if (size <= 5)
	{
		if (size == 2)
			ft_sort2 (stacka);
		else if (size == 3)
			ft_sort3 (stacka);
		else if (size == 4)
			ft_sort4 (stacka, stackb);
		else if (size == 5)
			ft_sort5 (stacka, stackb);
	}
	else
	{
		ft_index(*stacka);
		ft_radixsort(stacka, stackb, ft_list_size(*stacka));
	}
}

int	main(int ac, char **av)
{
	int			i;
	t_list		*stacka;
	t_list		*stackb;

	i = 1;
	stacka = NULL;
	stackb = NULL;
	while (i < ac)
	{
		if (ft_parse_arr(av[i], &stacka))
		{
			ft_freelist (&stacka);
			return (1);
		}
		i++;
	}
	ft_picksort (&stacka, &stackb, ft_list_size(stacka));
	ft_freelist (&stacka);
	ft_freelist (&stackb);
	return (0);
}
