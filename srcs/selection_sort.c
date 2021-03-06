/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-d <lgomez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 18:44:49 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/06/03 20:45:15 by lgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/algorithms.h"

static int	get_pos(t_stack *stack, int nbr)
{
	t_lst_st	*temp;

	temp = stack->start;
	while (temp)
	{
		if (temp->nbr == nbr)
			return (temp->pos_ord);
		temp = temp->next;
	}
	return (-1);
}

static void	push_and_swap(t_data *data)
{
	int		nbr;

	push_a(data);
	nbr = data->stack_b.bigger;
	move_up_b(data, nbr);
	push_a(data);
	if (needed_swap_b(data) && needed_swap_a(data))
		swap_both(data);
	else if (needed_swap_a(data))
		swap_a(data);
}

void	selection_sort_a(t_data *data)
{
	int	nbr;

	while (data->stack_a.size > 0)
	{
		nbr = data->stack_a.bigger;
		move_up_a(data, nbr);
		push_b(data);
	}
}

void	selection_sort_b(t_data *data)
{
	int		nbr;
	t_stack	*stack;

	stack = &data->stack_b;
	while (data->stack_b.size > 0)
	{
		if (stack->size > 1
			&& stack->start->pos_ord + 1 == get_pos(stack, stack->bigger))
			push_and_swap(data);
		else if (stack->size > 1 && get_pos(stack, stack->bigger) > 1
			&& stack->end->pos_ord + 1 == get_pos(stack, stack->bigger))
		{
			reverse_rotate_b(data);
			push_and_swap(data);
		}
		else
		{
			nbr = data->stack_b.bigger;
			move_up_b(data, nbr);
			push_a(data);
		}
	}
}

void	selection_sort(t_data *data)
{
	int	nbr;

	while (!a_is_sorted(data) && data->stack_a.size > 0)
	{
		nbr = data->stack_a.smaller;
		move_up_a(data, nbr);
		push_b(data);
	}
	move_down_a(data, data->stack_a.bigger);
	while (data->stack_b.size > 0)
		push_a(data);
}
