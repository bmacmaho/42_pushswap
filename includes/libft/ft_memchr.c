/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmacmaho <bmacmaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:17:37 by bmacmaho          #+#    #+#             */
/*   Updated: 2022/12/05 21:41:10 by bmacmaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*sptr;

	sptr = (char *) s;
	while (n > 0)
	{
		if ((unsigned char) *sptr == (unsigned char)c)
		{
			return (sptr);
		}
		n--;
		sptr++;
	}
	return (0);
}
