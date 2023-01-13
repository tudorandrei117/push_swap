/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburlacu <tburlacu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:47:38 by tburlacu          #+#    #+#             */
/*   Updated: 2023/01/13 18:29:26 by tburlacu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H


# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct node_a
{
	int				content;
	struct node_a	*next;
	int				argc;
}				t_node;

//main operations
void		ft_swap(t_node **stack);
//t_node *ft_lstsecondlast(t_node *head);
void		ft_rotate(t_node **stack);
void		ft_reverse(t_node **stack);
void		ft_push(t_node **stack1, t_node **stack2);
//main operations

//operations
void		ra(t_node **stack1);
void		rb(t_node **stack2);
void		rr(t_node **stack1, t_node **stack2);
void		pa(t_node **a, t_node **b);
void		pb(t_node **a, t_node **b);
void		rra(t_node **stack1);
void		rra(t_node **stack2);
void		rrr(t_node **stack1, t_node **stack2);
void		sa(t_node **stack1);
void		sb(t_node **stack2);
void		ss(t_node **stack1, t_node **stack2);
//operations

//sorters
void		short_sorter(t_node **stack);
//sorters

//utils
void		ft_lstadd_back(t_node **lst, t_node *new);
t_node		*ft_lstlast(t_node *lst);
void		push_lower(t_node **stack1, t_node **stack2);
void		printstack(t_node **current, t_node **current2);
t_node		*ft_addstack(long value, int argc);
long		ft_atol(const char *str);
t_node		*push_swap(int argc, char **argv);
void 		sorter5(t_node **stack1, t_node **stack2);
//utils

#endif


