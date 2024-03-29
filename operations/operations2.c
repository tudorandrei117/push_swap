/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tudor <tudor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:53:19 by tburlacu          #+#    #+#             */
/*   Updated: 2023/03/13 17:44:03 by tudor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//rotate

void	ra(t_node **stack1)
{
	ft_rotate(stack1);
	write(1, "ra\n", 3);
}

void	rb(t_node **stack2)
{
	ft_rotate(stack2);
	write(1, "rb\n", 3);
}

void	rr(t_node **stack1, t_node **stack2)
{
	ft_rotate(stack1);
	ft_rotate(stack2);
	write(1, "rr\n", 3);
}

//rotate

//push

void	pa(t_node **a, t_node **b)
{
	write(1, "pa\n", 3);
	ft_push(a, b);
}

void	pb(t_node **a, t_node **b)
{
	write(1, "pb\n", 3);
	ft_push(b, a);
}

//push
