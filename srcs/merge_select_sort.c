#include "../includes/push_swap.h"

static void system_sort_a(t_data *data, int sort)
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
            {
                push_b(data);
                if (sort)
                    sort_top(data);
            }
            else
                rotate_a(data);
            temp = data->stack_a.start;
            size--;
        }
        sort_top(data);
        system_sort_a(data, sort);
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

void insertion_from_b(t_data *data)
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


void merge_select_sort(t_data *data)
{
   system_sort_a(data, 0);
   system_sort_b(data);
   selection_sort(data);
}

void merge_insert_sort(t_data *data)
{
   system_sort_a(data, 0);
   system_sort_b(data);
   insertion_sort(data);    
}

void merge_insert_sort2(t_data *data)
{
   system_sort_a(data, 1);
   while (data->stack_b.size)
       insertion_from_b(data);
}

void merge_insert_sort3(t_data *data)
{
   system_sort_a(data, 1);
   while (data->stack_b.size)
       insertion_from_b(data);
}
