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
   move_down_a(data, data->stack_a.bigger);
}

void merge_insert_sort3(t_data *data)
{
   merge_sort_a(data, 0);
   while (data->stack_b.size)
	   insertion_one_in_a(data);
   move_down_a(data, data->stack_a.bigger);
}


void merge_insert_sort4(t_data *data)
{
	/*Hacmoes el merge sort a, devolvemos la mitad haciendo insertion a, hacemos merger de b
		insertion en b de los no ordenador y vuelta a a*/
      merge_sort_a(data, 0);
      
      while (data->stack_b.size > 0)
      {
         insertion_one_in_a(data);
      }
      move_down_a(data, data->stack_a.bigger);
      
}

void merge_insert_sort4_1(t_data *data)
{
	/*Hacmoes el merge sort a, devolvemos la mitad haciendo insertion a, hacemos merger de b
		insertion en b de los no ordenador y vuelta a a*/
      merge_sort_a_v2(data, 0);                
      while (data->stack_b.size > (data->sorted->size / 2) + 1)
         insertion_one_in_a(data);
      move_down_a(data, data->stack_a.bigger);
      selection_sort_b(data);
      
}

void merge_insert_sort5(t_data *data)
{
   merge_sort_a_v2(data, 0);
   
   selection_sort_b(data);
}
