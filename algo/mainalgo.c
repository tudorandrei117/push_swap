/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainalgo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tudor <tudor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:52:50 by tudor             #+#    #+#             */
/*   Updated: 2023/03/14 11:44:09 by tudor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	upper_2(t_node **stack_a, t_node **stack_b)
{
	t_node	*node;
	t_node	*best;
	int		firstcost;
	int		secondcost;

	node = min_cost(stack_a, stack_b);
	best = best_match(*stack_a, node);
	firstcost = total_cost(stack_a, best);
	secondcost = total_cost(stack_b, node);
	while (firstcost > 0 && secondcost > 0)
	{
		rr(stack_a, stack_b);
		firstcost--;
		secondcost--;
	}
	if (firstcost > 0)
		while (firstcost-- > 0)
			ra(stack_a);
	else if (secondcost > 0)
		while (secondcost-- > 0)
			rb(stack_b);
}

static void	lower_2(t_node **stack_a, t_node **stack_b)
{
	t_node	*node;
	t_node	*best;
	int		firstcost;
	int		secondcost;

	node = min_cost(stack_a, stack_b);
	best = best_match(*stack_a, node);
	firstcost = total_cost(stack_a, best);
	secondcost = total_cost(stack_b, node);
	while (firstcost > 0 && secondcost > 0)
	{
		rrr(stack_a, stack_b);
		firstcost--;
		secondcost--;
	}
	if (firstcost > 0)
		while (firstcost-- > 0)
			rra(stack_a);
	else if (secondcost > 0)
		while (secondcost-- > 0)
			rrb(stack_b);
}

static void	upper_1(t_node **stack_a, t_node **stack_b, char stack)
{
	t_node	*node;
	t_node	*best;
	int		firstcost;
	int		secondcost;

	node = min_cost(stack_a, stack_b);
	best = best_match(*stack_a, node);
	firstcost = total_cost(stack_a, best);
	secondcost = total_cost(stack_b, node);
	if (stack == 'a')
	{
		while (firstcost-- > 0)
			ra(stack_a);
	}
	if (stack == 'b')
	{
		while (secondcost-- > 0)
			rb(stack_b);
	}
}

static void	lower_1(t_node **stack_a, t_node **stack_b, char stack)
{
	t_node	*node;
	t_node	*best;
	int		firstcost;
	int		secondcost;

	node = min_cost(stack_a, stack_b);
	best = best_match(*stack_a, node);
	firstcost = total_cost(stack_a, best);
	secondcost = total_cost(stack_b, node);
	if (stack == 'a')
	{
		while (firstcost-- > 0)
			rra(stack_a);
	}
	if (stack == 'b')
	{
		while (secondcost-- > 0)
			rrb(stack_b);
	}
}

void	send_to_a(t_node **stack_a, t_node **stack_b)
{
	t_node	*node;
	t_node	*best;

	node = min_cost(stack_a, stack_b);
	best = best_match(*stack_a, node);
	if (best->half == 0 && node->half == 0)
		upper_2(stack_a, stack_b);
	else if (best->half == 1 && node->half == 1)
		lower_2(stack_a, stack_b);
	else if (best->half == 1 && node->half == 0)
	{
		lower_1(stack_a, stack_b, 'a');
		upper_1(stack_a, stack_b, 'b');
	}
	else if (best->half == 0 && node->half == 1)
	{
		upper_1(stack_a, stack_b, 'a');
		lower_1(stack_a, stack_b, 'b');
	}
	pa(stack_a, stack_b);
}
