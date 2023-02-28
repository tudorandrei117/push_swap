/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburlacu <tburlacu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:39:35 by tburlacu          #+#    #+#             */
/*   Updated: 2023/01/17 13:34:47 by tburlacu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	*array_dup(int array[],int array_dup[],  int start)
{
	int	i;
	i = 0;
	while (i < 20 || array[start])
	{
		array_dup[i] = array[start];
		start++;
		i++;
	}
	return (array_dup);
}

bool	checker_dup(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
			{
				//printf(" have dup\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	//printf("not dup\n");
	return (1);
}

int checker_num(int argc, char *argv[])
{
    char *str;
    int i;
    int h;

    i = 1;
    while (i < argc)
    {
        h = 0;
        str = argv[i];
        if (!ft_strisdigit(str) || ft_atol(str) > 2147483647 || ft_atol(str) < -2147483648)
        {
            printf("not int\n");
            return (0);
        }
        i++;
    }
    return (1);
}


t_node	*push_swap(int argc, char **argv)
{
	int		i;
	t_node	*node;
	t_node	*start;

	start = NULL;
	i = 1;
	while (i != argc)
	{
		node = ft_addstack(ft_atol(argv[i]), argc);
		if (start == NULL)
		{
			start = node;
		}
		else
		{
			ft_lstadd_back(&start, node);
		}
		i++;
	}
	return (start);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		i[argc - 1];
	int		o=0;
	int		num_chunks;
	int 	chunk_size;
	int		**chunks;
	chunk_size = 20;


	if (checker_num(argc, argv) == 0)
		return (0);
	stack_a = push_swap(argc, argv);
	stack_b = NULL;
	stack_a->head = stack_a;
	list2array(&stack_a, i);
	sort_array_ascending(i, argc - 1);
	chunks = create_chunk_array(i, argc - 1, chunk_size, &num_chunks);


	printf("\n\n");
		for (int o = 0; o < num_chunks; o++)
	{
		printf("Chunk %d: [", o);
		for (int j = 0; j < chunk_size && o * chunk_size + j < argc - 1; j++)
		{
			printf("%d", chunks[o][j]);
			if (j < chunk_size - 1 && o * chunk_size + j < argc - 1)
			{
				printf(", ");
			}
		}
		printf("]\n\n\n");
	}
int l = 0;
    while (l < num_chunks) {
		printstack(&stack_a, &stack_b);
		printf("correeeeeeeeeeeeeeeeeeeeeuuuuuuuuuuuu\n");
        match_finder(&stack_a, &stack_b, chunks[l], chunk_size);
		printstack(&stack_a, &stack_b);
        l++;
    }
 
	/* while (stack_b)
		pa(&stack_a, &stack_b);
	printstack(&stack_a, &stack_b); */
	/*
	
	
		if (argc < 5)
	{
		short_sorter(&stack_a);
	}
	if (argc > 5 && argc < 7)
	{
		sorter5(&stack_a, &stack_b);w
	} 
	printstack(&stack_a, &stack_b);*/
	//return (0);
}