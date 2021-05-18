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

int is_sort_decreasing(t_lst_st *list)
{
    t_lst_st *temp;

    temp = list;
    while (temp && temp->next)
    {
        if (temp->nbr < temp->next->nbr)
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

int get_middle(t_stack *stack)
{
    int *values;
    int value;
    int i;
    t_lst_st *temp;

    values = (int *)ft_calloc(sizeof(int), stack->size);
    printf("el tamaño del array %d\n", stack->size);
    if (!values)
        show_error();
    i = 0;
    while (temp && i < stack->size)
    {
        printf("en el while %d\n", i);
        values[i] = temp->nbr;
        printf("antes de pasar %d\n", i);
        temp = temp->next;
        i++;
        printf("añadido el valor %d en interaccion %d\n", values[i], i);
    }
    value = values[i / 2];
    free(values);
    return (value);
}
