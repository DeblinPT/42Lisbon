/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 22:04:50 by adimas-d          #+#    #+#             */
/*   Updated: 2023/11/14 18:48:14 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

typedef struct t_moves
{
	long	moves_in_a;
	long	moves_in_b;
	long	content_to_move;
	char	push_to;
}			t_moves;

/* MAIN */
void	ft_nothing(void *nothing);
void	ft_print_error(void);
void	ft_final_ordering(t_list **stack_a);
int		push_swap(int argc, char **argv);

/* CHECKS */
int		ft_is_int(int argc, char **argv);
int		ft_is_size_of_int(char *argv);
int		ft_intcmp(t_list *num1, t_list *num2);
void	ft_is_duplicated(t_list *stack);
int		ft_is_ordered(t_list *stack_a);

/* STACK BUILD */
long	ft_atol(const char *str);
void	ft_stack_build(int argc, char **argv, t_list **stack, int i);

/* SORT */
void	ft_sort(t_list **stack_a);
void	ft_sort_of_3(t_list **stack_a);
void	ft_bigger_first(t_list **stack_a);
void	ft_sort_more_then_3(t_list **stack_a);
void	ft_all_back_to_original_stack(t_list **stack_a, t_list **stack_b,
			t_moves *moves_to_make);

/* COST_TO_A */
void	ft_find_cheapest_to_a(t_list *stack_a, t_list *stack_b, t_moves *moves);
long	ft_find_place_in_a(t_list *stack_a, long node_nbr);
t_list	*ft_min_node(t_list	*stack);

/* COST_TO_B */
void	ft_find_cheapest_move(t_list *stack_a, t_list *stack_b, t_moves *moves);
long	ft_move_to_top(t_list *stack, t_list *node);
long	ft_find_place_in_b(t_list *stack_b, long node_nbr);

/* COST UTILS */
long	ft_cont(t_list *stack);
long	ft_min(t_list *stack);
long	ft_max(t_list *stack);
long	ft_abs(long number);
t_list	*ft_max_node(t_list *stack);

/* MAKE MOVES */
void	ft_make_move(t_list **stack_a, t_list **stack_b, t_moves *moves);
void	ft_single_stack_move(t_list **stack_a, t_list **stack_b,
			t_moves *moves);

/* MOVES S P */
void	ft_sa(t_list **stack);
void	ft_sb(t_list **stack);
void	ft_ss(t_list **stack_a, t_list **stack_b);
void	ft_pa(t_list **stack_a, t_list **stack_b);
void	ft_pb(t_list **stack_a, t_list **stack_b);

/* MOVES R */
void	ft_ra(t_list **stack);
void	ft_rb(t_list **stack);
void	ft_rr(t_list **stack_a, t_list **stack_b);

/* MOVES RR */
void	ft_rra(t_list **stack);
void	ft_rrb(t_list **stack);
void	ft_rrr(t_list **stack_a, t_list **stack_b);

/* MOVES IN LIST */
int		ft_swap(t_list **stack);
int		ft_push(t_list **stack_sender, t_list **stack_dest);
int		ft_rotate(t_list **stack);
int		ft_rev_rotate(t_list **stack);
#endif