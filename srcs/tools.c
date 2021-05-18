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

int is_sort_decreasing(t_stack *stack)
{
    t_lst_st *temp;

    temp = stack->start;
    while (temp && temp->next)
    {
        if (temp->next->nbr < temp->nbr)
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
