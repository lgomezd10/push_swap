#include "../includes/push_swap.h"
/*
static void system_sort_a(t_data *data, char name)
{
    t_stack *stack;
	t_lst_st *temp;
	int middle;
	int i;
	int size;

	stack = &data->stack_a;
	move_down(data, data->stack_a.bigger);
	find_min_sort(data);
	size = stack->size;
	while (find_min_sort(data) != stack->bigger)
	{
		middle = get_middle(data);
		temp = data->stack_a.start;
		while (temp && temp->nbr != data->min_sorted)
		{			
			if (temp->nbr <= middle)
			{
				push_b(data);
				//sort_top(data);
			}
			else
				rotate_a(data);
			temp = data->stack_a.start;
		}
		system_sort(data);
		move_down(data, data->stack_a.bigger);
		i = 0;
		while (stack->size < size)
		{
			push_a(data);
			sort_top(data);
		}					
	}
}


void merge_select_short(t_data *data)
{

	sort_array(data);
	system_sort_a(data, 'A');
}
*/