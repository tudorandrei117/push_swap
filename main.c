/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburlacu <tburlacu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:52:33 by tburlacu          #+#    #+#             */
/*   Updated: 2023/01/18 16:23:02 by tburlacu         ###   ########.fr       */
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
	int i[argc - 1];

	
	stack_a = push_swap(argc, argv);
	stack_b = NULL;

	list2array(&stack_a, i, argc);
	sort_array_ascending(i, argc); 
	for(int k = 0; k < argc - 1 ; k++)
	{
		printf("%d\n", i[k]);
	}
/* 	if (argc < 5)
	{
		short_sorter(&stack_a);
	}
	if (argc > 5 && argc < 7)
	{
		sorter5(&stack_a, &stack_b);
	}
	printstack(&stack_a, &stack_b); */
	return (0);
}

