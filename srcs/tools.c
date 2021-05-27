#include "../includes/push_swap.h"

int is_sort_increasing(t_lst_st *list)
{
    t_lst_st *temp;

    temp = list;
    while (temp && temp->next)
    {
        if (temp->nbr > temp->next->nbr)
            return (0);
        temp = temp->next;
    }
    return (1);    
}

int is_sort_decreasing(t_lst_st *list)
{
    t_lst_st *temp;

    temp = list;
    while (temp && temp->next)
    {
        if (temp->nbr < temp->next->nbr)
            return (0);
        temp = temp->next;
    }
    return (1);    
}


int get_middle_b(t_data *data)
{
    int i;
    int to_short;
    int middle;
    t_stack stack;

    if (data->sorted_b)
    {
        stack = data->stack_b;
        i = 0;
        to_short = data->size - data->pos_min_sorted_b;
        if (to_short == 2)
            to_short = 0;
        i = data->pos_min_sorted_b + (to_short / 2);
        return (data->sorted_b[i]);
    }
    return (0);
}

