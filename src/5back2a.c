/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5back2a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmacmaho <bmacmaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 20:39:43 by bmacmaho          #+#    #+#             */
/*   Updated: 2023/02/15 17:25:51 by bmacmaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	ft_rotate_direction(t_pushswap *pushswap)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = pushswap->b;
	while (temp && temp->diff != pushswap->curdiff)
	{
		i++;
		temp = temp->next;
	}
	if (i <= (pushswap->blen / 2))
		rb(pushswap);
	else
		rrb(pushswap);
}

void	ft_b_funcs(t_pushswap *pushswap)
{	
	if (pushswap->b->diff == pushswap->curdiff)
	{
		pa(pushswap);
		pushswap->curdiff -= 2;
	}
	else if (pushswap->b->diff == pushswap->curdiff - 2)
		pa(pushswap);
	else if ((pushswap->b->val > pushswap->alast->val && pushswap->down > 0) \
		|| pushswap->down == 0)
	{
		pa(pushswap);
		ra(pushswap);
		pushswap->down += 1;
	}
	else if (pushswap->blast->diff == pushswap->curdiff - 2)
		rrb(pushswap);
	else
		ft_rotate_direction(pushswap);
}

int	ft_which_stack(t_stack *stack, t_pushswap *pushswap)
{
	int		i;
	t_stack	*temp;

	temp = stack;
	i = 0;
	while (temp)
	{
		if (temp->diff == pushswap->curdiff)
			return (i);
		i++;
		temp = temp->next;
	}
	return (-1);
}

void	ft_a_funcs(t_pushswap *pushswap)
{
	if (pushswap->a->diff == pushswap->curdiff)
		pushswap->curdiff -= 2;
	else if (pushswap->a->next->diff == pushswap->curdiff)
	{
		sa(pushswap);
		pushswap->curdiff -= 2;
	}
	else if (pushswap->alast->diff == pushswap->curdiff)
	{
		rra(pushswap);
		pushswap->curdiff -= 2;
		pushswap->down -= 1;
	}
	else
		exit (-1);
}

void	ft_bring_back(t_pushswap *pushswap)
{
	pushswap->down = 0;
	pushswap->curdiff = 0;
	ft_find_max_diff(pushswap);
	while (pushswap->b || pushswap->down > 0)
	{
		if (ft_which_stack(pushswap->a, pushswap) >= 0)
			ft_a_funcs(pushswap);
		else if (!pushswap->a)
		{
			pa(pushswap);
			if (pushswap->a->diff != pushswap->curdiff)
				pushswap->down += 1;
		}
		else if (ft_which_stack(pushswap->b, pushswap) >= 0)
			ft_b_funcs(pushswap);
		else
			pushswap->down = 0;
	}
	if (pushswap->a->next->diff == pushswap->curdiff)
		sa(pushswap);
	if (pushswap->alast->diff == pushswap->curdiff)
		rra(pushswap);
}
