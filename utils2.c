/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tudor <tudor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:02:44 by tburlacu          #+#    #+#             */
/*   Updated: 2023/02/01 11:45:46 by tudor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/**
 * It prints the contents of the two stacks
 * 
 * @param stack1 The first stack
 * @param stack2 the second stack
 */
void	printstack(t_node **stack1, t_node **stack2)
{
	t_node	*current1;
	t_node	*current2;

	current1 = *stack1;
	current2 = *stack2;
	printf("--------------\n");
	while (current1)
	{
		printf("%d\n", current1->content);
		current1 = current1->next;
	}
	while (current2)
	{
		printf("\t%d\n", current2->content);
		current2 = current2->next;
	}
	printf("--------------\n");
}

/**
 * It creates a new node, assigns the value to the node's content,
	and returns the node
 * 
 * @param value the value of the node
 * @param argc the number of arguments that were passed to the program
 * 
 * @return A pointer to a new node.
 */
t_node	*ft_addstack(long value, int argc)
{
	t_node	*newlst;

	newlst = malloc(sizeof(t_node));
	if (newlst == NULL)
		return (NULL);
	newlst->content = value;
	newlst->next = NULL;
	return (newlst);
}

long	ft_atol(const char *str)
{
	long		result;
	int			sign;
	const char	*p;

	result = 0;
	sign = 1;
	p = str;
	if (*p == '-')
	{
		sign = -1;
		p++;
	}
	while (*p >= '0' && *p <= '9')
	{
		result = (result * 10) + (*p - '0');
		p++;
	}
	return (sign * result);
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