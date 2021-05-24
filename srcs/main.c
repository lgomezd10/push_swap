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
            show_error();
        i++;
    }
}


int main(int argc, char **argv)
{
    int i;
    t_data data;
    t_stack solution;


    ft_bzero(&solution, sizeof(t_stack));
    ft_bzero(&data, sizeof(t_data));
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
    
}