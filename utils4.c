/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tudor <tudor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:49:45 by tudor             #+#    #+#             */
/*   Updated: 2023/02/01 17:02:12 by tudor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	stack_organizer(t_node **stack1, t_node **stack2)
{
	t_node	*current;
	t_node	*current2;

	current = *stack1;
	current2 = *stack2;
	if (current2 == NULL)
		return ;
	while (current->content < current2->content)
	{
		rb(stack2);
		current2 = current2->next;
	}
}
