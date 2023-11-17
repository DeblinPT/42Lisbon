/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_build.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:52:22 by adimas-d          #+#    #+#             */
/*   Updated: 2023/11/14 19:43:29 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	num;

	num = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	num *= sign;
	if (num < INT_MIN || num > INT_MAX)
		ft_print_error();
	return (num);
}

void	ft_stack_build(int argc, char **argv, t_list **stack, int i)
{
	t_list	*node;

	if (!argv[i])
		ft_print_error();
	while (i < argc)
	{
		node = ft_lstnew((void *)ft_atol(argv[i]));
		if (!node)
			ft_print_error();
		else if (*stack == NULL)
			*stack = node;
		else
			ft_lstadd_back(stack, node);
		i++;
	}
	ft_is_duplicated(*stack);
}
