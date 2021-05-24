#include "../includes/push_swap.h"

void delete_list(t_lst_st **list)
{
    t_lst_st *delete;
    t_lst_st *temp;

    temp = *list;
    while (temp)
    {
        delete = temp;
        temp = temp->next;
        free(delete);
    }
    *list = 0;
}



void clear_data(t_data *data)
{
    delete_list(&data->stack_a.start);
    ft_bzero(&data->stack_a, sizeof(t_stack));
    delete_list(&data->stack_b.start);
    ft_bzero(&data->stack_b, sizeof(t_stack));
    free(data->sorted);
    data->sorted = 0;
    free(data->sorted_b);
    data->sorted_b = 0;

}

void save_and_restart(t_data *data, t_stack *op)
{
    if (!op->start || data->operations.size < op->size)
    {
        if (op->start)
            delete_list(&op->start);
        ft_memcpy(op, &data->operations, sizeof(t_stack));
    }
    else
        delete_list(&data->operations.start);
    ft_bzero(&data->operations, sizeof(t_stack));
    clear_data(data);
    ft_bzero(data, sizeof(t_data));
}
