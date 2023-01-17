/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburlacu <tburlacu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:52:33 by tburlacu          #+#    #+#             */
/*   Updated: 2023/01/17 15:47:32 by tburlacu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_node	*push_swap(int argc, char **argv)
{
	int		i;
	t_node	*node;
	t_node	**inicio;

	inicio = malloc(sizeof(t_node *));
	i = 1;
	while (i != argc && argv)
	{
		node = ft_addstack(ft_atol(argv[i]), argc);
		if (*inicio == NULL)
			*inicio = node;
		else if (*inicio != NULL)
		{
			ft_lstadd_back(inicio, node);
			node = node->next;
		}
		i++;
	}
	return (*inicio);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	
	stack_a = push_swap(argc, argv);
	stack_b = NULL;
	if (argc < 5)
	{
		short_sorter(&stack_a);
	}
	if (argc > 5 && argc < 7)
	{
		sorter5(&stack_a, &stack_b);
	}
	printstack(&stack_a, &stack_b);
	return (0);
}

