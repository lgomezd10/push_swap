/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_versions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-d <lgomez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 16:41:34 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/06/03 18:37:40 by lgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	merge_ab_select_sort(t_data *data)
{
	merge_sort_a(data);
	merge_sort_b(data);
	selection_sort(data);
}

void	merge_ab_insert_sort(t_data *data)
{
	merge_sort_a(data);
	merge_sort_b(data);
	insertion_sort(data);
}

void	merge_a_insert_sort(t_data *data)
{
	merge_sort_a(data);
	while (data->stack_b.size)
		insertion_one_in_a(data);
	move_up_a(data, data->stack_a.smaller);
}

void	merge_a_select_sort(t_data *data)
{
	merge_sort_a(data);
	move_up_a(data, data->stack_a.smaller);
	selection_sort_b(data);
}

void	merge_a_insert_select_sort(t_data *data)
{
	merge_sort_a(data);
	while (data->stack_b.size > (data->sorted->size / 2) + 1)
		insertion_one_in_a(data);
	move_up_a(data, data->stack_a.smaller);
	selection_sort_b(data);
}
