/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmacmaho <bmacmaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 20:40:10 by bmacmaho          #+#    #+#             */
/*   Updated: 2023/02/15 21:05:58 by bmacmaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	main(int argc, char **argv)
{
	t_pushswap	pushswap;

	if (ft_errors(argc, argv) == -1)
		return (write(2, "Error\n", 6));
	if (argc <= 2)
		return (-1);
	if (ft_prepstacks(argc, argv, &pushswap) == -1)
		return (write(2, "Error\n", 6));
	if (ft_issorted(&pushswap) == -1)
		ft_presort(&pushswap);
	ft_free_everything(&pushswap);
	return (0);
}
