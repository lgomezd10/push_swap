#include "../includes/push_swap.h"

void	run_operation(t_data *data, char *str)
{
	if (!ft_strncmp(str, "sa", 4))
		swap_a(data);
	else if (!ft_strncmp(str, "sb", 4))
		swap_b(data);
	else if (!ft_strncmp(str, "ss", 4))
		swap_both(data);
	else if (!ft_strncmp(str, "pa", 4))
		push_a(data);
	else if (!ft_strncmp(str, "pb", 4))
		push_b(data);
	else if (!ft_strncmp(str, "ra", 4))
		rotate_a(data);
	else if (!ft_strncmp(str, "rb", 4))
		rotate_b(data);
	else if (!ft_strncmp(str, "rr", 4))
		rotate_both(data);
	else if (!ft_strncmp(str, "rra", 4))
		reverse_rotate_a(data);
	else if (!ft_strncmp(str, "rrb", 4))
		reverse_rotate_b(data);
	else if (!ft_strncmp(str, "rrr", 4))
		reverse_rotate_both(data);
	else if (ft_strlen(str))
		show_error();
}

void	read_operations(t_data *data)
{
	int		fd;
	int		no_end;
	char	*str;
	int		firts;
	int		prev;

	fd = 0;
	no_end = 1;
	str = 0;
	firts = 1;
	while (no_end)
	{
		prev = no_end;
		no_end = get_next_line(fd, &str);
		if (no_end && !ft_strlen(str))
			show_error();
		if (!(!no_end && firts))
			run_operation(data, str);
		firts = 0;
		free(str);
		str = 0;
	}
}

int	main(int argc, char **argv)
{
	t_data		data;
	char		**numbers;
	t_solution	solution;

	solution.argc = argc;
	if (argc == 2)
		numbers = ft_split(argv[1], ' ');
	else
		numbers = argv;
	solution.argv = numbers;
	if (argc > 1)
	{
		ft_bzero(&data, sizeof(t_data));
		load_stack(&data, solution);
		read_operations(&data);
		if (is_all_sorted(&data))
			ft_putendl_fd("OK", 1);
		else
			ft_putendl_fd("KO", 1);
	}
}
