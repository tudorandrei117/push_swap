/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburlacu <tburlacu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:58:33 by tburlacu          #+#    #+#             */
/*   Updated: 2023/01/10 16:54:39 by tburlacu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	ft_swap(t_list **stack)
{
	t_list	*tmp;

	if (!(*stack) || !((*stack)->next))
		return ;
		tmp->content = (*stack)->content;
		(*stack)->content = (*stack)->next->content;
		(*stack)->next->content = tmp->content;
}

void	sa(t_list **stack1)
{
	ft_swap(stack1);
	write(1, "sa\n", 3);
}

void	sb(t_list **stack2)
{
	ft_swap(stack2);
	write(1, "sb\n", 3);
}

void	ss(t_list **stack1, t_list **stack2)
{
	ft_swap(stack1);
	ft_swap(stack2);
	write(1, "ss\n", 3);
}
