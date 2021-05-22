#include "../includes/push_swap.h"

int find_next_min(t_stack stack, int min)
{
    t_lst_st *temp;
    int next;

    temp = stack.start;
    next = stack.bigger;
    if (min < next)
    {
        while (temp)
        {
            if (temp->nbr > min && temp->nbr < next)
                next = temp->nbr;
            temp = temp->next;
        }
        return (next);
    }
    else
        return (min);
}

void sort_array(t_data *data)
{
    int *sorted;
    t_stack stack;
    int i;

    stack = data->stack_a;
    data->size = stack.size;
    sorted = (int *)ft_calloc(sizeof(int), data->size);
    if (!sorted)
        show_error();
    i = 0;
    sorted[i] = stack.smaller;
    while (++i < stack.size)
        sorted[i] = find_next_min(stack, sorted[i - 1]);
    data->sorted = sorted;
}

int get_middle_temp(t_data *data, t_stack *stack)
{
    int *sorted;
    int i;

    
    sorted = (int *)ft_calloc(sizeof(int), stack->size);
    if (!sorted)
        show_error();
    i = 0;
    sorted[i] = stack->smaller;
    while (++i < stack->size)
        sorted[i] = find_next_min(*stack, sorted[i - 1]);
    i = sorted[stack->size / 2];
    free(sorted);
    return (i);
}

void sort_array_b(t_data *data)
{
    int *sorted;
    t_stack stack;
    int i;

    stack = data->stack_b;
    data->size_b = stack.size;
    sorted = (int *)ft_calloc(sizeof(int), stack.size);
    if (!sorted)
        show_error();
    i = 0;
    sorted[i] = stack.smaller;
    while (++i < stack.size)
        sorted[i] = find_next_min(stack, sorted[i - 1]);
    data->sorted_b = sorted;
}