/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmacmaho <bmacmaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:54:43 by bmacmaho          #+#    #+#             */
/*   Updated: 2022/12/10 21:16:49 by bmacmaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numlen(int n)
{
	size_t	length;

	length = 2;
	if (n < 0)
	{
		length++;
		n *= -1;
	}
	while (n >= 10)
	{
		length++;
		n /= 10;
	}
	return (length);
}

static void	ft_putnbr_str(int n, char *numstr, size_t *numlen, size_t *i)
{
	if (*i < (*numlen - 1))
	{
		if (n < 0)
		{
			numstr[*i] = '-';
			n = n * (-1);
			*i = *i + 1;
		}
		if (n >= 10)
		{
			ft_putnbr_str((n / 10), numstr, numlen, i);
			ft_putnbr_str((n % 10), numstr, numlen, i);
		}
		else if (n >= 0 && n < 10)
		{
			numstr[*i] = n + 48;
			*i = *i + 1;
		}
	}
}

char	*ft_itoa(int n)
{
	size_t	numlen;
	char	*numstr;
	size_t	i;

	i = 0;
	if (n == -2147483648)
	{
		numstr = ft_strdup("-2147483648");
		return (numstr);
	}
	numlen = ft_numlen(n);
	numstr = (char *) malloc(numlen * sizeof(char));
	if (numstr == NULL)
		return (NULL);
	ft_putnbr_str(n, numstr, &numlen, &i);
	numstr[numlen - 1] = '\0';
	return (numstr);
}
