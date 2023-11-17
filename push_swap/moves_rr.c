/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:15:37 by adimas-d          #+#    #+#             */
/*   Updated: 2023/11/13 17:31:39 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_list **stack)
{
	if (ft_rev_rotate(stack))
		write(1, "rra\n", 4);
	else
		return ;
}

void	ft_rrb(t_list **stack)
{
	if (ft_rev_rotate(stack))
		write(1, "rrb\n", 4);
	else
		return ;
}

void	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	if (ft_rev_rotate(stack_a) && ft_rev_rotate(stack_b))
		write(1, "rrr\n", 4);
	else
		return ;
}
