#include "../includes/push_swap.h"

int find_min_sort(t_data *data)
{
	int i;
	t_lst_st *temp;
	int			*sorted;

	sorted = data->sorted->array;
	i = 0;	
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

int get_middle(t_data *data)
{
    int i;
    int pos;
    int to_short;
    int middle;
    t_stack stack;

    if (data->sorted)
    {
        stack = data->stack_a;
        i = 0;
        pos = data->size - stack.size;
        to_short = (data->pos_min_sorted - pos);
        if (to_short == 2)
            to_short = 0;
        i = pos + (to_short / 2);
        return (data->sorted->array[i]);
    }
    return (0);
}