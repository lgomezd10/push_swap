/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-d <lgomez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 18:44:49 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/05/26 18:45:27 by lgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/push_swap.h"

int	find_prev_a(t_stack stack, int nbr)
{
	t_array *sorted;
	int i;
	int prev;

	sorted = get_array_sorted(stack);
	i = sorted->size;
	while (--i)
	{
		if (nbr > sorted->array[i])
		{
			prev = sorted->array[i + 1];
			free(sorted->array);
			free(sorted);
			return(prev);
		}
	}
	return (0);
}

int	find_prev_b(t_stack stack, int nbr)
{
	t_array *sorted;
	int i;
	int prev;

	sorted = get_array_sorted(stack);
	i = 0;
	while (i < sorted->size)
	{
		if (nbr < sorted->array[i])
		{
			prev = sorted->array[i - 1];
			free(sorted->array);
			free(sorted);
			return(prev);
		}
		i++;
	}
	return (0);
}

void insertion_a_to_b(t_data *data)
{
	
	int nbr;
	t_stack *stack_a;
	t_stack *stack_b;
	int prev;

	stack_a = &data->stack_a;
	stack_b = &data->stack_b;
	nbr = stack_a->start->nbr;		
	if (nbr > data->stack_b.bigger || nbr < stack_b->smaller)
		move_up_b(data, stack_b->bigger);
	else
	{
		prev = find_prev_b(*stack_b, nbr);
		move_up_b(data, prev);
	}	
	push_b(data);
}

void insertion_sort(t_data *data)
{
	
	int nbr;
	t_stack *stack_a;
	t_stack *stack_b;
	int prev;

	stack_a = &data->stack_a;
	stack_b = &data->stack_b;
	while (stack_a->size > 0)
	{
		nbr = stack_a->start->nbr;		
		if (nbr > data->stack_b.bigger || nbr < stack_b->smaller)
			move_up_b(data, stack_b->bigger);
		else
		{
			prev = find_prev_b(*stack_b, nbr);
			move_up_b(data, prev);
		}	
		push_b(data);
	}
	move_up_b(data, stack_b->bigger);
	while (data->stack_b.size > 0)
		push_a(data);
}

void selection_sort(t_data *data)
{
	int nbr;
	
	while (!is_sort_increasing(data->stack_a.start) && data->stack_a.size > 0)
	{
		nbr = data->stack_a.smaller;
		move_up_a(data, nbr);
		push_b(data);
	}
	while (data->stack_b.size > 0)
		push_a(data);    
}