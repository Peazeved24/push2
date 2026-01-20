/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 13:23:03 by peazeved          #+#    #+#             */
/*   Updated: 2026/01/20 14:39:04 by peazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
	int				index;
}					t_list;

// srcs
int					ft_save_atoi(const char *str, int *out);
int					ft_repeat_elem(t_list *begin, int value);
t_list				*add_elem(void *data, size_t size);
void				ft_append(t_list **begin, void *data, size_t size);
int					ft_list_size(t_list *begin);
int					ft_is_sorted(t_list *node);
// COMANDOS
void				ft_pa(t_list **stacka, t_list **stackb);
void				ft_pb(t_list **stacka, t_list **stackb);
void				ft_ra(t_list **stacka);
void				ft_rb(t_list **stackb);
void				ft_rr(t_list **stacka, t_list **stackb);
void				ft_sa(t_list **stacka);
void				ft_sb(t_list **stackb);
void				ft_ss(t_list **stacka, t_list **stackb);
void				ft_rra(t_list **stacka);
void				ft_rrb(t_list **stackb);
void				ft_rrr(t_list **stacka, t_list **stackb);
// sort
void				ft_sort2(t_list **stacka);
void				ft_sort3(t_list **stacka);
void				ft_sort4(t_list **stacka, t_list **stackb);
void				ft_sort5(t_list **stacka, t_list **stackb);
void				ft_radixsort(t_list **stacka, t_list **stackb, int size);
void				ft_index(t_list *node);
// utils main!! -- para a minha nova main modulada.
void				ft_free_arr(char **ar);
void				ft_freelist(t_list **head);
char				**ft_split(char *s);
int					ft_parse_arr(char *str, t_list **stacka);

#endif