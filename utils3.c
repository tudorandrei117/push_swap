/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tudor <tudor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:54:27 by tburlacu          #+#    #+#             */
/*   Updated: 2023/01/30 17:47:41 by tudor            ###   ########.fr       */
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

void	ft_pushtotop(t_node **stack1, int cont)
{
	int	half;
	int	current;

	half = ft_lstsize(*stack1) / 2;
	printf("tamanho da stack %d\n", ft_lstsize(*stack1));
	printf("tamanho do half %d\n", half);
	current = cont;
	printf("valor da pos %d\n", current);
	if (current == 1)
	{
		return ;
	}
	if (current < half)
	{
		while (current >= 1)
		{
			current--;
			ra(stack1);
		}
	}
	else if (current >= half)
	{
		while (current > half && current <= ft_lstsize(*stack1))
		{
			current++;
			rra(stack1);
		}
	}
}

void	match_finder(t_node **stack1, t_node **stack2, int *array, int size)
{
	t_node	*current;
	int		i;
	int		pos;
	int 	lever;
	
	pos = 1;
	current = *stack1;
	i = 0;
	while (current)
	{
		lever = 0;
		while (i < size)
		{
			printf("valor do current %d\tvalor do array %d\n", current->content,
					array[i]);
			if (current->content == array[i])
			{
				printf("\nmatchfound!!!!!\n");
				printf("Printf antes do pushtotop!\n");
				printstack(stack1, stack2);
				ft_pushtotop(stack1, pos);
				printf("printstack depois do pushtotop\n");
				printstack(stack1, stack2);
				pb(stack1, stack2);
				printf("current = %d\n", (*stack1)->next->content);
				printf("printstack depois do pb!\n");
				printstack(stack1, stack2);
				current = *stack1;
				pos = 0;
				lever = 1;
			}
			i++;
		}
		pos++;
		i = 0;
		if(lever == 0)
		current = current->next;
	}
}
