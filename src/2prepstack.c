/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2prepstack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmacmaho <bmacmaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 20:55:13 by bmacmaho          #+#    #+#             */
/*   Updated: 2023/02/14 23:13:30 by bmacmaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

static t_stack	*ft_firstnode(char **argv)
{
	t_stack	*head;

	head = new_node(ft_atoi(argv[1]));
	return (head);
}

static void	ft_prepbstack(t_pushswap *pushswap)
{
	pushswap->blast = NULL;
	pushswap->blen = 0;
	pushswap->b = NULL;
}

int	ft_prepstacks(int argc, char **argv, t_pushswap *pushswap)
{
	int		i;
	t_stack	*temp;
	t_stack	*head;

	head = ft_firstnode(argv);
	if (!head)
		return (-1);
	temp = head;
	i = 2;
	while (i < argc)
	{
		temp->next = new_node(ft_atoi(argv[i]));
		if (!temp->next)
			return (ft_free_everything(pushswap));
		temp->next->prev = temp;
		temp = temp->next;
		i++;
	}
	pushswap->alast = temp;
	pushswap->alen = i - 1;
	pushswap->a = head;
	ft_prepbstack(pushswap);
	return (0);
}
