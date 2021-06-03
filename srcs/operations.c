/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-d <lgomez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 16:47:30 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/06/03 20:10:11 by lgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/operations.h"

void	swap_stack(t_stack *stack)
{
	t_lst_st	*temp;

	if (stack->start && stack->start->next)
	{
		temp = stack->start->next;
		remove_element(stack, temp);
		add_element_front(stack, temp);
	}
}

void	move_of_stack(t_stack *src, t_stack *dest)
{
	t_lst_st	*temp;

	if (src->start)
	{
		temp = src->start;
		remove_element(src, temp);
		add_element_front(dest, temp);
	}
}

void	rotate_stack(t_stack *stack)
{
	t_lst_st	*temp;

	if (stack->start && stack->start->next)
	{
		temp = stack->start;
		remove_element(stack, temp);
		add_element_back(stack, temp);
	}
}

void	rotate_reverse_stack(t_stack *stack)
{
	t_lst_st	*temp;

	if (stack->start && stack->start->next)
	{
		temp = stack->end;
		remove_element(stack, temp);
		add_element_front(stack, temp);
	}
}
