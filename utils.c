/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburlacu <tburlacu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:46:07 by tburlacu          #+#    #+#             */
/*   Updated: 2023/01/13 18:31:46 by tburlacu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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



void	push_lower(t_node **stack1, t_node **stack2)
{
	int 	lowest;
	t_node *current;
	int		argc;

	argc = (*stack1)->argc;
	current = *stack1;
	lowest = find_lowest(current);
	while (argc != 0)
	{
		printf("pb\n");
		if (current->content == lowest)
		{
			ft_push(stack1, stack2);
			break ;
		}
		if (current->next->content == lowest)
		{
			sa(stack1);
			ft_push(stack1, stack2);
			break ;
		}
		if (current->next->next->content == lowest)
		{
			ra(stack1);
			sa(stack1);
			ft_push(stack1, stack2);
			break ;
		}
		if (current->next->next->next->content == lowest)
		{
			rra(stack1);
			rra(stack1);
			ft_push(stack1, stack2);
			break ;
		}
		if (current->next->next->next->next->content == lowest)
		{
			rra(stack1);
			ft_push(stack1, stack2);
			break ;
		}
		argc--;
	}
}

