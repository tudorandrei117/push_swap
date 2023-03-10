/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tudor <tudor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:15:05 by tudor             #+#    #+#             */
/*   Updated: 2023/03/08 14:22:16 by tudor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct node_a
{
	struct node_a	*head;
	int				half;
	int				content;
	struct node_a	*next;
}					t_node;

//main operations
void				ft_swap(t_node **stack);
void				ft_rotate(t_node **stack);
void				ft_reverse(t_node **stack);
void				ft_push(t_node **stack1, t_node **stack2);
//main operations

//operations
void				ra(t_node **stack1);
void				rb(t_node **stack2);
void				rr(t_node **stack1, t_node **stack2);
void				pa(t_node **a, t_node **b);
void				pb(t_node **a, t_node **b);
void				rra(t_node **stack1);
void				rrb(t_node **stack2);
void				rrr(t_node **stack1, t_node **stack2);
void				sa(t_node **stack1);
void				sb(t_node **stack2);
void				ss(t_node **stack1, t_node **stack2);
//operations

//sorters 5 or less
void				push_lower2(t_node **stack1, t_node **stack2);
void				push_lower(t_node **stack1, t_node **stack2);
void				short_sorter(t_node **stack);
void				sorter5(t_node **stack1, t_node **stack2);
int					find_lowest(t_node **stack);
//sorters

//list utils
int	find_lowestforshort(t_node *stack);
void				ft_lstadd_back(t_node **lst, t_node *new);
t_node				*ft_lstlast(t_node *lst);
t_node				*ft_addstack(long value);
int					ft_lstsize(t_node *stack1);
void				create_list(int ac, char **av, t_node **stack);
void				lstclear(t_node **lst);
t_node				*create_stack(int argc, char **argv);
void				ft_push_top(t_node **stack1);
int					find_lowest_index(t_node **stack);
//list utils

//algo
t_node				*min_cost(t_node **stack_a, t_node **stack_b);
t_node				*best_match(t_node *stack1, t_node *stack2);
int					best_push(t_node *stack1, t_node *stack2, t_node *node1,
						t_node *node2);
int					total_cost(t_node **stack1, t_node *node);
void				send_to_a(t_node **stack_a, t_node **stack_b);
void				big_sorter(t_node **stack_a, t_node **stack_b);
void				main_sorter(int ac, t_node **stack_a, t_node **stack_b);
void				push_to_b(t_node **stack1, t_node **stack2);

//algo

//utils
int					find_lowest2(int value, t_node **stack);
int					find_mid(t_node **stack);
int					ft_atoi(const char *str);
int					ft_strisdigit(const char *str);
int					half(t_node **stack, t_node *node);
long				ft_atol(const char *str);
size_t				ft_strlen(const char *str);
unsigned long long	return_difference(t_node *a, t_node *b);
int					return_bigger(int a, int b);
//utils

//checker
int					checker_dup(int argc, char **argv);
int					checker_num(int argc, char **argv);
int					checker(int argc, char **argv);
int					analise(t_node **stack);
//checker

#endif
