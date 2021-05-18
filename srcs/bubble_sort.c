#include "../includes/push_swap.h"


void buble_sort(t_data *data)
{
    int count;
    int ordered;
    t_lst_st *temp;
    t_stack *stack;

    ordered = 0;
    stack = &data->stack_a;
    while (!ordered || !is_sort_increasing(stack->start))
    {
        count = data->stack_a.size;
        ordered = 1;
        temp = stack->start;
        while (--count && temp && temp->next)
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
            rotate_a(data);
            temp = stack->start;
        }
    }
}

void buble_sort_b(t_data *data)
{
    int count;
    int ordered;
    t_lst_st *temp;
    t_stack *stack;

    ordered = 0;
    stack = &data->stack_a;
    while (!ordered)
    {
        count = data->stack_a.size - 1;
        ordered = 1;
        temp = stack->start;
        while (count && temp && temp->next)
        {
            if (temp->nbr > temp->next->nbr)
            {
                swap_stack(stack);
                add_new_back(&data->operations, Op_sa);
                ordered = 0;
            }
            rotate_stack(stack);
            add_new_back(&data->operations, Op_ra);
            print_stack(stack, 'A'); 
            temp = stack->start;
            count--;
        }
        rotate_stack(stack);
        add_new_back(&data->operations, Op_ra);
    }    
}