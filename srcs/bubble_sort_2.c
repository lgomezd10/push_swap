#include "../includes/push_swap.h"

int swap_top(t_data *data)
{
    t_lst_st *list_a;
    t_lst_st *list_b;
    int rot_a;
    int rot_b;

    list_a = data->stack_a.start;
    list_b = data->stack_b.start;
    rot_a = 0;
    rot_b = 0;
		
    
    if (list_a && list_a->next)
    {
		//printf("STACK A 1: %d next: %d\n", list_a->nbr, list_a->next->nbr);
        
		if (list_a->nbr > list_a->next->nbr)
            rot_a = 1;
    }
    if (list_b && list_b->next)
    {
		//printf("STACK B 1: %d next: %d\n", list_b->nbr, list_b->next->nbr);
        if (list_b->nbr < list_b->next->nbr)
            rot_b = 1;
    }
	//printf("rot_a: %d rot_b: %d\n", rot_a, rot_b);	
	
    if (rot_a && rot_b)
        swap_both(data);
    if (rot_a && !rot_b)
        swap_a(data);
    if (!rot_a && rot_b)
        swap_b(data);	
	/*
	printf("*******DESPUES DE ROTAR************\n");
	print_stack(&data->stack_a, 'A');
    print_stack(&data->stack_b, 'B');
    */
    return (rot_a || rot_b);
	
}

int check_top(t_data *data)
{
    t_stack *stack_a;
    t_stack *stack_b;
    int moved;
    int swap;

    stack_a = &data->stack_a;
    stack_b = &data->stack_b;
    moved = 0;
    swap = 1;
    if (stack_a->start->nbr == stack_a->bigger)
    {
        moved = 1;
        rotate_a(data);
    }
    if (stack_b->start->nbr == stack_b->smaller)
    {
        rotate_b(data);
    }
    if (moved)
    {
        if (!data->change)
            swap = 0;
        data->change = 0;
    }
}
static void divide_a(t_data *data)
{
    t_stack *stack;
	t_lst_st *temp;
	int middle;
	int i;
	int size;

	stack = &data->stack_a;
	size = stack->size;
    if (!is_sort_increasing(stack->start))
    {
        middle = get_middle_temp(data, stack);
        temp = data->stack_a.start;        
        while (temp && stack->size > 2 && size)
        {		
            
            if (temp->nbr <= middle)
                push_b(data);
            else
                rotate_a(data);
            temp = data->stack_a.start;
            size--;
        }
    }
}

void bubble_sort_2(t_data *data)
{
    t_stack *stack_a;
    t_stack *stack_b;
    int     sorted_a;
    int     sorted_b;
    int     swap;
    int     count;

    stack_a = &data->stack_a;
    stack_b = &data->stack_b;
    move_down(data, stack_a->bigger);
    sorted_a = is_sort_increasing(stack_a->start);
    swap = 1;
    if (!sorted_a)
        divide_a(data);
    move_down(data, stack_a->bigger);
    move_down_b(data, stack_b->smaller);
    sorted_a = is_sort_increasing(stack_a->start);
    sorted_b = is_sort_decreasing(stack_b->start);
    printf("*******DESPUES DE DIVIDIR************\n");
	print_stack(&data->stack_a, 'A');
    print_stack(&data->stack_b, 'B');
    data->change = 1;        
    while ((!sorted_a || !sorted_b) && swap)
    {
        swap_top(data);
        if (!sorted_a && !sorted_b)
            rotate_both(data);
        if (sorted_a && !sorted_b)
            rotate_b(data);
        if (!sorted_a && sorted_b)
            rotate_a(data);
        check_top(data);
        sorted_a = is_sort_increasing(stack_a->start);
        sorted_b = is_sort_decreasing(stack_b->start);
    }
    move_down(data, data->stack_a.bigger);
    printf("*******DESPUES DE MOVE A************\n");
	print_stack(&data->stack_a, 'A');
    print_stack(&data->stack_b, 'B');
    move_down_b(data, data->stack_b.smaller);
    printf("*******DESPUES DE MOVE B************\n");
	print_stack(&data->stack_a, 'A');
    print_stack(&data->stack_b, 'B');
    while (stack_b->size)
    {
        push_a(data);
    }
    
    
}