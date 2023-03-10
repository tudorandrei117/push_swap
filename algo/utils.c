/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tudor <tudor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 22:21:33 by tudor             #+#    #+#             */
/*   Updated: 2023/03/08 14:24:19 by tudor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_lowest2(int value, t_node **stack)
{
	long	nb;
	t_node	*current;

	current = *stack;
	nb = INT_MAX;
	while ((*stack))
	{
		if (nb > (*stack)->content && (*stack)->content > value)
			nb = (*stack)->content;
		*stack = (*stack)->next;
	}
	*stack = current;
	return (nb);
}

int	find_mid(t_node **stack)
{
	int	i;
	int	mid;
	int	valor;

	mid = ft_lstsize(*stack) / 2;
	i = 0;
	valor = find_lowest(stack);
	while (i < mid)
	{
		valor = find_lowest2(valor, stack);
		i++;
	}
	return (valor);
}

void	ft_push_top(t_node **stack1)
{
	int		half;
	int		lowest;
	t_node	*current;
	int		pos;

	current = *stack1;
	lowest = find_lowest(stack1);
	half = ft_lstsize(*stack1) / 2;
	while (current)
	{
		if (current->content == lowest)
			break ;
		current = current->next;
	}
	if (pos < half)
	{
		while (pos > 0)
		{
			pos--;
			ra(stack1);
		}
	}
	else
	{
		while (pos < ft_lstsize(*stack1) - 1)
		{
			pos++;
			rra(stack1);
		}
	}
}

int	find_lowest_index(t_node **stack)
{
	int		nb;
	int		i;
	t_node	*temp;

	i = 0;
	temp = *stack;
	nb = (*stack)->content;
	while ((*stack)->next)
	{
		if (nb > (*stack)->next->content)
			nb = (*stack)->next->content;
		*stack = (*stack)->next;
	}
	*stack = temp;
	while ((*stack) && nb != (*stack)->content)
	{
		i++;
		*stack = (*stack)->next;
	}
	*stack = temp;
	return (i);
}

