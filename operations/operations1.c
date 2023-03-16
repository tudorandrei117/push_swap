/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tudor <tudor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:46:11 by tburlacu          #+#    #+#             */
/*   Updated: 2023/03/13 17:47:39 by tudor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//este codigo server para trocar os primeiros dois elementos da stack
void	ft_swap(t_node **stack)
{
	t_node	*tmp;

	tmp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	tmp->next = *stack;
	*stack = tmp;
}

//este codigo server para tornar o primeiro elemento o ultimo da stack
void	ft_rotate(t_node **stack)
{
	t_node	*temp1;
	t_node	*temp2;

	temp1 = *stack;
	*stack = (*stack)->next;
	temp2 = *stack;
	while (temp2->next)
		temp2 = temp2->next;
	temp2->next = temp1;
	temp1->next = NULL;
}

//este codigo server para tornar o ultimo elemento para o primeiro da stack
void	ft_reverse(t_node **stack)
{
	t_node *temp;

	temp = *stack;
	while ((*stack)->next)
		*stack = (*stack)->next;
	(*stack)->next = temp;
	while (temp->next != *stack)
		temp = temp->next;
	temp->next = NULL;
}

//este codigo serve para mandar o primeiro elemento da stack src para a dst
void	ft_push(t_node **stack1, t_node **stack2)
{
	t_node	*temp;

	if (*stack2 == NULL)
		return ;
	temp = *stack2;
	*stack2 = (*stack2)->next;
	temp->next = *stack1;
	*stack1 = temp;
}

void	rrr(t_node **stack1, t_node **stack2)
{
	ft_reverse(stack1);
	ft_reverse(stack2);
	write(1, "rrr\n", 4);
}
