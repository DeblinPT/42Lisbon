/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 22:55:17 by adimas-d          #+#    #+#             */
/*   Updated: 2023/11/04 18:15:07 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_make_move(t_list **stack_a, t_list **stack_b, t_moves *moves)
{
	while (moves->moves_in_a || moves->moves_in_b)
	{
		if (moves->moves_in_a > 0 && moves->moves_in_b > 0)
		{
			ft_rr(stack_a, stack_b);
			moves->moves_in_a--;
			moves->moves_in_b--;
		}
		else if (moves->moves_in_a < 0 && moves->moves_in_b < 0)
		{
			ft_rrr(stack_a, stack_b);
			moves->moves_in_a++;
			moves->moves_in_b++;
		}
		else
			ft_single_stack_move(stack_a, stack_b, moves);
	}
	if (moves->push_to == 'b')
		ft_pb(stack_a, stack_b);
	else
		ft_pa(stack_a, stack_b);
}

void	ft_single_stack_move(t_list **stack_a, t_list **stack_b, t_moves *moves)
{
	if (moves->moves_in_a > 0)
	{
		ft_ra(stack_a);
		moves->moves_in_a--;
	}
	if (moves->moves_in_b > 0)
	{
		ft_rb(stack_b);
		moves->moves_in_b--;
	}
	if (moves->moves_in_a < 0)
	{
		ft_rra(stack_a);
		moves->moves_in_a++;
	}
	if (moves->moves_in_b < 0)
	{
		ft_rrb(stack_b);
		moves->moves_in_b++;
	}
}
