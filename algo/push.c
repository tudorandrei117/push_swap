/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tudor <tudor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 12:58:32 by tudor             #+#    #+#             */
/*   Updated: 2023/03/13 17:42:13 by tudor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	big_sorter(t_node **stack_a, t_node **stack_b)
{
	push_to_b(stack_a, stack_b);
	while (ft_lstsize(*stack_b) > 0)
		send_to_a(stack_a, stack_b);
	ft_push_top(stack_a);
}

void	main_sorter(int ac, t_node **stack_a, t_node **stack_b)
{
	if (ac == 3 && analise(stack_a) == 0)
		sa(stack_a);
	else if (ac == 4 && analise(stack_a) == 0)
		short_sorter(stack_a);
	else if (ac == 5 || ac == 6)
		sorter5(stack_a, stack_b);
	else if (ac > 6 && analise(stack_a) == 0)
		big_sorter(stack_a, stack_b);
}

int	analise(t_node **stack)
{
	t_node	*temp;

	temp = *stack;
	while (temp->next)
	{
		if (temp->content < temp->next->content)
			temp = temp->next;
		else
			return (0);
	}
	return (1);
}

void	push_to_b(t_node **stack1, t_node **stack2)
{
	while (ft_lstsize(*stack1) > 3)
	{
		if ((*stack1)->content < find_mid(stack1))
			pb(stack1, stack2);
		else
			ra(stack1);
	}
	if (analise(stack1) == 0)
		short_sorter(stack1);
}
