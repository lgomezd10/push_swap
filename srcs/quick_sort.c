#include "../includes/algorithms.h"

static void perform_move(t_data *data, int chunk, int size)
{
	int nbr;
	while (has_elements_of_chunk(data, chunk, size) && !a_is_sorted(data))
	{
		nbr = get_max_of_chunk(data, chunk, size);
		if (data->stack_a.start->pos_ord <= nbr)
		{
			push_b(data);
			nbr = get_middle_of_chunk(data, chunk, size);
			if (data->stack_b.start->pos_ord <= nbr)
			{
				nbr = get_max_of_chunk(data, chunk, size);
				if (data->stack_a.size > 1 && data->stack_a.start->pos_ord > nbr)
					rotate_both(data);
				else
					rotate_b(data);
			}
		}
		else
			rotate_a(data);
	}
}

static void perform_sort(t_data *data, int size_div)
{
	int chunk;
	int nbr;

	chunk = 0;
	while (!a_is_sorted(data) && data->stack_a.size > 0)
	{
		perform_move(data, chunk, size_div);
		chunk++;
	}
	move_down_a(data, data->stack_a.bigger);
	while (data->stack_b.size)
		selection_sort_b(data);
}

void quick_sort(t_data *data, t_solution *solution, int i)
{
	int size;
	int	size_stack;
	int max;

	size = 10;
	max = 100;	
	size_stack = data->sorted->size;
	if (size_stack > 1000)
	{
		size = (size_stack / 10) / 2;
		max += size / 2;
	}
	if (size_stack < 2000)
	{
		perform_sort(data, 10);
		save_and_restart(data, solution, i);
		size += 10;
		while (size <= size_stack && size < max)
		{
			load_stack(data, *solution);
			perform_sort(data, size);
			size += 5;
			i++;
			save_and_restart(data, solution, i);
		}
	}
}