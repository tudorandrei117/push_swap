/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburlacu <tburlacu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:56:51 by tburlacu          #+#    #+#             */
/*   Updated: 2023/01/09 15:16:24 by tburlacu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static	void	ft_push(t_list **src, t_list **dest)
{
	t_list	*tmp;

	if (!*src || !*dest)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dest;
	return ;
}

void	pa(t_list **a, t_list **b)
{
	ft_push(a, b);
}

void	pb(t_list **a, t_list **b)
{
	ft_push(b, a);
}
