#include "../includes/push_swap.h"

int get_pos_prev_of(t_data *data, t_stack *stack, int pos)
{
    t_lst_st *temp;
    int pos_stack;

    pos_stack = 0;
    temp = stack->start;
    while (temp)
    {
        if (temp->pos_ord + 1 == pos)
            return (pos_stack);
        pos_stack++;
        temp = temp->next;
    }
    return (-1);
}

int get_pos_next_of(t_data *data, t_stack *stack, int pos)
{
    t_lst_st *temp;
    int pos_stack;

    pos_stack = 0;
    temp = stack->start;
    while (temp)
    {
        if (temp->pos_ord == pos + 1)
            return (pos_stack);
        pos_stack++;
        temp = temp->next;
    }
}

int get_next_of_a(t_data *data, t_stack *stack, int pos)
{
    t_lst_st *temp;
    int pos_stack;

    pos_stack = 0;
    temp = stack->start;
    if (pos < stack->start->pos_ord && pos > stack->end->pos_ord)
        return (stack->start->nbr);
    while (temp)
    {
        if (pos < temp->pos_ord && temp->nbr == stack->smaller)
            return (temp->next);
        if (pos > temp->pos_ord && temp->nbr == stack->bigger)
            return (temp->next);
        if (pos > temp->pos_ord && pos < temp->next->pos_ord)
            return (temp->next);
        pos_stack++;
        temp = temp->next;
    }
}

int get_number_actions(t_data *data, t_stack *stack, int pos_stack)
{
    int actions;

    if (pos_stack > stack->size / 2)
        actions = stack->size - pos_stack - 1;
    else
        actions = pos_stack;
    return (actions);
}