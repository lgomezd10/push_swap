#include "../includes/push_swap.h"

void markup_stack(t_data *data)
{
    t_lst_st *temp;
    int last_sorted;

    temp = data->stack_a.start;
    if (temp)
    {
        temp->is_sorted = 1;
        temp = temp->next;
        last_sorted = temp->pos_ord;
        while (temp)
        {
            if (temp->pos_ord > last_sorted)
            {
                temp->is_sorted = 1;
                last_sorted = temp->pos_ord;
            }
            else
                temp->is_sorted = 0;
            temp = temp->next;
        }
    }    
}

int has_not_sorted(t_data *data)
{
    t_lst_st *temp;
   
    temp = data->stack_a.start;
    while (temp)
    {
        if (!temp->is_sorted)
            return (1);
    }
    return (0);
}

void markup_sort(t_data *data)
{
    t_lst_st *temp;
    int pos1;
    int pos2;
    int pos3;

    markup_stack(data);
    temp = data->stack_a.start;
    while (has_not_sorted(data))
    {
        temp = data->stack_a.start;
        if (temp->is_sorted)
            rotate_a(data);
        else
            push_b(data);
    }
    while (data->stack_b.size > 0)
    {
        pos1 = get_pos_next_of(data, &data->stack_a, data->stack_b.start->pos_ord);
        pos2 = get_pos_prev_of(data, &data->stack_b, data->stack_a.start->pos_ord);
        pos3 = get_next_of_a(data, &data->stack_a, data->stack_b.start->pos_ord);
        if (pos1 == -1 && pos2 == -1)
            move_up_a(data, pos3);
        if (pos1 < pos2)
            insertion_one_in_a(data);
    }
    
    
}