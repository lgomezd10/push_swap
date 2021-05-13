#include "../includes/push_swap.h"

void add_new_nbr(t_list *list, int nbr)
{
    int *number;

    nbr = (int *)malloc(sizeof(int));
    *number = nbr;
    ft_lstadd_back(list, ft_lstnew(number));
}

t_list *load_stack(int argc, char **argv)
{
    t_list *list;
    int nbr;
    int i;

    while (i < argc)
    {
        if (ft_str_is_nbr(argv[i]))
        {
            nbr = ft_atoi(argv[i]);
            add_new_nbr(list, nbr);
        }
        else
            show_error();
    }
    return (list);
}

int main(int argc, char **argv)
{
    int i;
    t_list *stack_a;
    t_list *stack_b;

    stack_a = load_stack(argc, argv);
    
}