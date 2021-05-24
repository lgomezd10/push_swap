#include "../includes/push_swap.h"

/*
void add_new_nbr(t_list *list, int nbr)
{
    int *number;

    nbr = (int *)malloc(sizeof(int));
    *number = nbr;
    ft_lstadd_back(list, ft_lstnew(number));
}
*/

void load_stack(t_data *data, int argc, char **argv)
{
    t_list *list;
    int nbr;
    int i;

    i = 1;
    while (i < argc)
    {
        if (ft_str_is_nbr(argv[i]))
        {
            nbr = ft_atoi(argv[i]);
            add_new_back(&data->stack_a, nbr);
        }
        else
        {
            show_error();
        }
        i++;
    }
}

void load_functions(t_function **array_f)
{
    int i;
    t_function *array;

    array = (t_function *)ft_calloc(sizeof(t_function), 6);
    if (!array)
        show_error();
    i = 0;
    array[i++] = bubble_sort_a;
    array[i++] = selection_sort;
    array[i++] = bubble_sort_2;
    array[i++] = merge_short;
    array[i++] = merge_select_short;
    *array_f = array;
}

int main(int argc, char **argv)
{
    int i;
    t_data data;
    t_stack solution;
    t_function *array_f;

    i = 0;
    printf("entrando: argumentos: %d\n", argc);
    while (i < argc)
    {
        printf("argumento: %s\n", argv[i]);
        i++;
    }
    
    load_functions(&array_f);
    ft_bzero(&solution, sizeof(t_stack));
    ft_bzero(&data, sizeof(t_data));

    i = 0;
    while (array_f[i] != 0)
    {
        load_stack(&data, argc, argv);
        array_f[i](&data);
        printf("Despues de ejecutar la funcion %d\n", i);
        print_stack(&data.stack_a, 'A');
        print_stack(&data.stack_b, 'B');
        print_stack(&data.operations, 'O');
        save_and_restart(&data, &solution);
        printf("Solucion seleccionada\n");
        print_stack(&solution, 'S');
        i++;
    }

    /*
    load_stack(&data, argc, argv);
    printf("Tras cargar datos\n");
    print_stack(&data.stack_a, 'A');
    print_stack(&data.stack_b, 'B');
    
    bubble_sort_a(&data);
    printf("Despues de buble sort\n");
    print_stack(&data.stack_a, 'A');
    print_stack(&data.stack_b, 'B');
    print_stack(&data.operations, 'O');
    save_and_restart(&data, &solution);
    printf("Solucion seleccionada\n");
    print_stack(&solution, 'S');
    load_stack(&data, argc, argv);
    printf("Tras cargar datos\n");
    print_stack(&data.stack_a, 'A');
    print_stack(&data.stack_b, 'B');
    selection_sort(&data);
    printf("datos de selection sort\n");
    print_stack(&data.stack_a, 'A');
    print_stack(&data.stack_b, 'B');
    print_stack(&data.operations, 'O');
    save_and_restart(&data, &solution);
    printf("Solucion seleccionada\n");
    print_stack(&solution, 'S');
    system("leaks push_swap");
    */
}