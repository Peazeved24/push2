/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsmain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:07:03 by peazeved          #+#    #+#             */
/*   Updated: 2026/01/15 18:44:10 by peazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void	ft_freelist(t_list **head)
{
	t_list	*node;
	t_list	*tmp;

	node = *head;
	while (node)
	{
		tmp = node->next;
		free(node->data);
		free(node);
		node = tmp;
	}
	*head = NULL;
}

void	ft_free_arr(char **ar)
{
	int	i;

	i = 0;
	while (ar[i])
	{
		free(ar[i++]);
	}
	free(ar);
}

int	ft_parsearr(char *str, t_list **stacka)
{
	int		j;
	int		val;
	char	**ar;

	ar = ft_split(str);
	j = 0;
	while (ar[j])
	{
		if (!ft_save_atoi(ar[j], &val) || ft_repeat_elem(*stacka, val))
		{
			ft_free_arr(ar);
			write(1, "error\n", 6);
			return (1);
		}
		j++;
		ft_append(stacka, &val, sizeof(int));
	}
	free(ar);
	return (0);
}
