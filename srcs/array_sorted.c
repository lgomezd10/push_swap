#include "../includes/push_swap.h"

int find_next_min(t_stack stack, int min, int pos)
{
    t_lst_st *temp;
    int next;
    t_lst_st *min_node;

    temp = stack.start;
    next = stack.bigger;
    if (min < next)
    {
        while (temp)
        {
            if (temp->nbr > min && temp->nbr <= next)
            {
                next = temp->nbr;
                min_node = temp;
            }
            temp = temp->next;
        }
        if (pos >= 0)
           min_node->pos_ord = pos;
        return (next);
    }
    else
        return (min);
}

t_array *get_array_sorted(t_stack stack, int firts_time)
{
    t_array *array;
    int *sorted;
    int i;
    int pos;
    
    array = ft_calloc(sizeof(t_array), 1);
    if (!array)
        show_error();
    array->size = stack.size;
    sorted = (int *)ft_calloc(sizeof(int), array->size);
    if (!sorted)
        show_error();
    i = 0;
    sorted[i] = stack.smaller;
    while (++i < stack.size)
    {
        pos = i;
        if (!firts_time)
            pos = -1;
        sorted[i] = find_next_min(stack, sorted[i - 1], pos);
    }
    array->array = sorted;
    return (array);
}

void sort_array(t_data *data)
{
    t_stack stack;
    int i;

    stack = data->stack_a;
    data->size = stack.size;
    data->sorted = get_array_sorted(stack, 1);
    i = 0;
    while (i < stack.size - 1)
    {
        if (data->sorted->array[i] == data->sorted->array[i + 1])
            show_error();
        i++;
    }
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
        sorted[i] = find_next_min(*stack, sorted[i - 1], -1);
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
        sorted[i] = find_next_min(stack, sorted[i - 1], -1);
    data->sorted_b = sorted;
}