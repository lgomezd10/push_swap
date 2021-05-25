#include "../includes/push_swap.h"

int is_in_stack(t_stack *stack, int nbr)
{
    t_lst_st *temp;

    temp = stack->start;
    while (temp && temp->nbr != nbr)
        temp = temp->next;
    if (temp && temp->nbr == nbr)
        return (1);
    return (0);    
}

void ger_sort(t_data *data)
{
	t_stack *stack_a;
	t_stack *stack_b;
    int i;
    int nbr;

	stack_a = &data->stack_a;
	stack_b = &data->stack_b;
    i = 0;
    while (i < data->sorted->size)
    {
        nbr = data->sorted->array[i];
        if (is_in_stack(stack_a, nbr))
        {
            while (stack_a->start->nbr != nbr)
                push_b(data);
            rotate_a(data);
        }
        else if (is_in_stack(stack_b, nbr))
        {
            while (stack_b->start->nbr != nbr)
                push_a(data);
            push_a(data);
            rotate_a(data);
        }
        i++;
    }

}