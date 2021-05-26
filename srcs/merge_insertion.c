#include "../includes/push_swap.h"

void insertion_one_of_b(t_data *data)
{
	
	int nbr;
	t_stack *stack_a;
	t_stack *stack_b;
	int prev;

	stack_a = &data->stack_a;
	stack_b = &data->stack_b;
    nbr = stack_b->start->nbr;		
    if (nbr > data->stack_a.bigger || nbr < stack_a->smaller)
        move_up_a(data, stack_a->smaller);
    else
    {
        prev = find_prev_a(*stack_a, nbr);
        move_up_a(data, prev);
    }	
    push_a(data);
}

void merge_inser_2_sort(t_data *data)
{
	t_stack *stack;
	t_lst_st *temp;
	int middle;
	int size;
	int size2;

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
		merge_inser_2_sort(data);
		/*
		size2 = size - stack->size;
		if (size2 < 10)
		{
			*/
			while (stack->size < size)
		
				insertion_one_of_b(data);
				/*
		}
		else
		{
			push_a(data);
			sort_top(data);
		}	*/		
	}
}