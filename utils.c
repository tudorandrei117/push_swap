/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburlacu <tburlacu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:46:07 by tburlacu          #+#    #+#             */
/*   Updated: 2023/01/19 15:43:09 by tburlacu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/**
 * Adds a node to the end of a linked list.
 * 
 * @param lst A pointer to a pointer to the first node of a linked list.
 * @param new the new node to add to the list
 * 
 * @return The last node in the list.
 */
void	ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*last;

	if (!lst || !new)
		return ;
	while (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

/**
 * It returns the last node in a linked list.
 * 
 * @param lst A pointer to the first node of a linked list.
 * 
 * @return The last node in the list.
 */
t_node	*ft_lstlast(t_node *lst)
{
	if (lst == NULL)
	{
		return (NULL);
	}
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

int	find_lowest(t_node *stack)
{
	int		lowest;
	t_node	*current;

	current = stack;
	lowest = INT_MAX;
	while (current != NULL)
	{
		if (current->content < lowest)
		{
			lowest = current->content;
		}
		current = current->next;
	}
	return (lowest);
}

int	ft_lstsize(t_node *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
