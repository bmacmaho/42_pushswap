/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmacmaho <bmacmaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:44:27 by bmacmaho          #+#    #+#             */
/*   Updated: 2022/12/15 16:46:42 by bmacmaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*scpy;

	scpy = s;
	while (*scpy != '\0')
	{
		scpy++;
	}
	while (*scpy != (char)c)
	{
		if (scpy == s)
			return (NULL);
		scpy--;
	}
	return ((char *)scpy);
}
