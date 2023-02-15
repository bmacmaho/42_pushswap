/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmacmaho <bmacmaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:04:03 by bmacmaho          #+#    #+#             */
/*   Updated: 2022/12/06 18:00:13 by bmacmaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_trim(const char *nptr, int *sign)
{
	int	i;

	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t'
		|| nptr[i] == '\n' || nptr[i] == '\v'
		|| nptr[i] == '\f' || nptr[i] == '\r')
	{
		i++;
	}
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
		{
			*sign *= -1;
			i++;
		}
		else
		{
			i++;
		}
	}
	return (i);
}

static int	ft_char_is_numeric(const char *c)
{
	if (*c >= '0' && *c <= '9')
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	nb;
	int	sign;
	int	i;

	nb = 0;
	sign = 1;
	i = ft_trim(nptr, &sign);
	while (nptr[i] != '\0' && ft_char_is_numeric(&nptr[i]) == 1)
	{
		while (ft_char_is_numeric(&nptr[i]) == 1)
		{
			nb += (nptr[i] - 48);
			if (ft_char_is_numeric(&nptr[i + 1]) == 1)
			{
				nb *= 10;
				i++;
			}
			else
			{
				return (nb * sign);
			}
		}
	}
	return (nb * sign);
}
