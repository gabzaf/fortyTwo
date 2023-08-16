/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste_ft_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:31:07 by gamado-x          #+#    #+#             */
/*   Updated: 2023/05/16 17:43:19 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_insert(char const *s, char c, char **tab, size_t i)
{
	int	n;
	int	j;

	n = 0;
	while (i < (ft_strlen(s)))
	{
		j = 0;
		if (s[i] == c)
		{
			while (s[i] == c && (i < (ft_strlen(s))))
				i++;
		}
		else if (s[i] != c)
		{
			while (s[i] != c && (i < (ft_strlen(s))))
			{
				tab[n][j] = s[i];
				i++;
				j++;
			}
			tab[n][j] = '\0';
			n++;
		}
	}
}

void	ft_allocate(char **tab, int nchar, int ntab)
{
	tab[ntab] = malloc((nchar + 1) * sizeof(char));
	if (!tab)
		return ;
}

void	ft_countchars(char const *s, char c, char **tab, int tabsize)
{
	size_t	i;
	int		nchars;
	int		ntab;

	i = 0;
	ntab = 0;
	while (i < (ft_strlen(s)) && (ntab < tabsize))
	{
		nchars = 0;
		if (s[i] == c)
		{
			while (s[i] == c && (i < (ft_strlen(s))))
				i++;
		}
		else if (s[i] != c)
		{
			while (s[i] != c && (i < (ft_strlen(s))))
			{
				nchars++;
				i++;
			}
			ft_allocate(tab, nchars, ntab);
			ntab++;
		}
	}
}

int	ft_countwords(char const *s, char c, char **tab)
{
	size_t	i;
	int		countedwords;

	i = 0;
	countedwords = 0;
	while (i < (ft_strlen(s)))
	{
		if (s[i] == c)
		{
			while (s[i] == c && (i < (ft_strlen(s))))
				i++;
		}
		else if (s[i] != c)
		{
			countedwords++;
			while (s[i] != c && (i < (ft_strlen(s))))
				i++;
		}
	}
	tab = (char **)malloc((countedwords + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	return (countedwords);
}

char	**ft_split(char const *s, char c)
{
	size_t		i;
	char	**tab;

	if (!s)
		return (NULL);
	if ((ft_strchr(s, c)) == NULL)
	{
		ft_allocate(tab, ft_strlen(s) , 0);
		i = 0;
		while (s[i])
		{
			tab[0][i] = s[i];
			i++;
		}
		tab[0][i] = '\0';
		return (tab);
	}
	i = 0;
	nwords = ft_countwords(s, c, tab);
	ft_countchars(s, c, tab, nwords);
	ft_insert(s, c, tab, 0);
	return (tab);
}

int	main()
{
	char const	string[] = "\0aa\0bbb";
	char	delimiter = '\0';
	char	**tab = ft_split(string, delimiter);
	for (int i = 0; i < ft_countwords(string, delimiter); i++)
	{
		int	j = 0;
		while (j < 11)
		{
			printf("%c", tab[i][j]);
			j++;
		}
		printf("\n");
	}
	if (!tab)
		return (0);
	free(tab);
	return (0);
}
