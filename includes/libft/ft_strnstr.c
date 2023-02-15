/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmacmaho <bmacmaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:05:33 by bmacmaho          #+#    #+#             */
/*   Updated: 2022/12/06 17:18:41 by bmacmaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*bigptr;
	size_t	i;
	int		j;

	bigptr = (char *) big;
	if (little[0] == '\0')
		return (bigptr);
	i = 0;
	while (i < len && bigptr[i] != '\0')
	{
		j = 0;
		while ((bigptr[i + j] == little[j]) && (little[j] != '\0')
			&& ((i + j) < len) && (bigptr[i + j] != '\0'))
		{
			j++;
		}
		if (little[j] == '\0')
		{
			return (bigptr + i);
		}
		i++;
	}
	return (0);
}
