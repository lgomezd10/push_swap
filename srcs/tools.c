/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-d <lgomez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 17:15:27 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/06/03 20:53:09 by lgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_all_sorted(t_data *data)
{
	int			i;
	t_lst_st	*temp;

	temp = data->stack_a.start;
	i = 0;
	while (temp)
	{
		if (temp->pos_ord != i)
			return (0);
		temp = temp->next;
		i++;
	}
	return (1);
}

int	a_is_sorted(t_data *data)
{
	int			i;
	t_stack		*stack;
	t_lst_st	*temp;
	int			act;
	int			next;

	stack = &data->stack_a;
	temp = stack->start;
	if (stack->bigger != data->sorted->array[data->sorted->size - 1])
		return (0);
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
	int			i;
	t_stack		*stack;
	t_lst_st	*temp;
	int			act;
	int			next;

	stack = &data->stack_b;
	temp = stack->start;
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

int	needed_swap_a(t_data *data)
{
	int			needed;
	t_lst_st	*temp;

	if (data->stack_a.size > 1)
	{
		temp = data->stack_a.start;
		if (temp->pos_ord > temp->next->pos_ord)
			return (1);
	}
	return (0);
}

int	needed_swap_b(t_data *data)
{
	int			needed;
	t_lst_st	*temp;

	if (data->stack_b.size > 1)
	{
		temp = data->stack_b.start;
		if (temp->pos_ord < temp->next->pos_ord)
			return (1);
	}
	return (0);
}
