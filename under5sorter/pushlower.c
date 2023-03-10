/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushlower.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tudor <tudor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:31:20 by tburlacu          #+#    #+#             */
/*   Updated: 2023/03/08 14:22:36 by tudor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_lowest(t_node **stack)
{
	int		i;
	int		j;
	int		nb;
	t_node	*temp;

	i = find_lowest_index(stack);
	j = 0;
	nb = 0;
	temp = *stack;
	while (temp->next && j < i)
	{
		temp = temp->next;
		j++;
	}
	nb = temp->content;
	return (nb);
}

static void	shortop3(t_node **stack1, t_node **stack2)
{
	ra(stack1);
	sa(stack1);
	pb(stack1, stack2);
}

static void	shortop4(t_node **stack1, t_node **stack2)
{
	rra(stack1);
	rra(stack1);
	pb(stack1, stack2);
}

void	push_lower(t_node **stack1, t_node **stack2)
{
	int		lowest;
	t_node	*current;

	current = *stack1;
	lowest = find_lowestforshort(current);
	if (current->content == lowest)
	{
		pb(stack1, stack2);
	}
	else if (current->next->content == lowest)
	{
		sa(stack1);
		pb(stack1, stack2);
	}
	else if (current->next->next->content == lowest)
		shortop3(stack1, stack2);
	else if (current->next->next->next->content == lowest)
	{
		shortop4(stack1, stack2);
	}
	else if (current->next->next->next->next->content == lowest)
	{
		rra(stack1);
		pb(stack1, stack2);
	}
}

void	push_lower2(t_node **stack1, t_node **stack2)
{
	int		lowest;
	t_node	*current;

	current = *stack1;
	lowest = find_lowestforshort(current);
	if (current->content == lowest)
	{
		pb(stack1, stack2);
	}
	else if (current->next->content == lowest)
	{
		sa(stack1);
		pb(stack1, stack2);
	}
	else if (current->next->next->content == lowest)
		shortop3(stack1, stack2);
	else if (current->next->next->next->content == lowest)
	{
		rra(stack1);
		pb(stack1, stack2);
	}
}
