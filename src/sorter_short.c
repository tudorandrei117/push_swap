/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_short.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburlacu <tburlacu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:56:08 by tburlacu          #+#    #+#             */
/*   Updated: 2023/01/10 17:17:10 by tburlacu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sorter_3(t_list **stack1)
{
	int	primeiro;
	int	segundo;
	int	terceiro;

	primeiro = (*stack1)->content;
	segundo = (*stack1)->next->content;
	terceiro = (*stack1)->next->next->content;
	if (primeiro > segundo && segundo > terceiro)
	{
		sa(stack1);
		rra(stack1);
	}
	else if (segundo > terceiro)
	{
		sa(stack1);
		ra(stack1);
	}
	else if (primeiro > segundo)
		sa(stack1);
	else if (primeiro < segundo && segundo > terceiro)
		rra(stack1);
	else if (primeiro > segundo && segundo < terceiro)
		sa(stack1);
}

int main()
{
	t_list *stack2;
	int	primeiro = 3;
	int	segundo = 1;
	int	terceiro = 2;
	int len = 3;

	stack2 = malloc(sizeof(t_list) * len);

	(*stack2).content = primeiro;
	(*stack2).next->content = segundo;
	(*stack2).next->next->content = terceiro;
	
	sorter_3(stack2);

	printf("1: %d\n2: %d\n3: %d\n",primeiro, segundo, terceiro);
}