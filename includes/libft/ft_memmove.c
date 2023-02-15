/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmacmaho <bmacmaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:29:04 by bmacmaho          #+#    #+#             */
/*   Updated: 2022/12/05 20:01:59 by bmacmaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*destptr;
	char		*srcptr;

	i = 0;
	destptr = (char *) dest;
	srcptr = (char *) src;
	if (src > dest)
	{
		while (i < n)
		{
			destptr[i] = srcptr[i];
			i++;
		}
	}
	else
	{
		while (n--)
		{
			destptr[n] = srcptr[n];
		}
	}
	return (dest);
}
