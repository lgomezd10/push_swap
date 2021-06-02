#include "../includes/push_swap.h"

int get_number_actions(t_data *data, t_stack *stack, int pos_stack)
{
    int actions;

    if (pos_stack > stack->size / 2)
        actions = stack->size - pos_stack - 1;
    else
        actions = pos_stack;
    return (actions);
}

int actions_to_move_a(t_data *data, int pos)
{
    t_lst_st *temp;
    int pos_stack;
    t_stack *stack;

    pos_stack = 0;
    stack = &data->stack_a;
    temp = stack->start;
    while (temp)
    {
        if (temp->pos_ord + 1 == pos)
            return (get_number_actions(data, stack, pos_stack));
        pos_stack++;
        temp = temp->next;
    }
    return (-1);
}

int actions_to_move_b(t_data *data, int pos)
{
    t_lst_st *temp;
    int pos_stack;
    t_stack *stack;

    pos_stack = 0;
    stack = &data->stack_b;
    temp = stack->start;
    while (temp)
    {
        if (temp->pos_ord == pos + 1)
            return (get_number_actions(data, stack, pos_stack));
        pos_stack++;
        temp = temp->next;
    }
    return (-1);
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
            return (temp->nbr);
        if (pos > temp->pos_ord && temp->nbr == stack->bigger)
            return (temp->nbr);
        if (pos > temp->pos_ord && pos < temp->next->pos_ord)
            return (temp->next->nbr);
        pos_stack++;
        temp = temp->next;
    }
    return (0);
}

int get_pos_in_stack(t_data *data, t_stack *stack, int nbr)
{
    t_lst_st *temp;
    int pos;

    temp = stack->start;
    pos = 0;
    while (temp)
    {
        if (temp->nbr == nbr)
            return (pos);
        pos++;
        temp = temp->next;
    }
    return (-1);
}