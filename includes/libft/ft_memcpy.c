/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmacmaho <bmacmaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:30:07 by bmacmaho          #+#    #+#             */
/*   Updated: 2022/12/10 21:56:35 by bmacmaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, unsigned int n)
{
	size_t	i;
	char	*destptr;
	char	*srcptr;

	destptr = (char *) dest;
	srcptr = (char *) src;
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		destptr[i] = srcptr[i];
		i++;
	}
	return (destptr);
}
