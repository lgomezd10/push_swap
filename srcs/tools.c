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

/*

int get_middle(t_stack *stack)
{
    int i;
    int nbr;
    int smaller;
    int *numbers;
    t_lst_st *temp;

    temp = stack->start;
    numbers = ft_calloc(sizeof(int), stack->size);
    i = 0;
    while (i < stack->size && temp)
    {
        numbers[i] = temp->nbr;
        printf("se ha guarddo %d\n", numbers[i]);
        temp = temp->next;
        i++;
    }
    
    nbr = numbers[i / 2];
    printf("se devuelve %d\n", nbr);
    return (nbr);
}
*/