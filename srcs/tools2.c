/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-d <lgomez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:06:32 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/06/07 16:06:36 by lgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_sides(t_data *data)
{
	t_stack		*stack;

	stack = &data->stack_a;
	if (!stack->size)
		return (1);
	if (stack->bigger != data->sorted->array[data->sorted->size - 1])
		return (0);
	if (stack->end->nbr != stack->bigger)
	{
		if (stack->end->pos_ord + 1 != stack->start->pos_ord)
			return (0);
	}
	return (-1);
}

int	a_is_sorted(t_data *data)
{
	t_stack		*stack;
	t_lst_st	*temp;
	int			act;
	int			next;
	int			sorted;

	stack = &data->stack_a;
	temp = stack->start;
	sorted = check_sides(data);
	if (sorted > -1)
		return (sorted);
	while (temp && temp->next)
	{
		act = temp->pos_ord;
		next = temp->next->pos_ord;
		if (act + 1 != next)
		{
			next = temp->next->nbr;
			if (act != data->sorted->size - 1 || next != stack->smaller
				|| stack->size < 3)
				return (0);
		}
		temp = temp->next;
	}
	return (1);
}

int	b_is_sorted(t_data *data)
{
	t_stack		*stack;
	t_lst_st	*temp;
	int			act;
	int			next;

	stack = &data->stack_b;
	temp = stack->start;
	if (!stack->size)
		return (1);
	if (stack->end->nbr != stack->smaller
		&& stack->end->pos_ord != temp->pos_ord + 1)
		return (0);
	while (temp && temp->next)
	{
		act = temp->pos_ord;
		next = temp->next->pos_ord;
		if (act != next + 1)
		{
			next = temp->next->nbr;
			if (act != 0 || next != stack->bigger || stack->size < 3)
				return (0);
		}
		temp = temp->next;
	}
	return (1);
}
