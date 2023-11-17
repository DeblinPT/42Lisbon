/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 22:04:52 by adimas-d          #+#    #+#             */
/*   Updated: 2023/11/14 19:37:53 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_nothing(void *nothing)
{
	(void)nothing;
}

void	ft_print_error(void)
{
	ft_putstr_fd("Error\n", 1);
	exit (0);
}

int	ft_string_count(char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == c)
		{
			str++;
			continue ;
		}
		count++;
		while (*str != c && *str)
			str++;
	}
	return (count);
}

void	ft_final_ordering(t_list **stack_a)
{
	long	moves;

	moves = ft_move_to_top(*stack_a, ft_min_node(*stack_a));
	if (ft_lstsize(*stack_a) > 4 && moves > (ft_lstsize(*stack_a) / 2))
		moves = moves - ft_lstsize(*stack_a);
	if (moves > 0)
	{
		while ((moves) > 0)
		{
			ft_ra(stack_a);
			moves--;
		}
	}
	else
	{
		while ((moves) < 0)
		{
			ft_rra(stack_a);
			moves++;
		}
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;

	stack_a = NULL;
	if (argc < 2)
		return (0);
	else if (argc == 2)
	{
		if (ft_is_int(ft_string_count(argv[1], ' '), ft_split(argv[1], ' '))
			== 0 && ft_is_size_of_int(*ft_split(argv[1], ' ')) == 0)
			ft_stack_build(ft_string_count(argv[1], ' '),
				ft_split(argv[1], ' '), &stack_a, 0);
		else
			ft_print_error();
	}
	else
	{
		if (ft_is_int(argc, argv) == 0)
			ft_stack_build(argc, argv, &stack_a, 1);
		else
			ft_print_error();
	}
	if (!ft_is_ordered(stack_a))
		ft_sort(&stack_a);
	ft_lstclear(&stack_a, &ft_nothing);
	return (0);
}
