/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tudor <tudor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:54:27 by tburlacu          #+#    #+#             */
/*   Updated: 2023/01/27 17:54:40 by tudor            ###   ########.fr       */
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
	int	half;
	int	current;

	half = ft_lstsize(*stack1) / 2;
	current = get_position(stack1);
	if (current > half)
	{
		while (current >= 0)
		{
			rra(stack1);
			current--;
		}
	}
	else if (current <= half)
	{
		while (current >= 0)
		{
			ra(stack1);
			current--;
		}
	}
}

int	get_position(t_node **stack1)
{
	int		pos;
	t_node	*start;
	t_node	*current;

	pos = 1;
	current = *stack1;
	start = (*stack1)->head;
	while (current)
	{
		printf("entrei no getpos!\n");
		if (current->content == start->content)
		{
			printf("entrei no pos!!!\n");
			return (pos);
		}
		current = current->next;
		pos++;
	}//e so vafer uma temporaria
	return (-1);
}

void	match_finder(t_node **stack1, t_node **stack2, int *array)
{
	t_node	*current;
	int		i;

	current = *stack1;
	i = 0;
	while (current)
	{
		printf("lst\n");
		while (i < 3)
		{
			printf("valor do current %d\tvalor do array %d\n", current->content, array[i]);
			if (current->content == array[i])
			{
				printf("\nmatchfound!!!!!\n");
				ft_pushtotop(stack1);
				pb(stack1, stack2);
				printstack(stack1, stack2);
				current = (*stack1)->head;
				printf("current = %d\n", (*stack1)->next->content);
				break;
			}
			i++;
		}
		
		printf("oh bebe gosto mais de voce\n");
		i = 0;
		printf("bruh");
		current = current->next;
		
	}
}
