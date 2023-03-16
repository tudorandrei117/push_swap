/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tudor <tudor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 22:21:33 by tudor             #+#    #+#             */
/*   Updated: 2023/03/13 15:37:40 by tudor            ###   ########.fr       */
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
	int		i;
	t_node	*temp;

	i = find_lowest(stack1);
	temp = *stack1;
	while (temp)
	{
		if (temp->content == i)
			break ;
		temp = temp->next;
	}
	if (half(stack1, temp) == 0)
	{
		while ((*stack1)->content != i)
			ra(stack1);
	}
	else if (half(stack1, temp) == 1)
	{
		while ((*stack1)->content != i)
			rra(stack1);
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
