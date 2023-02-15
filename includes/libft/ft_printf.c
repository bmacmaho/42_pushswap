/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmacmaho <bmacmaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:55:38 by bmacmaho          #+#    #+#             */
/*   Updated: 2023/01/05 15:00:14 by bmacmaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_pointer(unsigned long long hex, int *printlength)
{
	if (hex <= 0)
	{
		ft_putstr_fd("(nil)", 1);
		*printlength += 5;
	}
	else
	{
		ft_putstr_fd("0x", 1);
		*printlength += 2;
		ft_putpointerhex(hex, printlength);
	}
}

void	ft_prehex(unsigned int hex, int *printlength, int c)
{
	if (hex == 0)
	{
		ft_putchar_fd('0', 1);
		*printlength += 1;
	}
	else
		ft_puthex(hex, printlength, c);
}

void	ft_convertfilter(va_list args, char a, int *printlength)
{
	if (a == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		*printlength += 1;
	}
	else if (a == 's')
		ft_str(va_arg(args, char *), printlength);
	else if (a == 'p')
		ft_pointer(va_arg(args, unsigned long long), printlength);
	else if (a == 'd' || a == 'i')
		ft_num(va_arg(args, int), printlength);
	else if (a == 'u')
		ft_unsignedint(va_arg(args, unsigned int), printlength);
	else if (a == 'x')
		ft_prehex(va_arg(args, unsigned int), printlength, 0);
	else if (a == 'X')
		ft_prehex(va_arg(args, unsigned int), printlength, 1);
	else if (a == '%')
	{
		ft_putchar_fd('%', 1);
		*printlength += 1;
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		printlength;
	size_t	i;

	va_start(args, format);
	i = 0;
	printlength = 0;
	while (i < ft_strlen(format))
	{
		if (format[i] == '%')
		{
			ft_convertfilter(args, format[i + 1], &printlength);
			i++;
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			printlength++;
		}
		i++;
	}
	va_end(args);
	return (printlength);
}
