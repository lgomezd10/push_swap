#include "../includes/push_swap.h"




void merge_short(t_data *data)
{
	t_stack *stack;
	t_lst_st *temp;
	int middle;
	int size;

	stack = &data->stack_a;
	move_down_a(data, data->stack_a.bigger);
	find_min_sort(data);
	size = stack->size;
	while (find_min_sort(data) != stack->smaller)
	{
		middle = get_middle(data);
		temp = data->stack_a.start;
		while (temp && temp->nbr != data->min_sorted)
		{			
			if (temp->nbr <= middle)
				push_b(data);
			else
				rotate_a(data);
			temp = data->stack_a.start;
		}		
		merge_short(data);
		move_down_a(data, data->stack_a.bigger);
		while (stack->size < size)
		{
			push_a(data);
			sort_top(data);
		}					
	}
}