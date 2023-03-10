/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tudor <tudor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:02:57 by tburlacu          #+#    #+#             */
/*   Updated: 2023/03/08 14:21:59 by tudor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_lowestforshort(t_node *stack)
{
	int		lowest;
	t_node	*current;

	current = stack;
	lowest = INT_MAX;
	while (current != NULL)
	{
		if (current->content < lowest)
		{
			lowest = current->content;
		}
		current = current->next;
	}
	return (lowest);
}

static void	shortop1(t_node **stack)
{
	sa(stack);
	rra(stack);
}

static void	shortop2(t_node **stack)
{
	sa(stack);
	ra(stack);
}

void	short_sorter(t_node **stack)
{
	int	primeiro;
	int	segundo;
	int	terceiro;

	primeiro = (*stack)->content;
	segundo = (*stack)->next->content;
	terceiro = (*stack)->next->next->content;
	if (primeiro > segundo && segundo > terceiro)
	{
		shortop1(stack);
	}
	else if (primeiro < terceiro && segundo > terceiro && primeiro < segundo)
	{
		shortop2(stack);
	}
	else if (primeiro > segundo && primeiro > terceiro)
	{
		ra(stack);
	}
	else if (primeiro < segundo && segundo > terceiro)
	{
		rra(stack);
	}
	else if (primeiro > segundo && segundo < terceiro)
		sa(stack);
}

void	sorter5(t_node **stack1, t_node **stack2)
{
	push_lower(stack1, stack2);
	push_lower2(stack1, stack2);
	short_sorter(stack1);
	pa(stack1, stack2);
	pa(stack1, stack2);
}
