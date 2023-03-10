/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tudor <tudor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:02:44 by tburlacu          #+#    #+#             */
/*   Updated: 2023/03/05 22:28:58 by tudor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_lstsize(t_node *stack1)
{
	int	i;

	i = 0;
	while (stack1 != NULL)
	{
		stack1 = stack1->next;
		i++;
	}
	return (i);
}

void	lstclear(t_node **lst)
{
	t_node	*temp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
	lst = NULL;
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

int	ft_atoi(const char *str)
{
	int			result;
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
