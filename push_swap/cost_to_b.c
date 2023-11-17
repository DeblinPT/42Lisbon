/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 22:17:17 by adimas-d          #+#    #+#             */
/*   Updated: 2023/11/13 20:53:35 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_find_cheapest_move(t_list *stack_a, t_list *stack_b, t_moves *moves)
{
	long	lowest_move_cost;
	long	move_cost_a;
	long	move_cost_b;
	long	move_cost;
	t_list	*node;

	lowest_move_cost = INT_MAX;
	node = stack_a;
	while (node)
	{
		move_cost_b = ft_find_place_in_b(stack_b, ft_cont(node));
		move_cost_a = ft_move_to_top(stack_a, node);
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

long	ft_move_to_top(t_list *stack, t_list *node)
{
	long	move_up;
	long	move_down;

	move_up = 0;
	move_down = 0;
	while (node != stack)
	{
		stack = stack->next;
		move_up++;
	}
	while (node)
	{
		node = node->next;
		move_down++;
	}
	if (move_up < move_down)
		return (move_up);
	else
		return (-move_down);
}

long	ft_find_place_in_b(t_list *stack_b, long node_nbr)
{
	long	moves_count;
	long	lst_size;
	t_list	*temp;

	lst_size = ft_lstsize(stack_b);
	moves_count = 0;
	if (node_nbr > ft_cont(stack_b) && node_nbr < ft_cont(ft_lstlast(stack_b)))
		moves_count = 0;
	else if (node_nbr < ft_min(stack_b) || node_nbr > ft_max(stack_b))
		moves_count = ft_move_to_top(stack_b, ft_max_node(stack_b));
	else
	{
		temp = stack_b->next;
		moves_count++;
		while (stack_b->next && !(ft_cont(temp) < node_nbr
				&& ft_cont(stack_b) > node_nbr))
		{
			stack_b = stack_b->next;
			temp = temp->next;
			moves_count++;
		}
		if (lst_size > 4 && node_nbr > (lst_size / 2))
			node_nbr = node_nbr - lst_size;
	}
	return (moves_count);
}
