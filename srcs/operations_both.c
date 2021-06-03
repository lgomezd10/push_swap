#include "../includes/push_swap.h"

void	swap_both(t_data *data)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*operations;

	stack_a = &data->stack_a;
	stack_b = &data->stack_b;
	operations = &data->operations;
	if (stack_a->size > 1)
		swap_stack(stack_a);
	if (stack_b->size > 1)
		swap_stack(stack_b);
	if (stack_a->size > 1 || stack_b->size > 1)
		add_new_back(operations, Op_ss);
}

void	rotate_both(t_data *data)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*operations;

	stack_a = &data->stack_a;
	stack_b = &data->stack_b;
	operations = &data->operations;
	if (stack_a->size > 1)
		rotate_stack(stack_a);
	if (stack_b->size > 1)
		rotate_stack(stack_b);
	if (stack_a->size > 1 || stack_b->size > 1)
		add_new_back(operations, Op_rr);
}

void	reverse_rotate_both(t_data *data)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*operations;

	stack_a = &data->stack_a;
	stack_b = &data->stack_b;
	operations = &data->operations;
	if (stack_a->size > 1)
		rotate_reverse_stack(stack_a);
	if (stack_b->size > 1)
		rotate_reverse_stack(stack_b);
	if (stack_a->size > 1 || stack_b->size > 1)
		add_new_back(operations, Op_rrr);
}
