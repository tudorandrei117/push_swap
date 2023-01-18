/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operantions3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburlacu <tburlacu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:59:08 by tburlacu          #+#    #+#             */
/*   Updated: 2023/01/13 16:45:04 by tburlacu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
//swap

void	sa(t_node **stack1)
{
	ft_swap(stack1);
	write(1, "sa\n", 3);
}

void	sb(t_node **stack2)
{
	ft_swap(stack2);
	write(1, "sb\n", 3);
}

void	ss(t_node **stack1, t_node **stack2)
{
	ft_swap(stack1);
	ft_swap(stack2);
	write(1, "ss\n", 3);
}

//swap

//reverse

void	rra(t_node **stack1)
{
	ft_reverse(stack1);
	write(1, "rra\n", 4);
}

void	rrb(t_node **stack2)
{
	ft_reverse(stack2);
	write(1, "rrb\n", 4);
}
