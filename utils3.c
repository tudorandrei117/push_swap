/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tudor <tudor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:54:27 by tburlacu          #+#    #+#             */
/*   Updated: 2023/02/01 16:59:38 by tudor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	ft_push_to_top_first(t_node **stack1)
{
	ra(stack1);
}

static void	ft_push_to_top_before_half(t_node **stack1, int cont)
{
	int	half;

	half = ft_lstsize(*stack1) / 2;
	while (cont >= 1)
	{
		cont--;
		ra(stack1);
	}
}

static void	ft_push_to_top_after_half(t_node **stack1, int cont)
{
	int	half;

	half = ft_lstsize(*stack1) / 2;
	while (cont < half && cont != ft_lstsize(*stack1))
	{
		cont++;
		rra(stack1);
	}
}

void	ft_pushtotop(t_node **stack1, t_node **stack2, int cont)
{
	int	half;

	printf("valor da posicao %d\n", cont);
	half = ft_lstsize(*stack1) / 2;
	if (cont == 1)
		ft_push_to_top_first(stack1);
	else if (cont < half)
		ft_push_to_top_before_half(stack1, cont);
	else if (cont >= half)
		ft_push_to_top_after_half(stack1, cont);
	stack_organizer(stack1, stack2);
	pb(stack1, stack2);
}

void	match_finder(t_node **stack1, t_node **stack2, int *array, int size)
{
	t_node	*current;
	int		i;
	int		pos;

	pos = 1;
	current = *stack1;
	while (current)
	{
		i = 0;
		while (i < size)
		{
			if (current->content == array[i])
			{
				ft_pushtotop(stack1, stack2, pos);
				current = *stack1;
				pos = 0;
				i = -1;
				printstack(stack1, stack2);
			}
			i++;
		}
		if (i >= 0)
			current = current->next;
		pos++;
	}
}
