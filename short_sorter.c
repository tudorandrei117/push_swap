/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburlacu <tburlacu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:02:57 by tburlacu          #+#    #+#             */
/*   Updated: 2023/01/17 14:13:13 by tburlacu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static	void	shortop1(t_node **stack)
{
	sa(stack);
	rra(stack);
}

static	void	shortop2(t_node **stack)
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

/**
 * It pushes the lowest number to stack2, then pushes the second lowest number to stack2, then sorts
 * the remaining numbers in stack1, then pushes the two numbers in stack2 back to stack1
 * 
 * @param stack1 the stack that contains the unsorted numbers
 * @param stack2 the stack that will be sorted
 */
void sorter5(t_node **stack1, t_node **stack2)
{
	push_lower(stack1, stack2);
	printstack(stack1, stack2);
	push_lower2(stack1, stack2);
	printstack(stack1, stack2);
	short_sorter(stack1);
	printstack(stack1, stack2);
	pa(stack1, stack2);
	printstack(stack1, stack2);
	pa(stack1, stack2);
	printstack(stack1, stack2);
}