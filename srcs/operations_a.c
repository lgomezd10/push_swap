#include "../includes/push_swap.h"

void swap_a(t_data *data)
{
    t_stack *stack;
    t_stack *operations;

    stack = &data->stack_a;
    operations = &data->operations;
    swap_stack(stack);
    add_new_back(operations, Op_sa);
}

void push_a(t_data *data)
{
    t_stack *stack;
    t_stack *operations;

    stack = &data->stack_a;
    operations = &data->operations;
    move_of_stack(&data->stack_b, &data->stack_a);
    add_new_back(operations, Op_pa);
}

void rotate_a(t_data *data)
{
    t_stack *stack;
    t_stack *operations;

    stack = &data->stack_a;
    operations = &data->operations;
    rotate_stack(stack);
    add_new_back(operations, Op_ra);
}

void reverse_rotate_a(t_data *data)
{
    t_stack *stack;
    t_stack *operations;

    stack = &data->stack_a;
    operations = &data->operations;
    rotate_reverse_stack(stack);
    add_new_back(operations, Op_rra);
}