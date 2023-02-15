/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmacmaho <bmacmaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:40:04 by bmacmaho          #+#    #+#             */
/*   Updated: 2022/12/05 21:43:04 by bmacmaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*scpy;

	scpy = (char *) s;
	while ((unsigned char)*scpy != (unsigned char)c)
	{
		if (*scpy == '\0')
		{
			return (NULL);
		}
		scpy++;
	}
	return (scpy);
}
