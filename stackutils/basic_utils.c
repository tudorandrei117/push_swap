/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tudor <tudor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 21:56:08 by tudor             #+#    #+#             */
/*   Updated: 2023/03/05 22:32:13 by tudor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	return_bigger(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

unsigned long long	return_difference(t_node *a, t_node *b)
{
	unsigned long long	resultado;

	if (a->content >= b->content)
		resultado = a->content - b->content;
	else
		resultado = b->content - a->content;
	return (resultado);
}

int	half(t_node **stack, t_node *node)
{
	if (ft_lstsize(node) > ft_lstsize(*stack) / 2)
		return (0);
	else
		return (1);
}
