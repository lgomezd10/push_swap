#include "../includes/push_swap.h"

void swap_list(t_list **list)
{
    t_list *temp;

    if (list && *list && (*list)->next)
    {
        temp = (*list)->next;
        (*list)->next = temp->next;
        temp->next = (*list)->next;
        list = &temp;
    }
}

void move_of_list(t_list **src, t_list **dest)
{
    t_list *temp;

    if (src && dest && *src)
    {
        temp = *src;
        src = &temp->next;
        ft_lstadd_front(dest, temp);
    }
}

void rotate_list(t_list **list)
{
    t_list *prev;
    t_list *temp;
    if (list && *list && (*list)->next)
    {
        temp = *list;
        prev = 0;
        while (temp->next)
        {
            prev = temp;
            temp = temp->next;
        }
        if (prev)
        {
            ft_lstadd_front(list, temp);
            prev->next = 0;
        }
    }
}

void rotate_reverse_list(t_list **list)
{
    t_list *temp;

    if (list && *list && (*list)->next)
    {
        temp = *list;
        list = &temp->next;
        temp->next = 0;
        ft_lstadd_back(list, temp);
    }
}