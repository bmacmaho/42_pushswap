/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfuncs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmacmaho <bmacmaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 21:09:54 by bmacmaho          #+#    #+#             */
/*   Updated: 2023/01/12 16:25:09 by bmacmaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthex(unsigned int hex, int *printlength, int c)
{
	if (hex >= 16)
	{
		ft_puthex(hex / 16, printlength, c);
		ft_puthex(hex % 16, printlength, c);
	}
	else
	{
		if (hex < 10)
			ft_putchar_fd(hex + 48, 1);
		else
		{
			if (c == 0)
				ft_putchar_fd(hex + (97 - 10), 1);
			else
				ft_putchar_fd(hex + (65 - 10), 1);
		}
		*printlength += 1;
	}
}

void	ft_putpointerhex(unsigned long long hex, int *printlength)
{
	if (hex >= 16)
	{
		ft_putpointerhex(hex / 16, printlength);
		ft_putpointerhex(hex % 16, printlength);
	}
	else
	{
		if (hex < 10)
			ft_putchar_fd(hex + 48, 1);
		else
			ft_putchar_fd(hex + (97 - 10), 1);
		*printlength += 1;
	}
}

void	ft_str(char *s, int *printlength)
{
	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		*printlength += 6;
	}
	else
	{
		ft_putstr_fd(s, 1);
		*printlength += ft_strlen(s);
	}
}

void	ft_num(int n, int *printlength)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", 1);
		*printlength += 11;
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', 1);
		*printlength += 1;
		n = n * (-1);
	}
	if (n >= 10)
	{
		ft_num((n / 10), printlength);
		ft_num((n % 10), printlength);
	}
	else if (n >= 0 && n < 10)
	{
		ft_putchar_fd((n + 48), 1);
		*printlength += 1;
	}
}

void	ft_unsignedint(unsigned int n, int *printlength)
{
	if (n >= 10)
	{
		ft_unsignedint((n / 10), printlength);
		ft_unsignedint((n % 10), printlength);
	}
	else if (n < 10)
	{
		ft_putchar_fd((n + 48), 1);
		*printlength += 1;
	}
}
