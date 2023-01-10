/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_reverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburlacu <tburlacu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:06:58 by tburlacu          #+#    #+#             */
/*   Updated: 2023/01/10 12:23:34 by tburlacu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static	void	ft_reverse(t_list **stack)
{
	t_list	*tmp;
	t_list	*final;

	if (!(*stack) || (*stack)->next)
		return ;
	while ((*stack)->next->next)
		*stack = (*stack)->next;
	final->next = tmp;
	(*stack)->next = 0;
	*stack = final;
}

void	rra(t_list **stack1)
{
	ft_reverse(stack1);
	write(1, "rra\n", 4);
}

void	rrb(t_list **stack2)
{
	ft_reverse(stack2);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **stack1, t_list **stack2)
{
	ft_reverse(stack1);
	ft_reverse(stack2);
	write(1, "rrr\n", 4);
}
