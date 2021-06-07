/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-d <lgomez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:05:24 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/06/07 16:06:36 by lgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char *operation_str(int nbr)
{
	char *str;

	str = 0;
	if (nbr == Op_sa)
		str = ft_strdup("sa");
	if (nbr == Op_sb)
		str = ft_strdup("sb");
	if (nbr == Op_ss)
		str = ft_strdup("ss");
	if (nbr == Op_pa)
		str = ft_strdup("pa");
	if (nbr == Op_pb)
		str = ft_strdup("pb");
	if (nbr == Op_ra)
		str = ft_strdup("ra");
	if (nbr == Op_rb)
		str = ft_strdup("rb");
	if (nbr == Op_rr)
		str = ft_strdup("rr");
	if (nbr == Op_rra)
		str = ft_strdup("rra");
	if (nbr == Op_rrb)
		str = ft_strdup("rrb");
	if (nbr == Op_rrr)
		str = ft_strdup("rrr");
	return (str);
}

void print_solution(t_lst_st *list)
{
	char *str;

	while (list)
	{
		str = operation_str(list->nbr);
		if (str)
			ft_putendl_fd(str, 1);
		free(str);
		list = list->next;
	}    
}

void load_functions(t_function **array_f)
{
	int			i;
	t_function	*array;

	array = (t_function *)ft_calloc(sizeof(t_function), 20);
	if (!array)
		show_error();
	i = 0;	
	
	array[i++] = bubble_sort;  //0
	array[i++] = bubble_sort_div;  //1
	array[i++] = selection_sort; //2
	array[i++] = insertion_sort; //3
	array[i++] = merge_a_insert_sort; //4
	array[i++] = merge_a_select_sort; //5
	array[i++] = merge_a_insert_select_sort; //6
	array[i++] = merge_sort; //7
	array[i++] = randix_sort; //8	
	*array_f = array;
}

int	main(int argc, char **argv)
{
	int			i;
	t_data		data;
	t_solution	solution;
	t_function	*array_f;
	char		**numbers;
	
	if (argc == 2)
		numbers = ft_split(argv[1], ' ');
	else
		numbers = argv;
	if (argc > 1)
	{
		load_functions(&array_f);
		ft_bzero(&solution, sizeof(t_solution));
		ft_bzero(&data, sizeof(t_data));
		solution.argc = argc;
		solution.argv = numbers;
		i = 0;
		load_stack(&data, solution);
		if (!is_all_sorted(&data))
		{
			while (array_f[i] != 0)
			{
				if (array_f[i] == randix_sort || data.sorted->size < 300)
				{
					array_f[i](&data);
						/*
					printf("Despues de ejecutar la funcion %d\n", i);
					print_stack(&data.stack_a, 'A');
					print_stack(&data.stack_b, 'B');     
					*/
					//print_stack(&data.operations, 'O');
					//printf("solucion ordenada: %d en %d movimientos\n", is_all_sorted(&data), data.operations.size);
					
									
					save_and_restart(&data, &solution, i);
					load_stack(&data, solution);
						
						/*
						printf("Solucion seleccionada\n");
						print_stack(&solution, 'S');	*/
				}
				i++;
			}
			quick_sort(&data, &solution, i);
		}
		print_solution(solution.solution.start);
		
		//printf("Solucion seleccionada por funcion %d veces: %d\n", solution.solution.func, solution.solution.size);
		//print_stack(&solution, 'S');
	}
	return (0);
}