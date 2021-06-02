/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-d <lgomez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 19:28:27 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/05/31 19:44:46 by lgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	bubble_sort(t_data *data)
{
	t_lst_st	*temp;
	t_stack		*stack;
	
	stack = &data->stack_a;
	temp = stack->start;
	while (!a_is_sorted(data) && temp && temp->next && !is_all_sorted(data))
	{
		if (temp->nbr == stack->smaller && temp->next->nbr == stack->bigger)
			swap_a(data);
		else if (temp->nbr > temp->next->nbr)
		{
			if (temp->nbr != stack->bigger || temp->next->nbr != stack->smaller)
				swap_a(data);
		}
		if (!a_is_sorted(data))
			rotate_a(data);
		temp = stack->start;
	}
	move_down_a(data, stack->bigger);
}