/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmacmaho <bmacmaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:44:42 by bmacmaho          #+#    #+#             */
/*   Updated: 2022/12/06 17:21:01 by bmacmaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	length;
	size_t	i;
	size_t	j;

	j = 0;
	if (size == 0)
		return (ft_strlen(src));
	else if (size <= ft_strlen(dst))
		return (ft_strlen(src) + size);
	else
		length = ft_strlen(dst) + ft_strlen(src);
	i = ft_strlen(dst);
	while (i < (size - 1) && src[j] != '\0')
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (length);
}
