/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-d <lgomez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 16:38:42 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/06/03 20:55:01 by lgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/algorithms.h"

void	merge_sort_a(t_data *data)
{
	t_stack		*stack;
	t_lst_st	*temp;
	int			middle;
	int			size;

	stack = &data->stack_a;
	size = stack->size;
	if (!a_is_sorted(data))
	{
		middle = get_middle_temp(data, stack);
		temp = data->stack_a.start;
		while (temp && size-- && !a_is_sorted(data))
		{
			if (temp->nbr <= middle)
				push_b(data);
			else
				rotate_a(data);
			temp = data->stack_a.start;
		}
		sort_top(data);
		merge_sort_a(data);
	}
}

void	merge_sort_b(t_data *data)
{
	t_stack		*stack;
	t_lst_st	*temp;
	int			middle;
	int			size;

	stack = &data->stack_b;
	size = stack->size;
	if (stack->size > 1)
	{
		middle = get_middle_temp(data, stack);
		temp = data->stack_b.start;
		while (temp && size--)
		{
			if (temp->nbr >= middle)
				push_a(data);
			else
				rotate_b(data);
			temp = data->stack_b.start;
		}
		sort_top(data);
		merge_sort_b(data);
	}
	else
		push_a(data);
}

static void	return_to_a(t_data *data, int size)
{
	move_down_a(data, data->stack_a.bigger);
	while (data->stack_a.size < size)
	{
		push_a(data);
		sort_top(data);
	}
}

void	merge_sort(t_data *data)
{
	t_stack		*stack;
	t_lst_st	*temp;
	int			middle;
	int			size;

	stack = &data->stack_a;
	move_down_a(data, data->stack_a.bigger);
	find_min_sort(data);
	size = stack->size;
	while (find_min_sort(data) != stack->smaller)
	{
		middle = get_middle(data);
		temp = data->stack_a.start;
		while (temp && temp->nbr != data->min_sorted)
		{
			if (temp->nbr <= middle)
				push_b(data);
			else
				rotate_a(data);
			temp = data->stack_a.start;
		}
		merge_sort(data);
		return_to_a(data, size);
	}
}
