#include "../includes/push_swap.h"

void merge_short(t_data *data)
{

	t_stack *stack;
	t_lst_st *temp;
	int count;
	int middle;
	int i;

	stack = &data->stack_a;
	middle = get_middle(stack);
	printf("valor de middle\n");
	temp = data->stack_a.start;
	count = stack->size;
	if (stack->size > 1)
	{
		while (!is_sort_increasing(stack->start))
		{
			while (count)
			{
				if (temp->nbr < middle)
					push_b(data);
				else
					rotate_a(data);
				count--;
			}
			if (!is_sort_increasing(stack->start))
			{
				merge_short(data);
				i = 0;
				while (i < stack->size)
				{
					push_a(data);
					i++;
				}				
			}
			print_stack(&data->stack_a, 'A');
			print_stack(&data->stack_b, 'B');
		}
	}
}