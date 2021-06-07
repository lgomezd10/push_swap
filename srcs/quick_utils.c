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
		if (temp->pos_ord <= get_max_of_chunk(data, chunk, size))
			return (1);
		temp = temp->next;
	}
	return (0);
}