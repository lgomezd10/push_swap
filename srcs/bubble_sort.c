/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-d <lgomez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 19:28:27 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/06/03 18:29:25 by lgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_head(t_data *data)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			need_rota;
	int			need_rotb;

	need_rota = 0;
	need_rotb = 0;
	stack_a = &data->stack_a;
	stack_b = &data->stack_b;
	if (stack_a->size > 2 && stack_a->start->nbr == stack_a->bigger)
	{
		if (stack_a->start->next->nbr == stack_a->smaller)
			need_rota = 1;
	}
	if (stack_b->size > 2 && stack_b->start->nbr == stack_b->smaller)
	{
		if (stack_b->start->next->nbr == stack_b->smaller)
			need_rotb = 1;
	}
	if (need_rota && need_rotb)
		rotate_both(data);
	else if (!need_rota && need_rotb)
		rotate_b(data);
	else if (need_rota && !need_rotb)
		rotate_a(data);
}

void	bubble_sort_div(t_data *data)
{
	t_stack		*stack;

	stack = &data->stack_a;
	divide_a(data);
	while (!a_is_sorted(data) || !b_is_sorted(data))
	{
		check_head(data);
		if (needed_swap_a(data) && needed_swap_b(data))
			swap_both(data);
		else if (!needed_swap_a(data) && needed_swap_b(data))
			swap_b(data);
		else if (needed_swap_a(data) && !needed_swap_b(data))
			swap_a(data);
		if (!a_is_sorted(data) && !b_is_sorted(data))
			rotate_both(data);
		else if (a_is_sorted(data) && !b_is_sorted(data))
			rotate_b(data);
		else if (!a_is_sorted(data) && b_is_sorted(data))
			rotate_a(data);
	}
	move_up_b(data, data->stack_b.bigger);
	move_up_a(data, stack->smaller);
	while (data->stack_b.size)
		push_a(data);
	
}

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
