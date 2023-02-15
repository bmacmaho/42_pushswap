/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psrab.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmacmaho <bmacmaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:13:31 by bmacmaho          #+#    #+#             */
/*   Updated: 2023/02/14 20:57:56 by bmacmaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	sa(t_pushswap *pushswap)
{
	t_stack	*temp;

	write(1, "sa\n", 3);
	if (pushswap->a)
	{
		if (pushswap->a->next)
		{
			temp = pushswap->a->next;
			pushswap->a->next = pushswap->a->next->next;
			if (pushswap->a->next)
				pushswap->a->next->prev = pushswap->a;
			pushswap->a->prev = temp;
			temp->next = pushswap->a;
			temp->prev = NULL;
			pushswap->a = temp;
			if (pushswap->a == pushswap->alast)
				pushswap->alast = pushswap->a->next;
		}
	}
}

void	ft_extend_pa(t_pushswap *pushswap)
{
	t_stack	*temp;

	temp = pushswap->b;
	pushswap->a = temp;
	pushswap->b = pushswap->b->next;
	pushswap->a->next = NULL;
	pushswap->alast = pushswap->a;
	pushswap->alen += 1;
	if (pushswap->b)
		pushswap->b->prev = NULL;
	else
		pushswap->blast = NULL;
	pushswap->blen -= 1;
}

void	pa(t_pushswap *pushswap)
{
	t_stack	*temp;

	temp = pushswap->b;
	write(1, "pa\n", 3);
	if (pushswap->b)
	{
		if (!(pushswap->a))
			ft_extend_pa(pushswap);
		else
		{		
			pushswap->b = pushswap->b->next;
			pushswap->blen -= 1;
			temp->next = pushswap->a;
			pushswap->a->prev = temp;
			pushswap->a = temp;
			pushswap->alen += 1;
			if (pushswap->b)
				pushswap->b->prev = NULL;
			else
				pushswap->blast = NULL;
		}
	}
}

void	ft_extend_pb(t_pushswap *pushswap)
{
	t_stack	*temp;

	temp = pushswap->a;
	pushswap->b = temp;
	pushswap->a = pushswap->a->next;
	pushswap->b->next = NULL;
	pushswap->blast = pushswap->b;
	pushswap->blen += 1;
	if (pushswap->a)
		pushswap->a->prev = NULL;
	else
		pushswap->alast = NULL;
	pushswap->alen -= 1;
}

void	pb(t_pushswap *pushswap)
{
	t_stack	*temp;

	write(1, "pb\n", 3);
	temp = pushswap->a;
	if (temp)
	{
		if (!(pushswap->b))
			ft_extend_pb(pushswap);
		else
		{		
			pushswap->a = pushswap->a->next;
			pushswap->alen -= 1;
			temp->next = pushswap->b;
			pushswap->b->prev = temp;
			pushswap->b = temp;
			pushswap->blen += 1;
			if (pushswap->a)
				pushswap->a->prev = NULL;
			else
				pushswap->alast = NULL;
		}
	}
}
