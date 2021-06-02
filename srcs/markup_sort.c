#include "../includes/push_swap.h"

int is_smaller(t_lst_st *list, int pos, int size)
{
    int count;

    count = 0;
    while (list && count < size)
    {
        if (list->pos_ord < pos)
            return (0);
        list = list->next;
        count++;
    }
    return (1);
}

void markup_stack(t_data *data)
{
    t_lst_st *temp;
    int last_sorted;

    temp = data->stack_a.start;
    if (temp)
    {
        temp->is_sorted = 1;
        last_sorted = temp->pos_ord;
        temp = temp->next;
        while (temp && temp->next)
        {
            if (temp->pos_ord > last_sorted)
            {
                temp->is_sorted = 1;
                last_sorted = temp->pos_ord;
            }
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
        temp = temp->next;
    }
    return (0);
}

void markup_sort(t_data *data)
{
    t_lst_st *temp;
    int pos1;
    int pos2;
    int pos3;    
    
    move_up_a(data, data->stack_a.smaller);
    markup_stack(data);
    temp = data->stack_a.start;
    while (has_not_sorted(data))
    {
        temp = data->stack_a.start;
        if (temp && temp->next && temp->pos_ord > temp->next->pos_ord)
        {
            if (temp->nbr == data->stack_a.bigger && temp->next->nbr == data->stack_a.smaller)
                rotate_a(data);
            else
                swap_a(data);            
        }
        else if (temp->is_sorted)
            rotate_a(data);
        else
            push_b(data);
        
    }
    while (data->stack_b.size > 0)
    {
        
        do_best_action_to_a(data);
        /*
        printf("prueba 5\n");
        print_stack(&data->stack_a, 'a');
        print_stack(&data->stack_b, 'b');
        */
    }
    move_down_a(data, data->stack_a.bigger);
    
}