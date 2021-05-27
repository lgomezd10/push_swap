#include "../includes/push_swap.h"

void merge_select_sort(t_data *data)
{
   merge_sort_a(data, 0);
   merge_sort_b(data);
   selection_sort(data);
}

void merge_insert_sort(t_data *data)
{
   merge_sort_a(data, 0);
   merge_sort_b(data);
   insertion_sort(data);    
}

void merge_insert_sort2(t_data *data)
{
   merge_sort_a(data, 1);
   while (data->stack_b.size)
	   insertion_one_in_a(data);
}

void merge_insert_sort3(t_data *data)
{
   merge_sort_a(data, 0);
   while (data->stack_b.size)
	   insertion_one_in_a(data);
}

void merge_insert_sort_4(t_data *data)
{
	/*Hacmoes el merge sort a, devolvemos la mitad haciendo insertion a, hacemos merger de b
		insertion en b de los no ordenador y vuelta a a*/
}
