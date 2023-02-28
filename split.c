#include "pushswap.h"

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

int ft_strisdigit(const char *str)
{
    int i;

    i = 0;
    if (str[i] == '-')
        i++;
    while (str[i] != '\0')
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

int	*create_chunk(int *arr, int start_index, int end_index)
{
	int	*chunk;
	int	i;

	i = 0;
	chunk = malloc((end_index - start_index) * sizeof(int));
	while (start_index + i < end_index)
	{
		chunk[i] = arr[start_index + i];
		i++;
	}
	return (chunk);
}

int	**create_chunk_array(int *arr, int arr_size, int chunk_size,
int *num_chunks)
{
	int	num;
	int	**chunks;
	int	i;
	int	j;
	int	end_index;

	num = (arr_size + chunk_size - 1) / chunk_size;
	chunks = malloc(num * sizeof(int *));
	i = 0;
	j = 0;
	while (i < arr_size && j < num)
	{
		end_index = i + chunk_size;
		if (end_index > arr_size)
		{
			end_index = arr_size;
		}
		chunks[j] = create_chunk(arr, i, end_index);
		i += chunk_size;
		j++;
	}
	*num_chunks = num;
	return (chunks);
}