/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmacmaho <bmacmaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:45:50 by bmacmaho          #+#    #+#             */
/*   Updated: 2022/12/10 21:17:20 by bmacmaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1ptr;
	unsigned char	*s2ptr;
	size_t			i;

	i = 0;
	s1ptr = (unsigned char *) s1;
	s2ptr = (unsigned char *) s2;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (i < n)
	{
		if (s1ptr[i] != s2ptr[i])
		{
			return (s1ptr[i] - s2ptr[i]);
		}
		i++;
	}
	return (0);
}
