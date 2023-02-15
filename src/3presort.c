/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3presort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmacmaho <bmacmaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 20:38:07 by bmacmaho          #+#    #+#             */
/*   Updated: 2023/02/15 20:42:40 by bmacmaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

static int	ft_closest_diff(t_pushswap *pushswap)
{
	t_stack	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	temp = pushswap->a;
	while (temp)
	{
		if (abs(temp->diff) == 4)
			temp = NULL;
		i++;
		if (temp)
			temp = temp->next;
	}
	temp = pushswap->alast;
	while (temp)
	{
		if (abs(temp->diff) == 4)
			temp = NULL;
		j++;
		if (temp)
			temp = temp->prev;
	}
	return (j - i);
}

static void	ft_sort_three(t_pushswap *pushswap)
{
	if (pushswap->alen == 2)
	{
		if (pushswap->a->val > pushswap->alast->val)
			sa(pushswap);
	}
	else
	{
		while (ft_issorted(pushswap) == -1)
		{
			if (pushswap->a->val > pushswap->a->next->val && \
			pushswap->alast->val > pushswap->alast->prev->val && \
			pushswap->a->val > pushswap->alast->val)
				ra(pushswap);
			else if (pushswap->a->val > pushswap->a->next->val)
				sa(pushswap);
			else if (pushswap->alast->val < pushswap->a->val)
				rra(pushswap);
			else if (pushswap->alast->val < pushswap->alast->prev->val)
			{
				ra(pushswap);
				sa(pushswap);
				rra(pushswap);
			}
		}
	}
}

static void	ft_sort_five(t_pushswap *pushswap)
{
	while (pushswap->alen > 3)
	{
		if (abs(pushswap->a->diff) == 4)
			pb(pushswap);
		else if (ft_closest_diff(pushswap) >= 0)
			ra(pushswap);
		else
			rra(pushswap);
	}
	ft_sort_three(pushswap);
	while (pushswap->b)
	{
		if (pushswap->b->val > pushswap->a->val)
		{
			pa(pushswap);
			ra(pushswap);
		}
		else
			pa(pushswap);
	}
}

static void	ft_find_diffs(t_pushswap *pushswap)
{
	t_stack	*temp;
	t_stack	*temp2;

	temp = pushswap->a;
	while (temp)
	{
		temp2 = pushswap->a;
		while (temp2)
		{
			if (temp->val > temp2->val)
				temp->diff += 1;
			else if (temp->val < temp2->val)
				temp->diff -= 1;
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
}

void	ft_presort(t_pushswap *pushswap)
{
	ft_find_diffs(pushswap);
	if (pushswap->alen <= 3)
		ft_sort_three(pushswap);
	else if (pushswap->alen == 5)
		ft_sort_five(pushswap);
	else
	{
		ft_calculate_n(pushswap);
		pushswap->curdiff = pushswap->n * 2;
		ft_send_to_b(pushswap);
		ft_bring_back(pushswap);
	}
}
