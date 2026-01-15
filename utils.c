/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:42:19 by peazeved          #+#    #+#             */
/*   Updated: 2026/01/15 18:42:10 by peazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void	ft_puts(char c, int *s)
{
	if (c == '-')
		*s = -1;
	else
		*s = 1;
}

int	ft_save_atoi(const char *str, int *out)
{
	long long	n;
	int			s;

	n = 0;
	s = 1;
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '-' || *str == '+')
	{
		ft_puts(*str, &s);
		str++;
	}
	if (!*str)
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		n = n * 10 + (*str - '0');
		if ((n * s) > INT_MAX || (n * s) < INT_MIN)
			return (0);
		str++;
	}
	*out = (int)(n * s);
	return (1);
}

t_list	*add_elem(void *data, size_t size)
{
	size_t	i;
	t_list	*node;

	i = 0;
	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->data = malloc(size);
	if (!node->data)
		return (NULL);
	while (i < size)
	{
		((char *)node->data)[i] = ((char *)data)[i];
		i++;
	}
	node->next = NULL;
	return (node);
}

int	ft_repeat_elem(t_list *begin, int value)
{
	t_list	*node;

	node = begin;
	while (node)
	{
		if (*(int *)node->data == value)
			return (1);
		node = node->next;
	}
	return (0);
}
