/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmacmaho <bmacmaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:47:12 by bmacmaho          #+#    #+#             */
/*   Updated: 2023/02/09 22:50:19 by bmacmaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_free(char **returnarr, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(returnarr[i]);
		i++;
	}
	return (-1);
}

static int	ft_wordmalloc(const char *s, char c, char **returnarr)
{
	int	i;
	int	arrindex;

	arrindex = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			i = 0;
			while (*(s + i) != c && *(s + i) != '\0')
				i++;
			returnarr[arrindex] = malloc((i + 1) * sizeof(char));
			if (returnarr[arrindex] == NULL)
				return (ft_free(returnarr, arrindex));
			arrindex++;
			s += i;
		}
		else
			s++;
	}
	return (0);
}

static char	**ft_worddup(const char *s, char c, char **returnarr)
{
	int	i;
	int	j;
	int	arrindex;

	i = 0;
	arrindex = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			j = 0;
			while (s[i + j] != c && s[i + j] != '\0')
			{
				returnarr[arrindex][j] = s[i + j];
				j++;
			}
			returnarr[arrindex][j] = '\0';
			arrindex++;
			i = i + j;
		}
		else
			i++;
	}
	return (returnarr);
}

static int	ft_arrcount(const char *s, char c)
{
	int	words;
	int	i;
	int	exit;

	words = 1;
	i = 0;
	exit = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && exit == 0)
		{
			exit = 1;
			words++;
		}
		else if (s[i] == c)
		{
			exit = 0;
		}
		i++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**returnarr;
	int		words;

	words = ft_arrcount(s, c);
	returnarr = malloc(words * sizeof(char *));
	if (returnarr == NULL)
		return (NULL);
	returnarr[words - 1] = NULL ;
	if (ft_wordmalloc(s, c, returnarr) == -1)
	{
		free(returnarr);
		return (NULL);
	}
	return (ft_worddup(s, c, returnarr));
}
