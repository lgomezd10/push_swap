/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randix_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-d <lgomez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 16:53:51 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/06/02 16:53:53 by lgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	randix_sort(t_data *data)
{
	int	max_num;
	int	max_bits;
	int	i;
	int	count;
	int	pos;

	max_num = data->sorted->size - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	i = -1;
	while (++i < max_bits && !is_all_sorted(data))
	{
		count = -1;
		while (++count < data->sorted->size)
		{
			pos = data->stack_a.start->pos_ord;
			if (((pos >> i) & 1) == 1)
				rotate_a(data);
			else
				push_b(data);
		}
		while (data->stack_b.size > 0)
			push_a(data);
	}
}
