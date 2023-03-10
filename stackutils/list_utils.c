/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tudor <tudor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:46:07 by tburlacu          #+#    #+#             */
/*   Updated: 2023/03/05 22:29:11 by tudor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

t_node	*ft_addstack(long value)
{
	t_node	*newlst;

	newlst = malloc(sizeof(t_node));
	if (newlst == NULL)
		return (NULL);
	newlst->content = value;
	newlst->next = NULL;
	return (newlst);
}

void	create_list(int ac, char **av, t_node **stack)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		ft_lstadd_back(stack, ft_addstack(ft_atol(av[i])));
		i++;
	}
}

t_node	*create_stack(int argc, char **argv)
{
	int		i;
	t_node	*node;
	t_node	*start;

	start = NULL;
	i = 1;
	while (i != argc)
	{
		node = ft_addstack(ft_atol(argv[i]));
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
