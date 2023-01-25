/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tudor <tudor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:54:27 by tburlacu          #+#    #+#             */
/*   Updated: 2023/01/25 17:33:35 by tudor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	sizeofarray(int *array)
{
	int	count;

	count = 0;
	while (*array++)
		count++;
	return (count);
}

void	list2array(t_node **stack1, int *array, int size)
{
	t_node	*current;
	int		i;

	current = *stack1;
	i = 0;
	while (current != NULL)
	{
		array[i] = current->content;
		current = current->next;
		i++;
	}
	size = i;
}

void	sort_array_ascending(int *array, int size)
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	ft_pushtotop(t_node **stack1)
{
	t_node *current = *stack1;
	int	pos;
	int	size;
	int	half;

	pos = get_position(&current);
	size = ft_lstsize(current);
	half = size / 2;
	printf("pos%d", pos);
	if (pos > half)
	{
		while (pos > 0)
		{
			rra(&current);
			pos--;
		}
	}
	else if (pos <= half)
	{
		while (pos > 0)
		{
			ra(&current);
			pos--;
		}
	}
}

int	get_position(t_node **stack1)
{
	t_node	*current;
	int		pos;

	current = (*stack1)->head;
	pos = 1;
	// Iterate through the stack to find the position of the current node
	while (current)
	{
		if (current->content == (*stack1)->content)
		{
			return (pos);
		}
		current = current->next;
		pos++;
	}
	
	return (pos);
}

void	match_finder(t_node *stack1, t_node *stack2, int arr[], int size)
{
	t_node	*current;
	int		i;
	int j = 0;

	current = stack1;
	i = 0;
	while (current)
	{
		while (i < size && j < 3)
		{
			printf("i: %d, pos do array: %d\n", i, arr[j]);
			printf("valor da stack : %d\n", current->content);
			if (current->content == arr[j])
			{
				printf("Match found\n");
				ft_pushtotop(&stack1);
				printstack(&stack1, &stack2);
				pb(&stack1, &stack2);
			}
			current = current->next;
			i++;
		}
		i = 0;
		j++;
	}
	printstack(&stack1, &stack2);
}
