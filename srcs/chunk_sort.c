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
        {
            chunks->found_up = temp->nbr;
            printf("pos up: %d\n", chunks->pos_up);
            return (chunks->pos_up);
        }
        temp = temp->next;
    }
    
    return (-1);
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
        {
            chunks->found_down = temp->nbr;
        printf("pos down: %d\n", chunks->pos_down);
            return (chunks->pos_down);
        }
        temp = temp->prev;
    }
    return (-1);
}

void chunk_sort(t_data *data)
{
    t_stack *stack;
    t_chunks chunks;
    int not_found;
    int steps_up;
    int steps_down;

    stack = &data->stack_a;
    chunks.divitions = 4;
    chunks.chunk = 0;
    not_found = 0;
    printf("Entra\n");
    print_array(data);
    while (stack->size > 0 || find_min_sort(data) != stack->smaller)
    {
        while (!not_found && stack->size > 0)
        {
            find_nbr_up(data, &chunks);
            find_nbr_down(data, &chunks);
            print_stack(stack, 'a');
            print_stack(&data->stack_b, 'b');
            printf("found up: %d, found down: %d\n", chunks.found_up, chunks.found_down);
            if (chunks.pos_up < 0)
                not_found = 1;
            else if (chunks.pos_up <= chunks.pos_down)
                move_up_a(data, chunks.found_up);
            else
                move_up_a(data, chunks.found_down);
            push_b(data);
            //sort_top(data);
        }
        chunks.chunk++;
        not_found = 0;
    }
    /*
    while (data->stack_b.size > 0)
        push_a(data);
        */
    selection_sort_b(data);
    /*
    while (data->stack_b.size > 0)
    {
        insertion_one_in_a(data);
        
        move_up_a(data, data->stack_b.smaller);
        push_a(data);
        
    }
    */
    move_up_a(data, stack->smaller);
}