/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburlacu <tburlacu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:50:41 by tburlacu          #+#    #+#             */
/*   Updated: 2023/01/10 17:17:18 by tburlacu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H


# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}					t_list;

//commandsvoid	rra(t_list **stack1)
void				pa(t_list **a, t_list **b);
void				pb(t_list **a, t_list **b);
void				sa(t_list **stack1);
void				sb(t_list **stack2);
void				ss(t_list **stack1, t_list **stack2);
void				ra(t_list **stack1);
void				rb(t_list **stack2);
void				rr(t_list **stack1, t_list **stack2);
void				rra(t_list **stack1);
void				rrb(t_list **stack2);
void				rrr(t_list **stack1, t_list **stack2);

//utils
void				ft_lstadd_back(t_list **lst, t_list *new);
t_list				*ft_lstlast(t_list *lst);

//sorters
void				sorter_3(t_list **stack1);












#endif
