/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmacmaho <bmacmaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 22:28:11 by bmacmaho          #+#    #+#             */
/*   Updated: 2023/02/15 20:43:20 by bmacmaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	ft_issorted(t_pushswap *pushswap)
{
	t_stack	*temp;

	if (!pushswap->a->next)
		return (0);
	temp = pushswap->a->next;
	while (temp)
	{
		if (temp->val < temp->prev->val)
			return (-1);
		temp = temp->next;
	}
	return (0);
}

t_stack	*new_node(int content)
{
	t_stack	*new;

	new = NULL;
	new = malloc(sizeof(t_stack));
	if (new == NULL)
		return ((new));
	new->val = content;
	new->next = NULL;
	new->prev = NULL;
	new->diff = 0;
	new->index = 0;
	return (new);
}

int	abs(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

int	ft_free_everything(t_pushswap *pushswap)
{
	t_stack	*temp;

	temp = pushswap->a;
	while (pushswap->a)
	{
		pushswap->a = temp->next;
		free(temp);
		temp = pushswap->a;
	}
	temp = pushswap->b;
	while (pushswap->b)
	{
		pushswap->b = temp->next;
		free(temp);
		temp = pushswap->b;
	}
	return (-1);
}

void	ft_calculate_n(t_pushswap *pushswap)
{
	if (pushswap->alen <= 150)
		pushswap->n = 8;
	else
		pushswap->n = 18;
}
