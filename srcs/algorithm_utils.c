#include "../includes/push_swap.h"

void insertion_one_in_a(t_data *data)
{
	
	int nbr;
	t_stack *stack_a;
	t_stack *stack_b;
	int prev;

	
	stack_a = &data->stack_a;
	stack_b = &data->stack_b;
    nbr = stack_b->start->nbr;
    if (nbr > stack_a->bigger || nbr < stack_a->smaller)
        move_up_a(data, stack_a->smaller);
    else
    {
        prev = find_prev_a(*stack_a, nbr);
        move_up_a(data, prev);
    }	
    push_a(data);
}

void insertion_one_in_b(t_data *data)
{
	
	int nbr;
	t_stack *stack_a;
	t_stack *stack_b;
	int prev;

	
	stack_a = &data->stack_a;
	stack_b = &data->stack_b;
    nbr = stack_a->start->nbr;
    if (nbr > stack_b->bigger || nbr < stack_b->smaller)
        move_up_a(data, stack_b->bigger);
    else
    {
        prev = find_prev_b(*stack_b, nbr);
        move_up_b(data, prev);
    }	
    push_b(data);
}

void merge_sort_a(t_data *data)
{
	t_stack *stack;
	t_lst_st *temp;
	int middle;
	int size;

	stack = &data->stack_a;
	size = stack->size;
	if (stack->size > 2)
	{
		middle = get_middle_temp(data, stack);
		temp = data->stack_a.start;
		while (temp && size--)
		{
			if (temp->nbr <= middle)
				push_b(data);
			else
				rotate_a(data);
			temp = data->stack_a.start;
		}
		sort_top(data);
		merge_sort_a(data);
	}
}

void merge_sort_b(t_data *data)
{
	t_stack *stack;
	t_lst_st *temp;
	int middle;
	int size;

	stack = &data->stack_b;
	size = stack->size;
	if (stack->size > 1)
	{
		middle = get_middle_temp(data, stack);
		temp = data->stack_b.start;
		while (temp && size--)
		{	
			if (temp->nbr >= middle)
				push_a(data);
			else
				rotate_b(data);
			temp = data->stack_b.start;
		}
		sort_top(data);
		merge_sort_b(data);
	}
	else
		push_a(data);
}

void sort_top(t_data *data)
{
    t_lst_st *list_a;
    t_lst_st *list_b;
    int rot_a;
    int rot_b;

    list_a = data->stack_a.start;
    list_b = data->stack_b.start;
    rot_a = 0;
    rot_b = 0;
		
    if (list_a && list_a->next)
    {
		if (list_a->nbr > list_a->next->nbr)
            rot_a = 1;
    }
    if (list_b && list_b->next)
    {
		if (list_b->nbr < list_b->next->nbr)
            rot_b = 1;
    }	
    if (rot_a && rot_b)
        swap_both(data);
    if (rot_a && !rot_b)
        swap_a(data);
    if (!rot_a && rot_b)
        swap_b(data);	
}