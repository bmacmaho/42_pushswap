/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmacmaho <bmacmaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:43:53 by bmacmaho          #+#    #+#             */
/*   Updated: 2022/12/13 19:17:54 by bmacmaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_setcheck(unsigned int start, const char *s1, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (s1[start] == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	end;
	size_t			rslength;
	char			*returnstr;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	if (*s1 == '\0' || *set == '\0')
		return (ft_strdup((char *)s1));
	while (ft_setcheck(start, s1, set) == 1)
		start++;
	end = ft_strlen(s1) - 1;
	while (ft_setcheck(end, s1, set) == 1 && end > start && end > 0)
		end--;
	rslength = end - start;
	returnstr = malloc((rslength + 1) * sizeof(char));
	if (returnstr == NULL)
		return (NULL);
	returnstr = ft_substr(s1, start, rslength + 1);
	return (returnstr);
}
