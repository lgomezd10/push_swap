/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-d <lgomez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:05:24 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/06/07 19:22:34 by lgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static char	*operation_str(int nbr)
{
	if (nbr == Op_sa)
		return (ft_strdup("sa"));
	if (nbr == Op_sb)
		return (ft_strdup("sb"));
	if (nbr == Op_ss)
		return (ft_strdup("ss"));
	if (nbr == Op_pa)
		return (ft_strdup("pa"));
	if (nbr == Op_pb)
		return (ft_strdup("pb"));
	if (nbr == Op_ra)
		return (ft_strdup("ra"));
	if (nbr == Op_rb)
		return (ft_strdup("rb"));
	if (nbr == Op_rr)
		return (ft_strdup("rr"));
	if (nbr == Op_rra)
		return (ft_strdup("rra"));
	if (nbr == Op_rrb)
		return (ft_strdup("rrb"));
	if (nbr == Op_rrr)
		return (ft_strdup("rrr"));
	return (0);
}

static void	print_solution(t_lst_st *list)
{
	char	*str;

	while (list)
	{
		str = operation_str(list->nbr);
		if (str)
			ft_putendl_fd(str, 1);
		free(str);
		list = list->next;
	}
}

static void	load_functions(t_function **array_f)
{
	int			i;
	t_function	*array;

	array = (t_function *)ft_calloc(sizeof(t_function), 20);
	if (!array)
		show_error();
	i = 0;
	array[i++] = bubble_sort;
	array[i++] = bubble_sort_div;
	array[i++] = selection_sort;
	array[i++] = insertion_sort;
	array[i++] = merge_a_insert_sort;
	array[i++] = merge_a_select_sort;
	array[i++] = merge_a_insert_select_sort;
	array[i++] = merge_sort;
	array[i++] = randix_sort;
	*array_f = array;
}

static void	run_functions(t_data *data, t_solution *solution)
{
	t_function	*array_f;
	int			i;

	i = 0;
	load_functions(&array_f);
	if (!is_all_sorted(data))
	{
		while (array_f[i] != 0)
		{
			if (array_f[i] == randix_sort || data->sorted->size < 300)
			{
				array_f[i](data);
				/*
					printf("Despues de ejecutar la funcion %d\n", i);
					print_stack(&data.stack_a, 'A');
					print_stack(&data.stack_b, 'B');     
					*/
					//print_stack(&data.operations, 'O');
					//printf("solucion ordenada: %d en %d movimientos\n", is_all_sorted(&data), data.operations.size);
				save_and_restart(data, solution, i);
				load_stack(data, *solution);
			}
			i++;
		}
		quick_sort(data, solution, i);
		free(array_f);
	}
}

int	main(int argc, char **argv)
{
	t_data		data;
	t_solution	solution;
	char		**numbers;

	if (argc == 2)
		numbers = ft_split(argv[1], ' ');
	else
		numbers = argv;
	if (argc > 1)
	{
		ft_bzero(&solution, sizeof(t_solution));
		ft_bzero(&data, sizeof(t_data));
		solution.argc = argc;
		solution.argv = numbers;
		load_stack(&data, solution);
		run_functions(&data, &solution);
		print_solution(solution.solution.start);
	}
	//printf("Solucion seleccionada por funcion %d veces: %d\n", solution.solution.func, solution.solution.size);
		//print_stack(&solution, 'S');
	return (0);
}
