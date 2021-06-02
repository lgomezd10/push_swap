#include "../includes/push_swap.h"

void do_best_action_to_a(t_data *data)
{
    int act_a;
    int act_b;
    int act_a2;
    int nbr;

    nbr = data->stack_a.start->pos_ord;
    act_b = actions_to_move_b(data, nbr);
    nbr = data->stack_b.start->pos_ord;
    act_a = actions_to_move_a(data, nbr);   
    nbr = get_next_of_a(data, &data->stack_a, nbr);
    act_a2 = get_pos_in_stack(data, &data->stack_a, nbr);
    act_a2 = get_number_actions(data, &data->stack_a, act_a2);
    if (act_a != -1 && act_a < act_b && act_a < act_a2)
        insertion_one_in_a(data);
    else if (act_b != -1 && act_b < act_a && act_b < act_a2)
    {
        act_b = data->stack_a.start->pos_ord + 1;
        move_up_b(data, data->sorted->array[act_b]);
        push_a(data);
    }
    else
    {
        move_up_a(data, nbr);
        push_a(data);
    }
}