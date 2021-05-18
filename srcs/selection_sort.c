#include "../includes/push_swap.h"


void selection_sort(t_data *data)
{
    int nbr;
    
    while (!is_sort_increasing(data->stack_a.start) && data->stack_a.size > 0)
    {
        nbr = data->stack_a.smaller;
        move_up(data, nbr);
        print_stack(&data->stack_a, 'A');
        push_b(data);
        print_stack(&data->stack_a, 'A');
        print_stack(&data->stack_b, 'B');
    }
    while (data->stack_b.size > 0)
        push_a(data);    
}