#include "../includes/push_swap.h"

int get_pos(t_stack *stack, int nbr)
{
    int pos;
    t_lst_st *temp;

    temp = stack->start;
    pos = -1;
    while (temp)
    {
        pos++;
        if (temp->nbr == nbr)
            return (pos);
    }
    return (pos);
}

int is_in_chunk(t_data *data, t_chunks *chunks, int nbr)
{
    int size;
    int to;
    int i;

    size = data->sorted->size / chunks->divitions;
    i = chunks->chunk * size;
    to = i + size;
    while (i < to)
    {
        if (nbr == data->sorted->array[i])
            return (1);
        i++;
    }
    return (0);
}

int find_nbr_up(t_data *data, t_chunks *chunks)
{
    int pos;
    t_lst_st *temp;

    temp = data->stack_a.start;
    chunks->pos_up = -1;
    while (temp)
    {
        chunks->pos_up++;
        if (is_in_chunk(data, chunks, temp->nbr))
            return (chunks->pos_up);
        temp = temp->next;
    }
    return (chunks->pos_up);
}

int find_nbr_down(t_data *data, t_chunks *chunks)
{
    int pos;
    t_lst_st *temp;

    temp = data->stack_a.end;
    chunks->pos_down = -1;
    while (temp)
    {
        chunks->pos_down++;
        if (is_in_chunk(data, chunks, temp->nbr))
            return (chunks->pos_down);
        temp = temp->prev;
    }
    return (chunks->pos_down);
}

void chunk_sort(t_data *data)
{
    t_stack *stack;
    t_chunks chunks;
    int not_found;
    int steps_up;
    int steps_down;

    stack = &data->stack_a;
    chunks.divitions = 11;
    chunks.chunk = 0;
    not_found = 0;
    while (stack->size > 0 || find_min_sort(data) != stack->smaller)
    {
        while (!not_found && stack->size > 0)
        {
            steps_up = find_nbr_up(data, &chunks);
            steps_down = stack->size - find_nbr_down(data, &chunks) - 1;
            if (steps_up < 0)
                not_found = 1;
            if (steps_up <= steps_down)
                move_up_a(data, chunks.found_up);
            else
                move_up_a(data, chunks.found_down);
            insertion_a_to_b(data);
        }
        chunks.chunk++;
        not_found = 0;
    }
    while (data->stack_b.size > 0)
        push_a(data);
    move_up_a(data, stack->smaller);
}