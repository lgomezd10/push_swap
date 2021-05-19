#include "../includes/push_swap.h"

void merge_short(t_data *data)
{

	t_stack *stack;
	t_lst_st *temp;
	int count;
	int middle;
	int i;

	stack = &data->stack_a;
	middle = stack->smaller + (stack->bigger - stack->smaller) / 2;
	printf("valor de middle %d\n", middle);
	count = stack->size;
	if (stack->size > 1)
	{
		while (!is_sort_increasing(stack->start))
		{
			while (count && data->stack_a.start)
			{
				temp = data->stack_a.start;
				if (temp->nbr < middle)
					push_b(data);
				else
					rotate_a(data);
				count--;
			}
			merge_short(data);
			i = 0;
			while (i < stack->size)
			{
				push_a(data);
				i++;
			}				
		}
	}
}