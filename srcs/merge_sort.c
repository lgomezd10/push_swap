#include "../includes/push_swap.h"
/*
	Crear un array con los números ordenados
	Hacer la división de los números sólo hasta el número más pequeño ordenado, lo que vemos con la lista de ordenados
	Dejar el número mayor abajo del todo antes de devolver los números de B
*/

void sort_top(t_data *data)
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
	printf("rot_a: %d rot_b: %d\n", rot_a, rot_b);
	
	
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
}

int find_min_sort(t_data *data)
{
	int i;
	t_lst_st *temp;
	int			*sorted;

	sorted = data->sorted;
	i = 0;
	/*
	printf("**** EN MIN SORT********\n");
	print_stack(&data->stack_a, 'A');
	print_stack(&data->stack_b, 'B');
	printf("Array: ");
	while (i < data->size)
	{
		printf("%d, ", sorted[i]);
		i++;
	}
	printf("\n");
	*/
	i = data->size - 1;
	temp = data->stack_a.end;
	
	while (i >= 0 && temp && temp->nbr == sorted[i])
	{
		data->min_sorted = temp->nbr;
		data->pos_min_sorted = i;
		i--;
		temp = temp->prev;
	}
	printf("\n");
	printf("deja de comparar en i: %d temp %p / minsorted: %d\n", i, temp, data->min_sorted);
	return (data->min_sorted);
}

static void system_sort(t_data *data)
{
	t_stack *stack;
	t_lst_st *temp;
	int middle;
	int i;
	int size;

	stack = &data->stack_a;
	move_down(data, data->stack_a.bigger);
	find_min_sort(data);
	size = stack->size;
	while (find_min_sort(data) != stack->smaller)
	{
		middle = get_middle(data);
		temp = data->stack_a.start;
		while (temp && temp->nbr != data->min_sorted)
		{			
			if (temp->nbr <= middle)
			{
				push_b(data);
				//sort_top(data);
			}
			else
				rotate_a(data);
			temp = data->stack_a.start;
		}		
		system_sort(data);
		move_down(data, data->stack_a.bigger);
		i = 0;
		while (stack->size < size)
		{
			push_a(data);
			sort_top(data);
		}					
	}
}

void merge_short(t_data *data)
{
	sort_array(data);
	system_sort(data);
}