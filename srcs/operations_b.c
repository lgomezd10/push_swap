#include "../includes/operations.h"

void	swap_b(t_data *data)
{
	t_stack	*stack;
	t_stack	*operations;

	stack = &data->stack_b;
	if (stack->size > 1)
	{
		operations = &data->operations;
		swap_stack(stack);
		add_new_back(operations, Op_sb);
	}
}

void	push_b(t_data *data)
{
	t_stack	*stack;
	t_stack	*operations;

	stack = &data->stack_b;
	if (data->stack_a.size)
	{
		operations = &data->operations;
		move_of_stack(&data->stack_a, &data->stack_b);
		add_new_back(operations, Op_pb);
	}
}

void	rotate_b(t_data *data)
{
	t_stack	*stack;
	t_stack	*operations;

	stack = &data->stack_b;
	if (stack->size > 1)
	{
		operations = &data->operations;
		rotate_stack(stack);
		add_new_back(operations, Op_rb);
	}
}

void	reverse_rotate_b(t_data *data)
{
	t_stack	*stack;
	t_stack	*operations;

	stack = &data->stack_b;
	if (stack->size > 1)
	{
		operations = &data->operations;
		rotate_reverse_stack(stack);
		add_new_back(operations, Op_rrb);
	}
}
