#include "../includes/push_swap.h"

void print_array(t_data *data)
{
    int i;
    t_lst_st *temp;

    i = 0;
    printf("ARRAY: ");
    while (i < data->sorted->size)
    {
        printf("%d,", data->sorted->array[i]);
        i++;
    }
    printf("\n");   
    printf("List with pos:\n");
    temp = data->stack_a.start;
    while (temp)
    {
        printf("nbr: %d / pos: %d |", temp->nbr, temp->pos_ord);
        temp = temp->next;
    }
    printf("\n");    
}

void print_stack(t_stack *stack, char name)
{
    t_lst_st *temp;

    printf("stack %c / menor: %d / mayor: %d size %d: ", name, stack->smaller, stack->bigger, stack->size);
    
    temp = stack->start;
    while (temp)
    {
        printf("%d,", temp->nbr);
        temp = temp->next;
    }
    printf("\n");
    /*
    printf("                                REVERSO: ");
    temp = stack->end;
    while (temp)
    {
        printf("%d,", temp->nbr);
        temp = temp->prev;
    }
    printf("\n");
    */
}

void print_reverse(t_stack *stack, char name)
{
    t_lst_st *temp;

    printf("stack %c %d: ", name, stack->size);
    temp = stack->end;
    while (temp)
    {
        printf("%d,", temp->nbr);
        temp = temp->prev;
    }
    printf("\n");
}