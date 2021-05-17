#include "includes/push_swap.h"

void print_stack(t_stack *stack, char name)
{
    t_lst_st *temp;

    printf("stack %c %d: ", name, stack->size);
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
    t_stack stackA;
    t_stack stackB;
    int pila[] = {5, 6, 10, 3, 1, 0};
    int i;

    ft_bzero(&stackA, sizeof(t_stack));
    ft_bzero(&stackB, sizeof(t_stack));
    printf("entrando en test\n");
    i = 0;
    while (pila[i] != 0)
    {
        printf("añadiendo %d\n", pila[i]);
        add_new_back(&stackA, pila[i]);
        i++;
        printf("añadido %d\n", pila[i]);
    }
    print_stack(&stackA, 'A');
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

}