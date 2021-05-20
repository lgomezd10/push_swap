#include "../includes/push_swap.h"

int find_min_sort_a(t_data *data)
{
	int i;
	t_lst_st *temp;
	int			*sorted;

	sorted = data->sorted;	i = 0;
	
	i = data->size - 1;
	temp = data->stack_a.end;
	
	while (i >= 0 && temp && temp->nbr == sorted[i])
	{
		data->min_sorted = temp->nbr;
		data->pos_min_sorted = i;
		i--;
		temp = temp->prev;
	}	
	return (data->min_sorted);
}

int find_min_sort_b(t_data *data)
{
	int i;
	t_lst_st *temp;
	int			*sorted;

	sorted = data->sorted;	i = 0;
	
	i = 0;
	temp = data->stack_a.end;
	
	while (i < data->size && temp && temp->nbr == sorted[i])
	{
		data->min_sorted = temp->nbr;
		data->pos_min_sorted = i;
		i--;
		temp = temp->prev;
	}	
	return (data->min_sorted);
}


int find_next_min(t_stack stack, int min)
{
    t_lst_st *temp;
    int next;

    temp = stack.start;
    next = stack.bigger;
    if (min < next)
    {
        while (temp)
        {
            if (temp->nbr > min && temp->nbr < next)
                next = temp->nbr;
            temp = temp->next;
        }
        return (next);
    }
    else
        return (min);
}

void sort_array(t_data *data)
{
    int *sorted;
    t_stack stack;
    int i;

    stack = data->stack_a;
    data->size = stack.size;
    sorted = (int *)ft_calloc(sizeof(int), data->size);
    if (!sorted)
        show_error();
    i = 0;
    sorted[i] = stack.smaller;
    while (++i < stack.size)
        sorted[i] = find_next_min(stack, sorted[i - 1]);
    data->sorted = sorted;
}
/*
void sort_array_b(t_data *data)
{
    int *sorted;
    t_stack stack;
    int i;

    stack = data->stack_b;
    data->size = stack.size;
    sorted = (int *)ft_calloc(sizeof(int), stack.size);
    if (!sorted)
        show_error();
    i = 0;
    sorted[i] = stack.smaller;
    while (++i < stack.size)
        sorted[i] = find_next_min(stack, sorted[i - 1]);
    data->sorted = sorted;
}*/