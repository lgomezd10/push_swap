#include "includes/push_swap.h"

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

int main(void)
{
    t_data data;
    t_stack *stackA;
    t_stack *stackB;
    int pila[] = {5, 1, 6, 10, 3, 4, 0};
    int i;

    ft_bzero(&data, sizeof(t_data));
    stackA = &data.stack_a;
    stackB = &data.stack_b;
    printf("entrando en test\n");
    i = 0;
    while (pila[i] != 0)
    {
        printf("añadiendo %d\n", pila[i]);
        add_new_back(stackA, pila[i]);
        i++;
        printf("añadido %d\n", pila[i]);
    }
    /*
    i = 0;
    while (pila[i] != 0)
    {
        printf("añadiendo %d\n", pila[i]);
        add_new_back(stackB, pila[i]);
        i++;
        printf("añadido %d\n", pila[i]);
    }
    */
    print_stack(stackA, 'A');
    print_stack(stackB, 'B');
    /*
    bubble_sort_a(&data);
    print_stack(stackA, 'A');
    bubble_sort_b(&data);    
    print_stack(stackB, 'B');
    */
    //selection_sort(&data);
    
    //insertion_sort(&data);
    merge_short(&data);
    print_stack(stackA, 'A');
    print_stack(stackB, 'B');
    print_stack(&data.operations, 'O');
    printf("%d operaciones\n", data.operations.size);

    /*
    buble_sort(&data);
    print_stack(stackA, 'A');
    print_stack(&data.operations, 'O');
    printf("%d operaciones\n", data.operations.size);
    
    print_reverse(&stackA, 'A');
    move_of_stack(&stackA, &stackB);
    print_stack(&stackA, 'A');
    print_stack(&stackB, 'B');
    move_of_stack(&stackA, &stackB);
    move_of_stack(&stackA, &stackB);
    print_stack(&stackA, 'A');
    print_stack(&stackB, 'B');
    rotate_stack(&stackB);
    print_stack(&stackB, 'B');
    rotate_reverse_stack(&stackB);
    print_stack(&stackB, 'B');
    */

}