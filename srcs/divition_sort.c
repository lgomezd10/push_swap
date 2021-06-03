#include "../includes/push_swap.h"



int get_size1(t_data *data)
{
	int size;

	if (data->sorted->size > 400)
		size = 60;
	else if(data->sorted->size >= 40)
		size = data->sorted->size / 5;
	else
		size = 20;
	return (size);
}

int get_size2(t_data *data)
{
	int size;

	if (data->sorted->size > 400)
		size = 50;
	else if(data->sorted->size >= 40)
		size = data->sorted->size / 5;
	else
		size = 20;
	return (size);
}

void divition_sort(t_data *data, int (*get_size)(t_data *))
{
	int chunk;
	int size_div;

	chunk = 0;
	size_div = get_size(data);
	while (!a_is_sorted(data) && data->stack_a.size > 1)
	{
		while (has_elements_of_chunk(data, chunk, size_div) && !a_is_sorted(data))
		{
			if (data->stack_a.start->pos_ord <= get_max_of_chunk(data, chunk, size_div))
			{
				push_b(data);
				if (data->stack_b.start->pos_ord <= get_middle_of_chunk(data, chunk, size_div))
				{
					if (data->stack_a.size > 1 && data->stack_a.start->pos_ord > get_max_of_chunk(data, chunk, size_div))
						rotate_both(data);
					else
						rotate_b(data);
				}
			}
			else
				rotate_a(data);
		}
		chunk++;
	}
	move_down_a(data, data->stack_a.bigger);
	while (data->stack_b.size)
		selection_sort_b(data);
}

void divition_sort1(t_data *data)
{
	divition_sort(data, get_size1);
}

void divition_sort2(t_data *data)
{
	divition_sort(data, get_size2);
}