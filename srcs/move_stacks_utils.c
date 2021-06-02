/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stacks_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-d <lgomez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 16:42:24 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/06/02 16:43:59 by lgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_all(t_data *data, int from, int to, void (*rot)(t_data *))
{
	int	i;

	i = from;
	while (i < to)
	{
		rot(data);
		i++;
	}
}

void	move_up_a(t_data *data, int nbr)
{
	int			found;
	int			pos;
	t_lst_st	*temp;

	pos = 0;
	found = 0;
	temp = data->stack_a.start;
	while (!found && temp)
	{
		if (temp->nbr == nbr)
		{
			if (pos > data->stack_a.size / 2)
				rotate_all(data, pos, data->stack_a.size, reverse_rotate_a);
			else
				rotate_all(data, 0, pos, rotate_a);
			found = 1;
		}
		pos++;
		temp = temp->next;
	}
}

void move_up_b(t_data *data, int nbr)
{
	int			found;
	int			pos;
	t_lst_st	*temp;

	pos = 0;
	found = 0;
	temp = data->stack_b.start;
	while (!found && temp)
	{
		if (temp->nbr == nbr)
		{
			if (pos > data->stack_b.size / 2)
				rotate_all(data, pos, data->stack_b.size, reverse_rotate_b);
			else
				rotate_all(data, 0, pos, rotate_b);
			found = 1;
		}
		pos++;
		temp = temp->next;
	}
}

void	move_down_a(t_data *data, int nbr)
{
	int			found;
	int			pos;
	t_lst_st	*temp;

	pos = 0;
	found = 0;
	temp = data->stack_a.start;
	while (!found && temp)
	{
		if (temp->nbr == nbr)
		{
			if (pos > data->stack_a.size / 2)
				rotate_all(data, pos, data->stack_a.size - 1, reverse_rotate_a);
			else
				rotate_all(data, 0, pos + 1, rotate_a);
			found = 1;
		}
		pos++;
		temp = temp->next;
	}
}

void	move_down_b(t_data *data, int nbr)
{
	int			found;
	int			pos;
	t_lst_st	*temp;

	pos = 0;
	found = 0;
	temp = data->stack_b.start;
	while (!found && temp)
	{
		if (temp->nbr == nbr)
		{
			if (pos > data->stack_b.size / 2)
				rotate_all(data, pos, data->stack_b.size - 1, reverse_rotate_b);
			else
				rotate_all(data, 0, pos + 1, rotate_b);
			found = 1;
		}
		pos++;
		temp = temp->next;
	}
}