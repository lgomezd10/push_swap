#include "../includes/push_swap.h"

static void system_sort_a(t_data *data)
{
    t_stack *stack;
	t_lst_st *temp;
	int middle;
	int i;
	int size;

	stack = &data->stack_a;
	size = stack->size;
    if (stack->size > 2)
    {
        middle = get_middle_temp(data, stack);
        temp = data->stack_a.start;        
        while (temp && stack->size > 2 && size)
        {		
            
            if (temp->nbr <= middle)
                push_b(data);
            else
                rotate_a(data);
            temp = data->stack_a.start;
            size--;
        }
        sort_top(data);
        system_sort_a(data);
    }
}

static void system_sort_b(t_data *data)
{
    t_stack *stack;
	t_lst_st *temp;
	int middle;
	int i;
	int size;

	stack = &data->stack_b;
	size = stack->size;
    if (size > 1)
    {
        middle = get_middle_temp(data, stack);
        temp = data->stack_b.start;
        while (temp && size)
        {	
            if (temp->nbr >= middle)
                push_a(data);
            else
                rotate_b(data);
            temp = data->stack_b.start;
            size--;
        }
        sort_top(data);
        system_sort_b(data);
        
    }
    else
        push_a(data);
}


void merge_select_short(t_data *data)
{
   system_sort_a(data);
   system_sort_b(data);
   selection_sort(data);
    
}
