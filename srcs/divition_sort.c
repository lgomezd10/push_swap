#include "../includes/push_swap.h"

int get_middle_of_chunk(t_data *data, int chunk, int size)
{
	return (size * chunk + (size / 2));
}

int get_max_of_chunk(t_data *data, int chunk, int size)
{
	return (size * chunk + size);
}

int has_elements_of_chunk(t_data *data, int chunk, int size)
{
	t_lst_st *temp;

	temp = data->stack_a.start;
	while (temp)
	{
		if (temp->pos_ord < get_max_of_chunk(data, chunk, size))
			return (1);
		temp = temp->next;
	}
	return (0);
}

int get_size (t_data *data)
{
	int size;

	if (data->sorted->size > 400)
		size = 50;
	else
		size = data->sorted->size / 5;
	return (size);
}

void try_swap(t_data *data)
{
	int swap_a;
	int swap_b;
	t_stack *stack_a;
	t_stack *stack_b;
	t_lst_st *temp;

	stack_a = &data->stack_a;
	stack_b = &data->stack_b;
	swap_a = 0;
	swap_b = 0;
	if (stack_a->size > 1)
	{
		temp = stack_a->start;
		if (temp->pos_ord > temp->next->pos_ord)
			swap_a = 1;
	}
	if (stack_b->size > 1)
	{
		temp = stack_b->start;
		if (temp->pos_ord < temp->next->pos_ord)
			swap_b = 1;
	}
	if (swap_a && swap_b)
		swap_both(data);
}

void divition_sort(t_data *data)
{
	int chunk;
	int size_div;

	chunk = 0;
	size_div = 50;
	while (!a_is_sorted(data) && data->stack_a.size > 2)
	{
		//printf("antes\n");
		//printf("chunk %d max_chunk %d middle chunk %d\n", chunk, get_max_of_chunk(data, chunk, size_div), get_middle_of_chunk(data, chunk, size_div));
		while (has_elements_of_chunk(data, chunk, size_div) && !a_is_sorted(data))
		{
			//print_stack(&data->stack_a, 'a');
			//print_stack(&data->stack_a, 'a');
			if (data->stack_a.start->pos_ord < get_max_of_chunk(data, chunk, size_div))
			{
				push_b(data);
				if (data->stack_b.start->pos_ord < get_middle_of_chunk(data, chunk, size_div))
					rotate_b(data);
				/*
				if (data->stack_b.start->pos_ord < get_middle_of_chunk(data, chunk, size_div))
				{
					if (data->stack_a.start->pos_ord >= get_max_of_chunk(data, chunk, size_div))
						rotate_both(data);
					else
						rotate_b(data);
				}*/
			}
			else
				rotate_a(data);
			//try_swap(data);
		}
		chunk++;
	}
	move_down_a(data, data->stack_a.bigger);
	printf("antes de ordenar\n");
	print_stack(&data->stack_a, 'a');
	while (data->stack_b.size)
	{
		selection_sort_b(data);
	}
	
}