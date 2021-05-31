#include "../includes/push_swap.h"

void load_stack(t_data *data, int argc, char **argv)
{
    t_list *list;
    int nbr;
    int i;

    i = 1;
    if (argc == 2)
    {
        argc = 0;
        while (argv[argc])
            argc++;
        i = 0;
    }
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
    data->stack_a.name = 'a';
    data->stack_b.name = 'b';
    sort_array(data);
}