/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainalgo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tudor <tudor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:52:50 by tudor             #+#    #+#             */
/*   Updated: 2023/03/10 14:18:32 by tudor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	all_upper_half(t_node **stack_a, t_node **stack_b)
{
	t_node	*elem;
	t_node	*best;
	int		cost_a;
	int		cost_b;

	elem = min_cost(stack_a, stack_b);
	best = best_match(*stack_a, elem);
	cost_a = total_cost(stack_a, best);
	cost_b = total_cost(stack_b, elem);
	while (cost_a > 0 && cost_b > 0)
	{
		rr(stack_a, stack_b);
		cost_a--;
		cost_b--;
	}
	if (cost_a > 0)
		while (cost_a-- > 0)
			ra(stack_a);
	else if (cost_b > 0)
		while (cost_b-- > 0)
			rb(stack_b);
}

static void	all_lower_half(t_node **stack_a, t_node **stack_b)
{
	t_node	*elem;
	t_node	*best;
	int		cost_a;
	int		cost_b;

	elem = min_cost(stack_a, stack_b);
	best = best_match(*stack_a, elem);
	cost_a = total_cost(stack_a, best);
	cost_b = total_cost(stack_b, elem);
	while (cost_a > 0 && cost_b > 0)
	{
		rrr(stack_a, stack_b);
		cost_a--;
		cost_b--;
	}
	if (cost_a > 0)
		while (cost_a-- > 0)
			rra(stack_a);
	else if (cost_b > 0)
		while (cost_b-- > 0)
			rrb(stack_b);
}

static void	upper_half(t_node **stack_a, t_node **stack_b, char stack)
{
	t_node	*elem;
	t_node	*best;
	int		cost_a;
	int		cost_b;

	elem = min_cost(stack_a, stack_b);
	best = best_match(*stack_a, elem);
	cost_a = total_cost(stack_a, best);
	cost_b = total_cost(stack_b, elem);
	if (stack == 'a')
	{
		while (cost_a-- > 0)
			ra(stack_a);
	}
	if (stack == 'b')
	{
		while (cost_b-- > 0)
			rb(stack_b);
	}
}

static void	lower_half(t_node **stack_a, t_node **stack_b, char stack)
{
	t_node	*elem;
	t_node	*best;
	int		cost_a;
	int		cost_b;

	elem = min_cost(stack_a, stack_b);
	best = best_match(*stack_a, elem);
	cost_a = total_cost(stack_a, best);
	cost_b = total_cost(stack_b, elem);
	if (stack == 'a')
	{
		while (cost_a-- > 0)
			rra(stack_a);
	}
	if (stack == 'b')
	{
		while (cost_b-- > 0)
			rrb(stack_b);
	}
}

void	send_to_a(t_node **stack_a, t_node **stack_b)
{
	t_node	*elem;
	t_node	*best;

	elem = min_cost(stack_a, stack_b);
	best = best_match(*stack_a, elem);
	if (best->half == 0 && elem->half == 0)
		all_upper_half(stack_a, stack_b);
	else if (best->half == 1 && elem->half == 1)
		all_lower_half(stack_a, stack_b);
	else if (best->half == 1 && elem->half == 0)
	{
		lower_half(stack_a, stack_b, 'a');
		upper_half(stack_a, stack_b, 'b');
	}
	else if (best->half == 0 && elem->half == 1)
	{
		upper_half(stack_a, stack_b, 'a');
		lower_half(stack_a, stack_b, 'b');
	}
	pa(stack_a, stack_b);
}
