#include "../includes/push_swap.h"


void bubble_sort_a(t_data *data)
{
    int count;
    int ordered;
    t_lst_st *temp;
    t_stack *stack;

    ordered = 0;
    stack = &data->stack_a;
    move_down(data, stack->bigger);
    while (!ordered || !is_sort_increasing(stack->start))
    {
        count = data->stack_a.size;
        ordered = 1;        
        temp = stack->start;
        while (--count && temp && temp->next && !is_sort_increasing(stack->start))
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
            if (!is_sort_increasing(stack->start))
                rotate_a(data);
            temp = stack->start;
        }
    }
}

void bubble_sort_b(t_data *data)
{
    int count;
    int ordered;
    t_lst_st *temp;
    t_stack *stack;

    ordered = 0;
    stack = &data->stack_b;
    while (!ordered || !is_sort_decreasing(stack->start))
    {
        count = data->stack_b.size;
        ordered = 1;
        temp = stack->start;
        while (--count && temp && temp->next)
        {
            if (temp->nbr < temp->next->nbr)
            {
                if (temp->nbr != stack->smaller || temp->next->nbr != stack->bigger)
                {
                    swap_b(data);
                    ordered = 0;
                }
                else
                    count = 1;
            }
            rotate_b(data);
            temp = stack->start;
        }
    }
}