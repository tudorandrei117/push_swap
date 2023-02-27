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
#include <stdbool.h>

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

int	checker_num(int argc, char *argv[])
{
	char	*str;
	int		i;
	int		h;

	i = 1;
	while (i < argc)
	{
		h = 0;
		str = argv[i];
		if (ft_atol(argv[i]) > 2147483647 || ft_atol(argv[i]) < -2147483648
			|| ft_strlen(argv[i]))
		{
			//printf("not int\n");
			return (0);
		}
		while (str[h] != '\0')
		{
			if ((str[h] < 48 || str[h] > 57) && str[h] != 45)
			{
				//printf("not number\n");
				return (0);
			}
			h++;
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
	int		i[30];
	int		o=0;

	if (checker_num(argc, argv) == 0)
		return (0);
	stack_a = push_swap(argc, argv);
	stack_b = NULL;
	stack_a->head = stack_a;
	list2array(&stack_a, i);
	while (i[o])
	{
		printf("array:%i\n",i[o]);
		o++;
	}
	sort_array_ascending(i, 67);
	if (checker_dup(i, argc) == 0)
		return (0);
	while (i[o])
	{
		printf("array2:%i\n",i[o]);
		o++;
	}
	
	//match_finder(&stack_a, &stack_b, i, argc);
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