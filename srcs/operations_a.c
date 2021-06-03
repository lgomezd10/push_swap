/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-d <lgomez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 16:44:29 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/06/03 20:09:42 by lgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/operations.h"

void	swap_a(t_data *data)
{
	t_stack	*stack;
	t_stack	*operations;

	stack = &data->stack_a;
	if (stack->size > 1)
	{
		operations = &data->operations;
		swap_stack(stack);
		add_new_back(operations, Op_sa);
	}
}

void	push_a(t_data *data)
{
	t_stack	*stack;
	t_stack	*operations;

	stack = &data->stack_a;
	if (data->stack_b.size)
	{
		operations = &data->operations;
		move_of_stack(&data->stack_b, &data->stack_a);
		add_new_back(operations, Op_pa);
	}
}

void	rotate_a(t_data *data)
{
	t_stack	*stack;
	t_stack	*operations;

	stack = &data->stack_a;
	if (stack->size > 1)
	{
		operations = &data->operations;
		rotate_stack(stack);
		add_new_back(operations, Op_ra);
	}
}

void	reverse_rotate_a(t_data *data)
{
	t_stack	*stack;
	t_stack	*operations;

	stack = &data->stack_a;
	if (stack->size > 1)
	{
		operations = &data->operations;
		rotate_reverse_stack(stack);
		add_new_back(operations, Op_rra);
	}
}
