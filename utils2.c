/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburlacu <tburlacu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:02:44 by tburlacu          #+#    #+#             */
/*   Updated: 2023/01/18 17:02:39 by tburlacu         ###   ########.fr       */
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
	t_node	*current;
	t_node	*current2;
	current2 = *stack2;
	current = *stack1;
	printf("--------------\n");
	while (current != NULL)
	{
		printf("%d\n",current->content);
		current = current->next;
	}
	while (current2 != NULL)
	{
		if (current2 != 0)
		{
			printf("\t %d \n", current2->content);
			current2 = current2->next;
		}
	}
	printf("--------------\n");
}

/**
 * It creates a new node, assigns the value to the node's content, and returns the node
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
long ft_atol(const char *str)
{
	long	result;
	int	sign;

	result = 0;
	sign = 1;
	const char *p = str;

	if (*p == '-') {
        sign = -1;
        p++;
	}
    while (*p >= '0' && *p <= '9') {
        result = (result * 10) + (*p - '0');
        p++;
	}
    return (sign * result);
}

