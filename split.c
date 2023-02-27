#include "pushswap.h"

int	module(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

void	negative_sorter(t_node **stack1, t_node **stack2)
{
	t_node	*current;
	t_node	*current2;
	double	div;
	int		pos;

	current = *stack1;
	current2 = *stack2;
	pos = 1;
	div = 1;
	while (current2->content > 0 && current2)
	{
		current2 = current2->next;
		pos++;
        printf("ta a descer ate ao 0\t %i\n", current2->content);
	}
    printf("chegou ao 0\n");
	while (div < 0 && current2)
	{
        printf("a ser posto na posicao certa\n");
		div = current2->content / current->content;
		current2 = current2->next;
		pos++;
	}
    ft_push_to_top_b(stack1, stack2, pos);
    printf("negative!!!!\n");
}
