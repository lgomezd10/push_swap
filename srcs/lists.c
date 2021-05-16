#include "../includes/push_swap.h"

t_lst_st *add_new_back(t_stack *stack, int nbr)
{
    t_lst_st    *new;

    new = (t_lst_st *)ft_calloc(sizeof(t_lst_st), 1);
    if (!new)
        show_error();
    new->nbr = nbr;
    if (!stack->start)
    {
        stack->start = new;
        stack->end = new;
        stack->size = 1;
        return (new);
    }
    stack->end->next = new;
    new->prev = stack->end;
    stack->end = new;
    stack->size++;
    return (new);
}

void    add_element_front(t_stack *stack, t_lst_st *element)
{
    if (!stack->start)
    {
        element->prev = 0;
        element->next = 0;
        stack->start = element;
        stack->end = element;
        stack->size = 1;
    }
    else
    {
        element->prev = 0;
        element->next = stack->start;
        stack->start = element;
        stack->size++;
    }
}

void    add_element_back(t_stack *stack, t_lst_st *element)
{
    if (!stack->start)
    {
        stack->start = element;
        stack->end = element;
        stack->size = 1;
    }
    else
    {
        stack->end->next = element;
        element->prev = stack->end;
        stack->end = element;
        stack->size++;
    }
}

void remove_element(t_stack *stack, t_lst_st *element)
{
    if (!element->prev)
        stack->start = element->next;
    if (!element->next)
        stack->end = element->prev;
    element->prev->next = element->next;
    element->next->prev = element->prev;
    stack->size--;
}