/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-d <lgomez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:06:11 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/06/07 16:06:36 by lgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_middle_of_chunk(int chunk, int size)
{
	return (size * chunk + (size / 2));
}

int	get_max_of_chunk(int chunk, int size)
{
	return (size * chunk + size);
}

int	has_elements_of_chunk(t_data *data, int chunk, int size)
{
	t_lst_st	*temp;

	temp = data->stack_a.start;
	while (temp)
	{
		if (temp->pos_ord <= get_max_of_chunk(chunk, size))
			return (1);
		temp = temp->next;
	}
	return (0);
}
