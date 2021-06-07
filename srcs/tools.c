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

int	needed_swap_a(t_data *data)
{
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
	t_lst_st	*temp;

	if (data->stack_b.size > 1)
	{
		temp = data->stack_b.start;
		if (temp->pos_ord < temp->next->pos_ord)
			return (1);
	}
	return (0);
}
