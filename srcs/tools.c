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

void rotate_all(t_data *data, int from, int to, void (*rot)(t_data *))
{
    int i;

    i = from;
    while (i < to)
    {
        rot(data);
        i++;
    }
}

void move_up(t_data *data, int nbr)
{
    int found;
    int pos;
    t_lst_st *temp;

    pos = 0;
    found = 0;
    temp = data->stack_a.start;
    while (!found && temp)
    {
        if (temp->nbr == nbr)
        {
            if (pos > data->stack_a.size / 2)            
                rotate_all(data, pos, data->stack_a.size, reverse_rotate_a);
            else
                rotate_all(data, 0, pos, rotate_a);
            found = 1;
        }
        pos++;
        temp = temp->next;
    }
}

void move_down(t_data *data, int nbr)
{
    int found;
    int pos;
    t_lst_st *temp;

    pos = 0;
    found = 0;
    temp = data->stack_a.start;
    while (!found && temp)
    {
        if (temp->nbr == nbr)
        {
            if (pos > data->stack_a.size / 2)            
                rotate_all(data, pos, data->stack_a.size - 1, reverse_rotate_a);
            else
                rotate_all(data, 0, pos + 1, rotate_a);
            found = 1;
        }
        pos++;
        temp = temp->next;
    }
}

void move_down_b(t_data *data, int nbr)
{
    int found;
    int pos;
    t_lst_st *temp;

    pos = 0;
    found = 0;
    temp = data->stack_b.start;
    while (!found && temp)
    {
        if (temp->nbr == nbr)
        {
            if (pos > data->stack_b.size / 2)            
                rotate_all(data, pos, data->stack_b.size - 1, reverse_rotate_b);
            else
                rotate_all(data, 0, pos + 1, rotate_b);
            found = 1;
        }
        pos++;
        temp = temp->next;
    }
}

int get_middle(t_data *data)
{
    int i;
    int pos;
    int to_short;
    int middle;
    t_stack stack;

    if (data->sorted)
    {
        stack = data->stack_a;
        i = 0;
        pos = data->size - stack.size;
        to_short = (data->pos_min_sorted - pos);
        if (to_short == 2)
            to_short = 0;
        i = pos + (to_short / 2);
        return (data->sorted[i]);
    }
    return (0);
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
