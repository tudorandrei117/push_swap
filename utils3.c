/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburlacu <tburlacu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:54:27 by tburlacu          #+#    #+#             */
/*   Updated: 2023/01/19 17:58:17 by tburlacu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void list2array(t_node **stack1, int *array, int size)
{
	t_node *current;
	int i;
	
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

void sort_array_ascending(int* array, int size) 
{
    int temp;
	int i;
	int j;

	i = 0;
	while(i < size - 1)
	{
		j = i + 1;
		while(j < size)
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

void ft_pushtotop(t_node **stack1)
{
	t_node *current;
	current = stack1;
	t_node *half;
	half = lstsize(stack1) / 2;
	if (get_pos(stack1) > half)
	{
		while(get_pos(stack1) == (*stack1)->head)
		{
			rra(stack1);
		}
	}
		else if (get_pos(stack1) <= half)
	{
		while(get_pos(stack1) == (*stack1)->head)
		{
			ra(stack1);
		}
	}
	
}

int get_position(t_node *stack1) 
{
    t_node *temp;
	temp = stack1->head; 
    int pos = 1; 
	
    while (temp != stack1)
	{ 
        temp = temp->next; 
        pos++;
    }
    return pos;
}


int array(int *array, t_node **stack1, t_node **stack2)
{
	int i;
	i = 0;
	while(*stack1->next != NULL)
	{
		While(array[i])
		{
			if(array[i] == *stack1->content)
				{
				ft_pushtotop(stack1);
					pb(stack1, stack2)
		}
		}
	}
}
