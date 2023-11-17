/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_in_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:58:57 by adimas-d          #+#    #+#             */
/*   Updated: 2023/11/07 04:19:02 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_swap(t_list **stack)
{
	t_list	*temp;

	temp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	temp->next = (*stack);
	(*stack) = temp;
	return (1);
}

int	ft_push(t_list **stack_sender, t_list **stack_dest)
{
	t_list	*temp;

	temp = (*stack_sender)->next;
	(*stack_sender)->next = (*stack_dest);
	(*stack_dest) = (*stack_sender);
	(*stack_sender) = temp;
	return (1);
}

int	ft_rotate(t_list **stack)
{
	t_list	*temp;

	temp = (*stack)->next;
	(ft_lstlast(*stack))->next = (*stack);
	(*stack)->next = NULL;
	(*stack) = temp;
	return (1);
}

int	ft_rev_rotate(t_list **stack)
{
	t_list	*second_to_last;
	t_list	*last;

	last = (ft_lstlast(*stack));
	second_to_last = (*stack);
	while (second_to_last->next != last)
		second_to_last = second_to_last->next;
	second_to_last->next = NULL;
	last->next = (*stack);
	(*stack) = last;
	return (1);
}
