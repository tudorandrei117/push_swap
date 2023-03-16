/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tudor <tudor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:02:44 by tburlacu          #+#    #+#             */
/*   Updated: 2023/03/13 17:28:14 by tudor            ###   ########.fr       */
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

void	ft_lstclear(t_node **lst)
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


int	find_lowest(t_node **stack)
{
	int		i;
	int		j;
	int		nb;
	t_node	*temp;

	i = find_lowest_index(stack);
	j = 0;
	nb = 0;
	temp = *stack;
	while (temp->next && j < i)
	{
		temp = temp->next;
		j++;
	}
	nb = temp->content;
	return (nb);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;
	int	i;

	res = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (sign * res);
}
