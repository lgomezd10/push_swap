#include "../includes/push_swap.h"
int find_min_sort_a(t_data *data)
{
	int i;
	t_lst_st *temp;
	int			*sorted;

	sorted = data->sorted;
	i = 0;
	i = data->size - 1;
	temp = data->stack_a.end;
	
	while (i >= 0 && temp && temp->nbr == sorted[i])
	{
		data->min_sorted = temp->nbr;
		data->pos_min_sorted = i;
		i--;
		temp = temp->prev;
	}
	return (data->min_sorted);
}

static void system_sort_a(t_data *data)
{
    t_stack *stack;
	t_lst_st *temp;
	int middle;
	int i;
	int size;

	stack = &data->stack_a;
    
	move_down(data, data->stack_a.bigger);
	find_min_sort_a(data);
	size = stack->size;
    if (stack->size > 1)
    {
        middle = get_middle(data);
        temp = data->stack_a.start;        
        while (temp && temp->nbr != stack->bigger)
        {			
            if (temp->nbr <= middle)
            {
                push_b(data);
                sort_top(data);
            }
            else
                rotate_a(data);
            temp = data->stack_a.start;
        }
        system_sort_a(data);
    }
}

static void system_sort_b(t_data *data)
{
    t_stack *stack;
	t_lst_st *temp;
	int middle;
	int i;
	int size;

	stack = &data->stack_b;
	move_down_b(data, data->stack_b.smaller);

    printf("DESPUES DE MOVER ABAJO B\n");
    print_stack(&data->stack_a, 'A');
    print_stack(&data->stack_b, 'B');
	size = stack->size;
    if (size > 1)
    {
        middle = stack->smaller + ((stack->bigger - stack->smaller) / 2);
        printf("prueba 4\n");
        temp = data->stack_b.start;
        while (temp && temp->nbr != stack->smaller)
        {	
            if (temp->nbr >= middle)
            {
                push_a(data);
                //sort_top(data);
            }
            else
                rotate_b(data);
            temp = data->stack_b.start;
        }
        system_sort_b(data);
    }
    else
        push_a(data);
}


void merge_select_short(t_data *data)
{

    printf("Entrando en programa\n");
	sort_array(data);
    printf("DESPUES DE ORDENAR ARRAY\n");
	system_sort_a(data);
    printf("DESPUES DE ORDENAR A\n");
    print_stack(&data->stack_a, 'A');
    print_stack(&data->stack_b, 'B');
    sort_array_b(data);
    system_sort_b(data);
    printf("DESPUES DE ORDENAR B\n");
    print_stack(&data->stack_a, 'A');
    print_stack(&data->stack_b, 'B');
    selection_sort(data);
    printf("DESPUES DE SELECTION SORT B\n");
    print_stack(&data->stack_a, 'A');
    print_stack(&data->stack_b, 'B');
}
