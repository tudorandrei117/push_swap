/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburlacu <tburlacu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:16:49 by tburlacu          #+#    #+#             */
/*   Updated: 2023/01/10 11:47:55 by tburlacu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static	void	ft_reverse(t_list **stack)
{
	t_list	*tmp;

	if (!*stack)
		return ;
	tmp = *stack;
	tmp->next = 0;
	ft_lstlast(*stack)->next = tmp;
}

void	ra(t_list **stack1)
{
	ft_reverse(stack1);
	write(1, "ra\n", 3);
}

void	rb(t_list **stack2)
{
	ft_reverse(stack2);
	write(1, "rb\n", 3);
}

void	rr(t_list **stack1, t_list **stack2)
{
	ft_reverse(stack1);
	ft_reverse(stack2);
	write(1, "rr\n", 3);
}
