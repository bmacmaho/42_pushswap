/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1errors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmacmaho <bmacmaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 20:40:17 by bmacmaho          #+#    #+#             */
/*   Updated: 2023/02/15 21:16:21 by bmacmaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

static int	ft_isargabunchofzeroes(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	if (arg[i] == '0')
	{
		if (arg[i + 1] == '0')
			return (-1);
	}
	return (0);
}

static int	ft_isargint(char *arg)
{	
	size_t	len;

	len = ft_strlen(arg);
	if (len > 11)
		return (-1);
	if (len == 11)
	{
		if (*arg == '-' || *arg == '+')
		{
			arg++;
			if (ft_strncmp(arg, "2147483648", 10) > 0)
				return (-1);
			else
				return (0);
		}
		else
			return (-1);
	}
	if (arg[0] == '-' || arg[0] == '+' || len < 10)
		return (0);
	if (ft_strncmp(arg, "2147483647", 10) > 0)
		return (-1);
	return (0);
}

static int	ft_isargrepeated(char **argv, int i)
{
	int	j;

	j = 1;
	while (j < i)
	{
		if (ft_atoi(argv[j]) == ft_atoi(argv[i]))
			return (-1);
		j++;
	}
	return (0);
}

static int	ft_isargnum(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i] != '\0')
	{
		if (!ft_isdigit(arg[i]))
			return (-1);
		i++;
	}
	return (0);
}

int	ft_errors(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_isargnum(argv[i]) == -1)
			return (-1);
		if (ft_isargint(argv[i]) == -1)
			return (-1);
		if (ft_isargrepeated(argv, i) == -1)
			return (-1);
		if (ft_isargabunchofzeroes(argv[i]) == -1)
			return (-1);
		i++;
	}
	return (0);
}
