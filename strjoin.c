/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:28:16 by peazeved          #+#    #+#             */
/*   Updated: 2026/01/08 17:30:17 by peazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

static int ft_strlen(char *s)
{
	int i = 0;
	while(s[i])
		i++;
	return i;
}

char *ft_strjoin(char *s1, char *s2)
{
	int i = 0;
	int j = 0;
	int l1 = ft_strlen(s1);
	int l2 = ft_strlen(s2);
	if(!s1 || !s2)
		return NULL;
	char *s = malloc((l1 + l2) + 1);
	if(!s)
		return NULL;
	while(i < l1)
	{
		s[i] = s1[i];
		i++;
	}
	while(j < l2)
		s[i++] = s2[j++];
	s[i] = '\0';
	return s;
}
int main()
{
	char a[] = "ola ";
	char b[] = "mundo";
	char *result = ft_strjoin(a, b);
	printf("%s", result);
	return 0;
}