/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:36:59 by peazeved          #+#    #+#             */
/*   Updated: 2026/01/08 18:19:13 by peazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
static void ft_free(char **ar)
{
    int i = 0;

    while(ar[i])
    {
        free(ar[i++]);
    }
    free(ar);
}
static void ft_picksort(t_list **stacka, t_list **stackb, int size)
{
    if(ft_is_sorted(*stacka))
        return;
    if(size <= 5)
    {
        if(size == 2)
            ft_sort2(stacka);
        else if(size == 3)
            ft_sort3(stacka);
        else if(size == 4)
            ft_sort4(stacka, stackb);   
        else if(size == 5)
            ft_sort5(stacka, stackb); 
    }
    else
    {
        ft_index(*stacka);
        ft_radixsort(stacka, stackb, ft_list_size(*stacka));
    }
}

int main(int ac, char **av)
{
    int i = 1;
    int j = 0;
    t_list *stacka = NULL;
    t_list *stackb = NULL;
    int val;
    while(i < ac)
    {
        char **ar = ft_split(av[i]);
        if(!ar || !ar[0])
        {
            write(1, "error\n", 6);
            return 1;
        }
        j = 0; // reiniciar a contagem
        while(ar[j]) // modular isto !!!!
        {
            if(!ft_save_atoi(ar[j], &val) ||ft_repeat_elem(stacka, val))
            {
                ft_free(ar);
                write(1, "error\n", 6);
                return 1;
            }
            j++;
            ft_append(&stacka, &val, sizeof(int));
        }
        i++;
        ft_free(ar);
    }
    ft_picksort(&stacka, &stackb , ft_list_size(stacka));
    ft_freelist(&stacka);
    ft_freelist(&stackb);
    return 0;
}

/*
    enquanto n chegar ao meu argc -
        - criar um arr == com a split pegar o meu av[i];
        - prencher esse array com os meus argumentos; (while(ar[j]))
            - a questao aqui e usar a ft-saveatoi para adicionar os meus valores dentro(verificao)
            ! se der erro:
                - free na split.
                - returna msg de error
*/
/*int main(int ac, char **av)
{
    int i = 1;
    t_list *stacka = NULL;
    t_list *stackb = NULL;
    int val;

    if(ac <= 2)
        return 0;
    while(i < ac)
    {
        if(!ft_save_atoi(av[i], &val)) // error aqui 
            return 1;
        if(ft_repeat_elem(stacka, val)) // error aqui
            return 1;
        ft_append(&stacka, &val, sizeof(int));
        i++; 
    }
    ft_picksort(&stacka, &stackb , ft_list_size(stacka));
    ft_freelist(&stacka);
    ft_freelist(&stackb);
    return 0;
}*/
