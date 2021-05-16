#include "../includes/push_swap.h"

void swap_stack(t_stack *stack)
{
    t_lst_st *temp;

    if (stack->start && stack->start->next)
    {
        temp = stack->start;        
        stack->start = temp->next;
        temp->next = stack->start->next;
        temp->prev = stack->start;
        stack->start->prev = 0;
        stack->start->next = temp;
    }
}

void move_of_stack(t_stack *src, t_stack *dest)
{
    t_lst_st *temp;

    if (src->start)
    {
        temp = src->start;
        remove_element(src, temp);
        add_element_front(dest, temp);
    }
}

void rotate_stack(t_stack *stack)
{
    t_lst_st    *temp;

    if (stack->start && stack->start->next)
    {
        temp = stack->start;
        remove_element(stack, temp);
        add_element_back(stack, temp);
    }
}

void rotate_reverse_stack(t_stack *stack)
{
    t_lst_st    *temp;

    if (stack->start && stack->start->next)
    {
        temp = stack->end;
        remove_element(stack, temp);
        add_element_front(stack, temp);
    }
}