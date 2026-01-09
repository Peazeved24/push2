/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:25:44 by peazeved          #+#    #+#             */
/*   Updated: 2026/01/08 17:56:54 by peazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"



int ft_space(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

int ft_cw(char *s)
{
	int i = 0;
	int c = 0;

	while(s[i])
	{
		while(s[i] && ft_space(s[i]))
			i++;
		if(s[i])
		{
			c++;
			while(s[i] && !ft_space(s[i]))
				i++;
		}
	}
	return c;
}

char *ft_getwords(char *s) // pego palavras.
{
	int i = 0;
	int len = 0;
	char *wd;
	
	while(s[len] && !ft_space(s[len]))
		len++;
	wd = malloc(len + 1);
	if(!wd)
		return NULL;
	while(i < len)
	{
		wd[i] = s[i];
		i++;
	}
	wd[i] = '\0';
	return wd;
}

int ft_fw(char **ar, char *s)
{
	int i = 0;
	int j = 0;
	while(s[i])
	{
		while(s[i] && ft_space(s[i])) // pula espacos
			i++;
		if(s[i]) // palavra!
		{
			ar[j] = ft_getwords(&s[i]); // pega a palvra associa ao array.
			if(!ar[j]) // condicao de seguranca.
			{
				while(j > 0) // LIMPA 
					free(ar[--j]);
				return 0;
			}
			while(s[i] && !ft_space(s[i]))
				i++;
			j++;
		}
	}
	return 1;
}
/*
	- dar fill !
		- pegar a palvra.
		- caso for espaco -- pula
			- se ainda n for null
				- associa a palvra ao arr.
					- condicao de seguranca -- free ate chegar a 0 e return 0;
				- se nao , enquanto n chegar ao fim , pula os char.
*/

char	**ft_split(char *s)
{
	int len = ft_cw(s);
	char **ar = malloc(sizeof(char *) * (len + 1));
	if(!ar)
		return NULL;
	if(!s)
		return NULL;
	if(!ft_fw(ar, s))
	{
		free(ar);
		return NULL;
	}
	ar[len] = NULL;
	return ar;
}
/*
	- entender o len da palavra
		criar o arr --- que recebe o tamanho total das palavras pegas/
		 as condicoes de seguranca 
		 		
		se a ft_fw nao falhar.
			free(no array)
			return NULL;
			
		arr[len] = NULL (array valido)
		RETURN ARR'
*/


/*
int ft_space(char c)
{
	return (c == 32);
}

int ft_wlen(char *s)
{
	int i = 0;
	int c = 0;

	while(s[i])
	{
		while(s[i] && ft_space(s[i]))
			i++;
		if(s[i])
		{
			c++;
			while(s[i] && !ft_space(s[i]))
				i++;
		}
		i++;
	}
	return c;
}

char    **ft_split(char *str)
{
    char **ar;
    int i = 0;
    int j = 0;
	
    ar = malloc(sizeof(char*) * (ft_wlen(str) + 1)); // alocar espaco no arr
    if(!ar)
        return NULL;
    while(str[i]) // pegar cada palvra.
    {
        while(ft_space(str[i]))
            i++;
        if(str[i])
        {  
            int start = i;
            while(str[i] && !ft_space(str[i]))
                i++;
            int len = i - start;
            ar[j] = malloc(len + 1);
            if(!ar[j]) 
                return NULL;
            int k = 0;
            while(k < len)
            {
                ar[j][k] = str[start + k];
                k++;
            }
            ar[j][k] = '\0';
            j++;    
        }
    }
    ar[j] = NULL;
    return ar;
}

int main()
{
	char *s = "1 3 4     5";
	char **ar = ft_split(s);
	int i = 0;
	while(ar[i])	
		printf("%s", ar[i++]);
	return 0;
}*/