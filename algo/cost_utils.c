/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tudor <tudor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 21:35:24 by tudor             #+#    #+#             */
/*   Updated: 2023/03/12 13:06:57 by tudor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	total_cost(t_node **stack1, t_node *node)
{
	if (ft_lstsize(node) > ft_lstsize(*stack1) / 2)
	{
		node->half = 0;
		return (ft_lstsize(*stack1) - ft_lstsize(node));
	}
	else
	{
		node->half = 1;
		return (ft_lstsize(node));
	}
}

int	best_push(t_node *stack1, t_node *stack2, t_node *node1, t_node *node2)
{
	int	firstcost;
	int	secondcost;

	firstcost = (total_cost(&stack1, node2));
	secondcost = (total_cost(&stack2, node1));
	if (node1->half == 0 && node2->half == 0)
		return (return_bigger(firstcost, secondcost));
	if (node1->half == 1 && node2->half == 1)
		return (return_bigger(firstcost, secondcost));
	else
		return (firstcost + secondcost);
}

t_node	*best_match(t_node *stack1, t_node *stack2)
{
	unsigned long long	index;
	t_node				*current;

	current = stack1;
	index = 10000000000000;
	while (stack1->next != NULL)
	{
		if (return_difference(stack1, stack2) < index
			&& stack1->content > stack2->content)
		{
			index = return_difference(stack1, stack2);
			current = stack1;
		}
		stack1 = stack1->next;
	}
	return (current);
}

t_node	*min_cost(t_node **stack_a, t_node **stack_b)
{
	int		mincost;
	int		totalcost;
	t_node	*bestmatch;
	t_node	*node;
	t_node	*current;

	mincost = INT_MAX;
	node = *stack_b;
	current = *stack_b;
	while (current)
	{
		bestmatch = best_match(*stack_a, current);
		totalcost = best_push(*stack_a, *stack_b, current, bestmatch);
		if (totalcost < mincost)
		{
			mincost = totalcost;
			node = current;
		}
		current = current->next;
	}
	return (node);
}
