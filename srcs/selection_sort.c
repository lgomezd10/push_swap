#include "../includes/push_swap.h"

void insertion_sort(t_data *data)
{
	while (!is_sort_increasing(data->stack_a.start) && data->stack_a.size > 0)
	{
		push_b(data);
		bubble_sort_b(data);
	}
	while (data->stack_b.size > 0)
		push_a(data);	
}

void selection_sort(t_data *data)
{
	int nbr;
	
	while (!is_sort_increasing(data->stack_a.start) && data->stack_a.size > 0)
	{
		nbr = data->stack_a.smaller;
		move_up(data, nbr);
		push_b(data);
	}
	while (data->stack_b.size > 0)
		push_a(data);    
}