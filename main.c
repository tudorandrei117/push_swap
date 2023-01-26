/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tudor <tudor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:52:33 by tburlacu          #+#    #+#             */
/*   Updated: 2023/01/26 12:59:42 by tudor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_node *push_swap(int argc, char **argv)
{
    int i;
    t_node *node, *head;
    head = NULL;
    i = 1;
    while (i != argc)
    {
        node = ft_addstack(ft_atol(argv[i]), argc);
        if (head == NULL)
            head = node;
        else
        {
            ft_lstadd_back(&head, node);
        }
        i++;
    }
    head->head = head;
    return head;
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		i[argc - 1];
	int		j[3] = {8, 5, 3};

	stack_a = push_swap(argc, argv);
	stack_b = NULL;
/* 	list2array(&stack_a, i, argc);
	sort_array_ascending(i, argc);
	for (int k = 0; k < argc - 1; k++)
	{
		printf("%d\n", i[k]);
	} */
	
	printstack(&stack_a, &stack_b);
	match_finder(stack_a, stack_b, j, argc - 1);
	//printf("situacao %d\n", stack_a->content);
	//printf("situacao %d\n", stack_b->head);
	printstack(&stack_a, &stack_b);
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
