#include "../includes/push_swap.h"

void merge_ab_select_sort(t_data *data)
{
   merge_sort_a(data);
   merge_sort_b(data);
   selection_sort(data);
}

void merge_ab_insert_sort(t_data *data)
{
   merge_sort_a(data);
   merge_sort_b(data);
   insertion_sort(data);    
}


void merge_a_insert_sort(t_data *data)
{
   merge_sort_a(data);
   while (data->stack_b.size)
	   insertion_one_in_a(data);
   move_down_a(data, data->stack_a.bigger);
}


void merge_a_select_sort(t_data *data)
{
      merge_sort_a(data);      
      selection_sort_b(data);     
}

void merge_a_markup_sort(t_data *data)
{
      merge_sort_a(data);
      while (data->stack_b.size)
      {
         do_best_action_to_a(data);
      }
        
      
      move_down_a(data, data->stack_a.bigger);
}

void merge_a_insert_select_sort(t_data *data)
{
      merge_sort_a(data);                
      while (data->stack_b.size > (data->sorted->size / 2) + 1)
         insertion_one_in_a(data);
      move_down_a(data, data->stack_a.bigger);
      selection_sort_b(data);      
}

