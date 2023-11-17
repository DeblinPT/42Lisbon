/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:50:44 by adimas-d          #+#    #+#             */
/*   Updated: 2023/11/14 19:43:03 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_int(int argc, char **argv)
{
	static int	i;
	static int	j;

	while (++j < argc)
	{
		if (!argv[j][0])
			return (1);
		else if ((argv[j][i] == '-' || argv[j][i] == '+')
			&& ft_isdigit(argv[j][i + 1] == 0))
			return (1);
		else
		{
			if (argv[j][i] == '-' || argv[j][i] == '+')
				i++;
			while (argv[j][i])
			{
				if (ft_isdigit(argv[j][i]) == 0)
					return (1);
				i++;
			}
		}
		i = 0;
	}
	return (0);
}

int	ft_is_size_of_int(char *argv)
{
	if (!argv)
		ft_print_error();
	if ((ft_atol(argv) < INT_MIN) || (ft_atol(argv) > INT_MAX))
		return (1);
	return (0);
}

int	ft_intcmp(t_list *num1, t_list *num2)
{
	if (num1 == num2)
		return (1);
	else
		return (0);
}

void	ft_is_duplicated(t_list *stack)
{
	t_list	*stack_copy1;
	t_list	*stack_copy2;

	stack_copy1 = stack;
	stack_copy2 = stack->next;
	while (stack_copy1 && stack_copy2)
	{
		if (ft_intcmp(stack_copy1->content, stack_copy2->content) == 1)
			ft_print_error();
		else if (!(stack_copy2->next))
		{
			stack_copy2 = stack_copy1->next->next;
			stack_copy1 = stack_copy1->next;
		}
		else
			stack_copy2 = stack_copy2->next;
	}
}

int	ft_is_ordered(t_list *stack_a)
{
	while (stack_a->next != NULL
		&& ft_cont(stack_a) < ft_cont(stack_a->next))
		stack_a = stack_a->next;
	return (stack_a->next == NULL);
}
