#include "../includes/algorithms.h"

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

int get_size3(t_data *data)
{
	int size;

	if (data->sorted->size > 400)
		size = 70;
	else if(data->sorted->size >= 40)
		size = data->sorted->size / 5;
	else
		size = 20;
	return (size);
}

void divition_sort(t_data *data, int size_div)
{
	int chunk;

	chunk = 0;
	//size_div = get_size(data);
	while (!a_is_sorted(data) && data->stack_a.size > 0)
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
	}/*
	printf("antes de mover\n");
	print_stack(&data->stack_a, 'a');
	print_stack(&data->stack_b, 'b');
	*/
	move_down_a(data, data->stack_a.bigger);
	
	while (data->stack_b.size)
		selection_sort_b(data);
}

void divition_func_2(t_data *data, t_solution *solution, int i)
{
	int size = 40;
	divition_sort(data, size);
	printf("solucion size: %d ordenada: %d en %d movimientos\n", size, is_all_sorted(data), data->operations.size);
	save_and_restart(data, solution, i);
}

void divition_func(t_data *data, t_solution *solution, int i)
{
	int size;
	int	size_stack;

	size = 10;
	size_stack = data->sorted->size;
	divition_sort(data, 10);
	//printf("solucion size: %d ordenada: %d en %d movimientos\n", size, is_all_sorted(data), data->operations.size);
	save_and_restart(data, solution, i);
	size += 10;
	while (size < 100 && size <= size_stack)
	{
		load_stack(data, *solution);
		divition_sort(data, size);
		//printf("solucion size: %d ordenada: %d en %d movimientos\n", size, is_all_sorted(data), data->operations.size);
		size += 5;
		i++;
		save_and_restart(data, solution, i);
	}
}