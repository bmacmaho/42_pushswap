/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswaprot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmacmaho <bmacmaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 18:04:08 by bmacmaho          #+#    #+#             */
/*   Updated: 2023/02/14 20:57:52 by bmacmaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	sb(t_pushswap *pushswap)
{
	t_stack	*temp;

	write(1, "sb\n", 3);
	if (pushswap->b)
	{
		if (pushswap->b->next)
		{
			temp = pushswap->b->next;
			pushswap->b->next = pushswap->b->next->next;
			if (pushswap->b->next)
				pushswap->b->next->prev = pushswap->b;
			pushswap->b->prev = temp;
			temp->next = pushswap->b;
			temp->prev = NULL;
			pushswap->b = temp;
			if (pushswap->b == pushswap->blast)
				pushswap->blast = pushswap->b->next;
		}
	}
}

void	ra(t_pushswap *pushswap)
{
	t_stack		*temp;

	write(1, "ra\n", 3);
	if (pushswap->a)
	{
		temp = pushswap->a;
		if (temp->next)
		{
			pushswap->a = pushswap->a->next;
			pushswap->a->prev = NULL;
			pushswap->alast->next = temp;
			temp->prev = pushswap->alast;
			temp->next = NULL;
			pushswap->alast = temp;
		}
	}
}

void	rb(t_pushswap *pushswap)
{
	t_stack		*temp;

	write(1, "rb\n", 3);
	if (pushswap->b)
	{
		temp = pushswap->b;
		if (temp->next)
		{
			pushswap->b = pushswap->b->next;
			pushswap->b->prev = NULL;
			pushswap->blast->next = temp;
			temp->prev = pushswap->blast;
			temp->next = NULL;
			pushswap->blast = temp;
		}
	}
}

void	rra(t_pushswap *pushswap)
{
	t_stack		*temp;

	write(1, "rra\n", 4);
	if (pushswap->alast)
	{
		temp = pushswap->alast;
		if (temp->prev)
		{
			pushswap->alast = pushswap->alast->prev;
			pushswap->alast->next = NULL;
			pushswap->a->prev = temp;
			temp->next = pushswap->a;
			temp->prev = NULL;
			pushswap->a = temp;
		}
	}
}

void	rrb(t_pushswap *pushswap)
{
	t_stack		*temp;

	write(1, "rrb\n", 4);
	if (pushswap->blast)
	{
		temp = pushswap->blast;
		if (temp->prev)
		{
			pushswap->blast = pushswap->blast->prev;
			pushswap->blast->next = NULL;
			pushswap->b->prev = temp;
			temp->next = pushswap->b;
			temp->prev = NULL;
			pushswap->b = temp;
		}
	}
}
