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
	array[i++] = bubble_sort_div;  //0
	array[i++] = selection_sort; //1
	array[i++] = insertion_sort; //2
	array[i++] = merge_a_insert_sort; //5
	array[i++] = merge_a_select_sort; //6
	array[i++] = merge_a_insert_select_sort; //7
	array[i++] = merge_sort; //8
	array[i++] = randix_sort; //9	
	array[i++] = divition_sort1; //9
	array[i++] = divition_sort2; //9
	array[i++] = divition_sort3; //9
	
	*array_f = array;
}

int	main(int argc, char **argv)
{
	int			i;
	t_data		data;
	t_stack		solution;
	t_function	*array_f;
	char		**numbers;
	
	if (argc == 2)
		numbers = ft_split(argv[1], ' ');
	else
		numbers = argv;
	if (argc > 1)
	{
		load_functions(&array_f);
		ft_bzero(&solution, sizeof(t_stack));
		ft_bzero(&data, sizeof(t_data));
		i = 0;
		while (array_f[i] != 0)
		{
			load_stack(&data, argc, numbers);
			if (!is_all_sorted(&data))
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
					
					/*
					printf("Solucion seleccionada\n");
					print_stack(&solution, 'S');
					*/				
				i++;
			}
			else
				break;
			
		}
		print_solution(solution.start);
		
		//printf("Solucion seleccionada por funcion %d veces: %d\n", solution.func, solution.size);
		//print_stack(&solution, 'S');
	}
}