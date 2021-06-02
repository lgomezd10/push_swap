/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-d <lgomez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 17:15:27 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/06/02 17:23:11 by lgomez-d         ###   ########.fr       */
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
	while (temp && temp->next)
	{
		act = temp->pos_ord;
		next = temp->next->pos_ord;
		if (act + 1 != next)
		{
			next = temp->next->nbr;
			if (act != data->sorted->size - 1 || next != stack->smaller)
				return (0);
		}
		temp = temp->next;
	}
	return (1);
}

int	b_is_sorted(t_data *data)
{
	int			i;
	t_lst_st	*temp;
	int			act;
	int			next;

	temp = data->stack_b.start;
	while (temp && temp->next)
	{
		act = temp->pos_ord;
		next = temp->next->pos_ord;
		if (act != next + 1)
		{
			if (act != 0 || temp->next->nbr != data->stack_b.bigger)
				return (0);
		}
		temp = temp->next;
	}
	return (1);
}

