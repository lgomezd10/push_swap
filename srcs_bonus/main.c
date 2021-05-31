#include "../includes/bonus.h"

void run_operation(t_data *data, char *str)
{
    if (!ft_strncmp(str, "sa", 4))
        swap_a(data);
    if (!ft_strncmp(str, "sb", 4))
        swap_b(data);
    if (!ft_strncmp(str, "ss", 4))
        swap_both(data);
    if (!ft_strncmp(str, "pa", 4))
        push_a(data);
    if (!ft_strncmp(str, "pb", 4))
        push_b(data);
    if (!ft_strncmp(str, "ra", 4))
        rotate_a(data);
    if (!ft_strncmp(str, "rb", 4))
        rotate_b(data);
    if (!ft_strncmp(str, "rr", 4))
        rotate_both(data);
    if (!ft_strncmp(str, "rra", 4))
        reverse_rotate_a(data);
    if (!ft_strncmp(str, "rrb", 4))
        reverse_rotate_b(data);
    if (!ft_strncmp(str, "rrr", 4))
        reverse_rotate_both(data);
}

void read_operations(t_data *data)
{
    // comprobar que pasa en el test si se hacen operaciones
    // tras pasar una lista vacía o estando ordenado
    int fd;
    int no_end;
    char *str;

    fd = 0;
    no_end = 1;
    while (no_end)
    {
        no_end = get_next_line(fd, &str);
        run_operation(data, str);
        free(str);
        str = 0;
    }   

}

int main(int argc, char **argv)
{
    t_data data;
    char **numbers;

    if (argc == 2)
        numbers = ft_split(argv[1], ' ');
    else
        numbers = argv;
    if (argc > 1)
    {
        ft_bzero(&data, sizeof(t_data));
        load_stack(&data, argc, numbers);
        read_operations(&data);
        if (is_all_sorted(&data))
            ft_putendl_fd("OK", 1);
        else
            ft_putendl_fd("KO", 1);
    }

}