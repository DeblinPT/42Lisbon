/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_s_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:57:35 by adimas-d          #+#    #+#             */
/*   Updated: 2023/11/13 17:07:31 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_list **stack)
{
	if (ft_swap(stack))
		write(1, "sa\n", 3);
	else
		return ;
}

void	ft_sb(t_list **stack)
{
	if (ft_swap(stack))
		write(1, "sb\n", 3);
	else
		return ;
}

void	ft_ss(t_list **stack_a, t_list **stack_b)
{
	if (ft_swap(stack_a) && ft_swap(stack_b))
		write(1, "ss\n", 3);
	else
		return ;
}

void	ft_pa(t_list **stack_a, t_list **stack_b)
{
	if (ft_push(stack_b, stack_a))
		write(1, "pa\n", 3);
	else
		return ;
}

void	ft_pb(t_list **stack_a, t_list **stack_b)
{
	if (ft_push(stack_a, stack_b))
		write(1, "pb\n", 3);
	else
		return ;
}
