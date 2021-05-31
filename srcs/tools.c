#include "../includes/push_swap.h"

int is_all_sorted(t_data *data)
{
    int i;
    t_lst_st *temp;

    temp = data->stack_a.start;
    i = 0;
    while (temp)
    {
        if (temp->pos_ord != i)
        {
            //printf("NO esta ordenado el elemento temp: %d, con pos_order %d\n", temp->nbr, temp->pos_ord);
            return(0);
        }
        temp = temp->next;
        i++;
    }
    return (1);
}

int stack_a_is_sorted(t_data *data)
{
    int i;
    t_lst_st *temp;

    temp = data->stack_a.end;
    i = data->sorted->size - 1;
    while (temp)
    {
        if (temp->pos_ord != i)
        {
            return(0);
        }
        temp = temp->prev;
        i--;
    }
    return (1);
}

int stack_b_is_sorted(t_data *data)
{
    int i;
    t_lst_st *temp;

    temp = data->stack_b.end;
    i = 0;
    while (temp && i < data->stack_b.size)
    {
        if (temp->pos_ord != i)
            return(0);
        temp = temp->prev;
        i++;
    }
    return (1);
}

int a_is_sorted(t_data *data)
{
    int i;
    t_lst_st *temp;
    int act;
    int next;

    temp = data->stack_a.start;
    while (temp && temp->next)
    {
        act = temp->pos_ord;
        next = temp->next->pos_ord;
        if (act + 1 != next)
        {
            if (act != data->sorted->size - 1 || temp->next->nbr != data->stack_a.smaller)
                return (0);
        }
        temp = temp->next;
    }
    return (1);
}

int b_is_sorted(t_data *data)
{
    int i;
    t_lst_st *temp;
    int act;
    int next;

    temp = data->stack_b.start;
    while (temp && temp->next)
    {
        act = temp->pos_ord;
        next = temp->next->pos_ord;
        if (act != next + 1)
        {
            if (act != 0 || temp->next->nbr != data->stack_b.bigger)
                return (0);
        }
        temp = temp->next;
    }
    return (1);
}

void divide_a(t_data *data)
{
    t_stack *stack;
	t_lst_st *temp;
	int middle;
	int i;
	int size;

	stack = &data->stack_a;
	size = stack->size;
    if (!is_all_sorted(data))
    {
        middle = get_middle_temp(data, stack);
        temp = data->stack_a.start;        
        while (temp && size)
        {		
            
            if (temp->nbr <= middle)
                push_b(data);
            else
                rotate_a(data);
            temp = data->stack_a.start;
            size--;
        }
    }
}