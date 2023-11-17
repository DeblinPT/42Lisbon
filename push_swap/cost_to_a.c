/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:59:06 by adimas-d          #+#    #+#             */
/*   Updated: 2023/11/14 20:27:31 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_find_cheapest_to_a(t_list *stack_a, t_list *stack_b, t_moves *moves)
{
	long	lowest_move_cost;
	long	move_cost_a;
	long	move_cost_b;
	long	move_cost;
	t_list	*node;

	lowest_move_cost = INT_MAX;
	node = stack_b;
	while (node)
	{
		move_cost_a = ft_find_place_in_a(stack_a, ft_cont(node));
		move_cost_b = ft_move_to_top(stack_b, node);
		move_cost = (ft_abs(move_cost_a) + ft_abs(move_cost_b));
		if (move_cost < lowest_move_cost)
		{
			lowest_move_cost = move_cost;
			moves->moves_in_a = move_cost_a;
			moves->moves_in_b = move_cost_b;
			moves->content_to_move = ft_cont(node);
		}
		if (node->next == NULL)
			break ;
		else
			node = node->next;
	}
}

long	ft_find_place_in_a(t_list *stack_a, long node_nbr)
{
	long	nbr_of_moves;
	t_list	*temp;
	long	lst_lize;

	nbr_of_moves = 0;
	lst_lize = ft_lstsize(stack_a);
	if (ft_cont(ft_lstlast(stack_a)) < node_nbr && ft_cont(stack_a) > node_nbr)
		nbr_of_moves = 0;
	else if (node_nbr > ft_max(stack_a) || node_nbr < ft_min(stack_a))
		nbr_of_moves = ft_move_to_top(stack_a, ft_min_node(stack_a));
	else if (stack_a->next)
	{
		temp = stack_a->next;
		nbr_of_moves++;
		while (temp && (ft_cont(temp) < node_nbr || ft_cont(stack_a)
				> node_nbr))
		{
			stack_a = stack_a->next;
			temp = temp->next;
			nbr_of_moves++;
		}
		if (lst_lize > 4 && nbr_of_moves > (lst_lize / 2))
			nbr_of_moves = nbr_of_moves - lst_lize;
	}
	return (nbr_of_moves);
}

t_list	*ft_min_node(t_list	*stack)
{
	t_list	*min;

	min = stack;
	while (stack)
	{
		if (ft_cont(stack) < ft_cont(min))
			min = stack;
		stack = stack->next;
	}
	return (min);
}
