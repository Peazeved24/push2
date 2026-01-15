/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:25:44 by peazeved          #+#    #+#             */
/*   Updated: 2026/01/15 18:20:08 by peazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

int	ft_space(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

int	ft_cw(char *s)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (s[i])
	{
		while (s[i] && ft_space(s[i]))
			i++;
		if (s[i])
		{
			c++;
			while (s[i] && !ft_space(s[i]))
				i++;
		}
	}
	return (c);
}

char	*ft_getwords(char *s)
{
	int		i;
	int		len;
	char	*wd;

	i = 0;
	len = 0;
	while (s[len] && !ft_space(s[len]))
		len++;
	wd = malloc(len + 1);
	if (!wd)
		return (NULL);
	while (i < len)
	{
		wd[i] = s[i];
		i++;
	}
	wd[i] = '\0';
	return (wd);
}

int	ft_fw(char **ar, char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && ft_space(s[i]))
			i++;
		if (s[i])
		{
			ar[j] = ft_getwords(&s[i]);
			if (!ar[j])
			{
				while (j > 0)
					free(ar[--j]);
				return (0);
			}
			while (s[i] && !ft_space(s[i]))
				i++;
			j++;
		}
	}
	return (1);
}

char	**ft_split(char *s)
{
	int		len;
	char	**ar;

	if (!s)
		return (NULL);
	len = ft_cw(s);
	ar = malloc(sizeof(char *) * (len + 1));
	if (!ar)
		return (NULL);
	if (!ft_fw(ar, s))
	{
		free(ar);
		return (NULL);
	}
	ar[len] = (NULL);
	return (ar);
}
