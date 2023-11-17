/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:29:53 by adimas-d          #+#    #+#             */
/*   Updated: 2023/11/13 19:51:16 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_list **stack_a)
{
	if (ft_lstsize(*stack_a) == 2)
		ft_sa(stack_a);
	else if (ft_lstsize(*stack_a) == 3)
		ft_sort_of_3(stack_a);
	else
		ft_sort_more_then_3(stack_a);
}

void	ft_sort_of_3(t_list **stack_a)
{
	if (ft_cont(*stack_a) > ft_cont((*stack_a)->next)
		&& ft_cont(*stack_a) > ft_cont((*stack_a)->next->next))
		ft_bigger_first(stack_a);
	else if ((ft_cont(*stack_a) < ft_cont((*stack_a)->next)
			&& ft_cont(*stack_a) > ft_cont((*stack_a)->next->next)))
		ft_rra(stack_a);
	else if ((ft_cont(*stack_a) > ft_cont((*stack_a)->next)
			&& ft_cont(*stack_a) < ft_cont((*stack_a)->next->next)))
		ft_sa(stack_a);
	else
	{
		ft_rra(stack_a);
		ft_sa(stack_a);
	}
}

void	ft_bigger_first(t_list **stack_a)
{
	if (ft_cont((*stack_a)->next) < ft_cont((*stack_a)->next->next))
		ft_ra(stack_a);
	else
	{
		ft_ra(stack_a);
		ft_sa(stack_a);
	}
}

void	ft_sort_more_then_3(t_list **stack_a)
{
	t_list	*stack_b;
	t_moves	moves_to_make;

	stack_b = NULL;
	ft_pb(stack_a, &stack_b);
	ft_pb(stack_a, &stack_b);
	while (ft_lstsize(*stack_a) > 3 && !ft_is_ordered(*stack_a))
	{
		ft_memset(&moves_to_make, 0, sizeof(moves_to_make));
		ft_find_cheapest_move(*stack_a, stack_b, &moves_to_make);
		moves_to_make.push_to = 'b';
		ft_make_move(stack_a, &stack_b, &moves_to_make);
	}
	if (!ft_is_ordered(*stack_a))
	{
		if (ft_lstsize(*stack_a) == 2)
			ft_sa(stack_a);
		else
			ft_sort_of_3(stack_a);
	}
	ft_all_back_to_original_stack(stack_a, &stack_b, &moves_to_make);
	if (!ft_is_ordered(*stack_a))
		ft_final_ordering(stack_a);
}

void	ft_all_back_to_original_stack(t_list **stack_a, t_list **stack_b,
	t_moves *moves_to_make)
{
	while (*stack_b != NULL)
	{
		ft_memset(moves_to_make, 0, sizeof(*moves_to_make));
		ft_find_cheapest_to_a(*stack_a, *stack_b, moves_to_make);
		moves_to_make->push_to = 'a';
		ft_make_move(stack_a, stack_b, moves_to_make);
	}
}
