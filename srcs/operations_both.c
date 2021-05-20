#include "../includes/push_swap.h"

void swap_both(t_data *data)
{
    t_stack *stack_a;
    t_stack *stack_b;
    t_stack *operations;

    stack_a = &data->stack_a;
    stack_b = &data->stack_b;
    operations = &data->operations;
    swap_stack(stack_a);
    swap_stack(stack_b);
    add_new_back(operations, Op_ss);
}

void rotate_both(t_data *data)
{
    t_stack *stack_a;
    t_stack *stack_b;
    t_stack *operations;

    stack_a = &data->stack_a;
    stack_b = &data->stack_b;
    operations = &data->operations;
    rotate_stack(stack_a);
    rotate_stack(stack_b);
    add_new_back(operations, Op_rr);
}

void reverse_rotate_both(t_data *data)
{
    t_stack *stack_a;
    t_stack *stack_b;
    t_stack *operations;

    stack_a = &data->stack_a;
    stack_b = &data->stack_b;
    operations = &data->operations;
    rotate_reverse_stack(stack_a);
    rotate_reverse_stack(stack_b);
    add_new_back(operations, Op_rrr);
}