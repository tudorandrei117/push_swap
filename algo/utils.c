/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tudor <tudor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 22:21:33 by tudor             #+#    #+#             */
/*   Updated: 2023/03/12 13:05:09 by tudor            ###   ########.fr       */
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
	int		pos;
	t_node	*current;

	half = ft_lstsize(*stack1) / 2;
	lowest = find_lowest(stack1);
	pos = 0;
	current = *stack1;
	while (current && current->content != lowest)
	{
		pos++;
		current = current->next;
	}
	if (pos >= half)
	{
		pos = ft_lstsize(*stack1) - pos;
		while (pos-- > 0)
			rra(stack1);
	}
	else
	{
		while (pos-- > 0)
			ra(stack1);
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
