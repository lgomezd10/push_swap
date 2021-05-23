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

void load_stack(t_data *data)
{
    t_list *list;
    int nbr;
    int i;

    i = 1;
    while (i < data->argc)
    {
        if (ft_str_is_nbr(data->argv[i]))
        {
            nbr = ft_atoi(data->argv[i]);
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

    data.argc = argc;
    data.argv = argv;
    load_stack(&data);
    print_stack(&data.stack_a, 'A');
    print_stack(&data.stack_b, 'A');
    
}