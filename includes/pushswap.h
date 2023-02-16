/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmacmaho <bmacmaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 20:31:01 by bmacmaho          #+#    #+#             */
/*   Updated: 2023/02/15 20:43:08 by bmacmaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "./libft/libft.h"
# include <unistd.h>

# define INTMAX 2147483647

typedef struct s_stack
{
	int				val;
	int				diff;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

typedef struct s_pushswap
{
	struct s_stack	*a;
	struct s_stack	*b;
	struct s_stack	*alast;
	struct s_stack	*blast;
	int				alen;
	int				blen;
	int				n;
	int				curdiff;
	int				down;
}				t_pushswap;

//stack prep
int		ft_prepstacks(int argc, char **argv, t_pushswap *pushswap);

//push swap rotate functions
void	sa(t_pushswap *pushswap);
void	sb(t_pushswap *pushswap);

//shorthand push swap rotate a b
void	pa(t_pushswap *pushswap);
void	pb(t_pushswap *pushswap);
void	ra(t_pushswap *pushswap);
void	rb(t_pushswap *pushswap);
void	rra(t_pushswap *pushswap);
void	rrb(t_pushswap *pushswap);

//sorting
void	ft_presort(t_pushswap *pushswap);
void	ft_send_to_b(t_pushswap *pushswap);
void	ft_bring_back(t_pushswap *pushswap);
void	ft_find_max_diff(t_pushswap *pushswap);
void	ft_find_min_diff(t_pushswap *pushswap);

//utils
int		ft_issorted(t_pushswap *pushswap);
t_stack	*new_node(int content);
int		abs(int num);
int		ft_free_everything(t_pushswap *pushswap);
void	ft_calculate_n(t_pushswap *pushswap);

//errors
int		ft_errors(int argc, char **argv);

#endif
