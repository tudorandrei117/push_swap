/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tudor <tudor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:39:35 by tburlacu          #+#    #+#             */
/*   Updated: 2023/03/09 17:15:23 by tudor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node *stack_a;
	t_node *stack_b;

	stack_b = NULL;

	if (checker(argc, argv) == 0)
		return (0);
	stack_a = create_stack(argc, argv
	);

main_sorter(argc, &stack_a, &stack_b);

	lstclear(&stack_a);
	lstclear(&stack_b);
}