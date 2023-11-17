/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 21:07:43 by adimas-d          #+#    #+#             */
/*   Updated: 2023/11/13 18:40:33 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_cont(t_list *stack)
{
	return ((long)(stack->content));
}

long	ft_min(t_list *stack)
{
	long	min;
	t_list	*copy;

	copy = stack;
	min = LONG_MAX;
	while (copy)
	{
		if (min > ft_cont(copy))
			min = ft_cont(copy);
		copy = copy->next;
	}
	return (min);
}

long	ft_max(t_list *stack)
{
	return (ft_cont(ft_max_node(stack)));
}

long	ft_abs(long number)
{
	if (number < 0)
		number *= -1;
	return (number);
}

t_list	*ft_max_node(t_list *stack)
{
	t_list	*max;

	max = stack;
	while (stack)
	{
		if (ft_cont(stack) > ft_cont(max))
			max = stack;
		stack = stack->next;
	}
	return (max);
}
