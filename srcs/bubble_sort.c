#include "../includes/push_swap.h"


void bubble_sort_a(t_data *data)
{
    int count;
    int ordered;
    t_lst_st *temp;
    t_stack *stack;

    ordered = 0;
    stack = &data->stack_a;
    move_down_a(data, stack->bigger);
    while (!ordered || !is_all_sorted(data))
    {
        count = data->stack_a.size;
        ordered = 1;        
        temp = stack->start;
        while (--count && temp && temp->next && !is_all_sorted(data))
        {
            if (temp->nbr > temp->next->nbr)
            {
                if (temp->nbr != stack->bigger || temp->next->nbr != stack->smaller)
                {
                    swap_a(data);
                    ordered = 0;
                }
                else
                    count = 1;
            }
            if (!is_all_sorted(data))
                rotate_a(data);
            temp = stack->start;
        }
    }
}