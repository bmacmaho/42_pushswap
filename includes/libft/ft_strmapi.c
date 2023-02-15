/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmacmaho <bmacmaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:49:20 by bmacmaho          #+#    #+#             */
/*   Updated: 2022/12/13 19:12:21 by bmacmaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*resarr;

	len = ft_strlen(s);
	resarr = malloc((len + 1) * sizeof(char));
	if (!resarr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		resarr[i] = (*f)(i, s[i]);
		i++;
	}
	resarr[i] = '\0';
	return (resarr);
}
