/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:58:08 by adimas-d          #+#    #+#             */
/*   Updated: 2023/11/04 19:29:43 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_list **stack)
{
	if (ft_rotate(stack))
		write(1, "ra\n", 3);
	else
		return ;
}

void	ft_rb(t_list **stack)
{
	if (ft_rotate(stack))
		write(1, "rb\n", 3);
	else
		return ;
}

void	ft_rr(t_list **stack_a, t_list **stack_b)
{
	if (ft_rotate(stack_a) && ft_rotate(stack_b))
		write(1, "rr\n", 3);
	else
		return ;
}
