/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4send2b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmacmaho <bmacmaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 20:39:09 by bmacmaho          #+#    #+#             */
/*   Updated: 2023/02/15 20:39:08 by bmacmaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	ft_find_max_diff(t_pushswap *pushswap)
{
	t_stack	*temp;

	temp = pushswap->b;
	while (temp)
	{
		if (temp->diff > pushswap->curdiff)
			pushswap->curdiff = temp->diff;
		temp = temp->next;
	}
}

void	ft_find_min_diff(t_pushswap *pushswap)
{
	t_stack	*temp;

	temp = pushswap->b;
	while (temp)
	{
		if (abs(temp->diff) < abs(pushswap->curdiff))
			pushswap->curdiff = abs(temp->diff);
		temp = temp->next;
	}
}

int	ft_look_for_diff(t_pushswap *pushswap)
{
	t_stack	*temp;

	temp = pushswap->a;
	while (temp)
	{
		if (abs(temp->diff) <= pushswap->curdiff)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	ft_send_to_b(t_pushswap *pushswap)
{
	while (pushswap->a)
	{
		if (ft_look_for_diff(pushswap) == 1)
		{
			if (abs(pushswap->a->diff) <= pushswap->curdiff)
			{
				pb(pushswap);
				if (pushswap->b->diff < 0)
					rb(pushswap);
			}
			else
				ra(pushswap);
		}
		else
			pushswap->curdiff += pushswap->n * 4;
	}
}
