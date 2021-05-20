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

int main(void)
{
    t_data data;
    t_stack *stackA;
    t_stack *stackB;
    //int pila[] = {5, 1, 6, 10, 3, 4, 0};
    //int pila[] = {16, 17, 45, 27, 88, 49, 75, 2, 72, 59, 95, 37, 13, 51, 31, 10, 23, 50, 91, 25, 66, 7, 96, 56, 92, 68, 73, 33, 61, 15, 0};
    int pila[] = {53, 167, 93, 32, 72, 114, 194, 60, 112, 46, 175, 24, 73, 59, 151, 197, 170, 139, 95, 186, 80, 148, 178, 145, 133, 153, 9, 200, 111, 160, 66, 78, 84, 70, 169, 183, 51, 37, 94, 74, 6, 75, 143, 52, 11, 116, 185, 149, 82, 156, 118, 165, 7, 36, 17, 192, 12, 137, 16, 57, 44, 138, 49, 98, 113, 187, 68, 10, 81, 21, 198, 48, 182, 45, 19, 108, 100, 164, 30, 177, 91, 67, 123, 33, 128, 15, 191, 104, 58, 135, 125, 23, 96, 199, 25, 69, 129, 105, 86, 161, 0};
    //int pila[] = {54, 23, 106, 94, 190, 119, 161, 72, 189, 137, 34, 114, 40, 53, 39, 103, 7, 26, 171, 51, 48, 163, 36, 46, 28, 124, 67, 185, 59, 162,0};
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
    t_lst_st *temp;
    temp = data.stack_a.end;
    while (temp)
    {
        printf("%d, ", temp->nbr);
        temp = temp->prev;
    }
    printf("\n");
    */
    
     print_stack(stackA, 'A');
    print_stack(stackB, 'B');
    merge_short(&data);
    //selection_sort(&data);
    
    print_stack(stackA, 'A');
    print_stack(stackB, 'B');
    print_stack(&data.operations, 'O');
    

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
   /*
    i = 0;
    printf("** %d **\n", i++);
    print_stack(stackA, 'A');
    print_stack(stackB, 'B');
    push_b(&data);
    printf("** %d **\n", i++);
    print_stack(stackA, 'A');
    print_stack(stackB, 'B');
    push_b(&data);
    printf("** %d **\n", i++);
    print_stack(stackA, 'A');
    print_stack(stackB, 'B');
    push_b(&data);
    printf("** %d **\n", i++);
    print_stack(stackA, 'A');
    print_stack(stackB, 'B');
    push_b(&data);
    printf("** %d **\n", i++);
    print_stack(stackA, 'A');
    print_stack(stackB, 'B');
    push_b(&data);
    printf("** %d **\n", i++);
    print_stack(stackA, 'A');
    print_stack(stackB, 'B');
    push_b(&data);
    printf("** %d **\n", i++);
    print_stack(stackA, 'A');
    print_stack(stackB, 'B');
    push_b(&data);
    printf("** %d **\n", i++);
    print_stack(stackA, 'A');
    print_stack(stackB, 'B');
    push_b(&data);

    
    printf("**CAMBIO A PUSH A %d **\n", i++);
    print_stack(stackA, 'A');
    print_stack(stackB, 'B');
    push_a(&data);
    printf("** %d **\n", i++);
    print_stack(stackA, 'A');
    print_stack(stackB, 'B');
    push_a(&data);
    printf("** %d **\n", i++);
    print_stack(stackA, 'A');
    print_stack(stackB, 'B');
    push_a(&data);
    printf("** %d **\n", i++);
    print_stack(stackA, 'A');
    print_stack(stackB, 'B');
    push_a(&data);
    printf("** %d **\n", i++);
    print_stack(stackA, 'A');
    print_stack(stackB, 'B');
    push_a(&data);
    printf("** %d **\n", i++);
    print_stack(stackA, 'A');
    print_stack(stackB, 'B');
    push_a(&data);
    printf("** %d **\n", i++);
    print_stack(stackA, 'A');
    print_stack(stackB, 'B');
    push_a(&data);
    printf("** %d **\n", i++);
    print_stack(stackA, 'A');
    print_stack(stackB, 'B');
    push_a(&data);
    */
  
    //short_array(&data);
    /*
    bubble_sort_a(&data);
    print_stack(stackA, 'A');
    bubble_sort_b(&data);    
    print_stack(stackB, 'B');
    */
    //selection_sort(&data);
    
    //insertion_sort(&data);
    /*
    merge_short(&data);
    print_stack(stackA, 'A');
    print_stack(stackB, 'B');
    print_stack(&data.operations, 'O');
    printf("%d operaciones\n", data.operations.size);
    */
    /*
    buble_sort(&data);
    print_stack(stackA, 'A');
    print_stack(&data.operations, 'O');
    printf("%d operaciones\n", data.operations.size);
    */
   /*
    printf("***** 1 ********\n");
    print_stack(stackA, 'A');
    move_of_stack(stackA, stackB);
    print_stack(stackA, 'A');
    print_stack(stackB, 'B');
    printf("***** 2 ********\n");
    move_of_stack(stackA, stackB);
    move_of_stack(stackA, stackB);
    print_stack(stackA, 'A');
    print_stack(stackB, 'B');
    printf("***** 3 ********\n");
    rotate_stack(stackB);
    print_stack(stackB, 'B');
    printf("***** 4 ********\n");
    rotate_reverse_stack(stackB);
    print_stack(stackB, 'B');
    printf("***** 3 ********\n");
    rotate_stack(stackB);
    print_stack(stackB, 'B');
    printf("***** 4 ********\n");
    rotate_reverse_stack(stackB);
    print_stack(stackB, 'B');
    printf("***** 5 ********\n");
    rotate_stack(stackA);
    print_stack(stackA, 'A');
    printf("***** 6 ********\n");
    rotate_reverse_stack(stackA);
    print_stack(stackA, 'A');
*/
    

}