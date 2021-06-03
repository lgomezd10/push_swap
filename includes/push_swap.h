#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
#include "../libft/libft.h"
#include  <stdio.h>

enum e_operations
{
	Op_sa,
	Op_sb,
	Op_ss,
	Op_pa,
	Op_pb,
	Op_ra,
	Op_rb,
	Op_rr,
	Op_rra,
	Op_rrb,
	Op_rrr
};

typedef struct s_array
{
	int size;
	int *array;
}	t_array;

typedef struct s_lst_st
{
	int             nbr;
	int				pos_ord;
	struct s_lst_st  *next;
	struct s_lst_st  *prev;    
	
} t_lst_st;

typedef struct s_stack
{
	t_lst_st    *start;
	t_lst_st    *end;
	int         size;
	int			smaller;
	int			bigger;
	int			pos_smaller;
	int			pos_bigger;
	int			func;
} t_stack;

typedef struct s_data
{
	t_stack stack_a;
	t_stack stack_b;
	int		min_sorted;
	int		pos_min_sorted;
	t_stack operations;
	t_array		*sorted;
	int size;
	int func;
} t_data;

typedef void (*t_function)(t_data *);

void load_stack(t_data *data, int argc, char **argv);
void show_error();
void save_and_restart(t_data *data, t_stack *op, int func);
void delete_list(t_lst_st **list);
t_lst_st *add_new_back(t_stack *stack, int nbr);
void    add_element_front(t_stack *stack, t_lst_st *element);
void    add_element_back(t_stack *stack, t_lst_st *element);
void	remove_element(t_stack *stack, t_lst_st *element);
int	is_all_sorted(t_data *data);
void swap_stack(t_stack *stack);
void move_of_stack(t_stack *src, t_stack *dest);
void rotate_stack(t_stack *stack);
void rotate_reverse_stack(t_stack *stack);
void bubble_sort(t_data *data);
void print_stack(t_stack *stack, char name);
void print_array(t_data *data);
void swap_a(t_data *data);
void push_a(t_data *data);
void rotate_a(t_data *data);
void reverse_rotate_a(t_data *data);
void swap_b(t_data *data);
void push_b(t_data *data);
void rotate_b(t_data *data);
void reverse_rotate_b(t_data *data);
void rotate_both(t_data *data);
void reverse_rotate_both(t_data *data);
void move_up_a(t_data *data, int nbr);
void move_up_b(t_data *data, int nbr);
void move_down_a(t_data *data, int nbr);
void move_down_b(t_data *data, int nbr);
void selection_sort(t_data *data);
void insertion_sort(t_data *data);
void merge_sort(t_data *data);
int get_middle(t_data *data);
void sort_array(t_data *data);
void swap_both(t_data *data);
void sort_top(t_data *data);
int get_middle_temp(t_data *data, t_stack *stack);
t_array *get_array_sorted(t_stack stack, int firts_time);
int	find_prev_a(t_stack stack, int nbr);
int	find_prev_b(t_stack stack, int nbr);
void insertion_one_in_a(t_data *data);
void insertion_one_in_b(t_data *data);
void merge_sort_a(t_data *data);
void merge_sort_b(t_data *data);
void randix_sort(t_data *data);
int a_is_sorted(t_data *data);
int b_is_sorted(t_data *data);
void divide_a(t_data *data);
void selection_sort_b(t_data *data);
int find_min_sort(t_data *data);
void merge_ab_select_sort(t_data *data);
void merge_ab_insert_sort(t_data *data);
void merge_a_insert_sort(t_data *data);
void merge_a_select_sort(t_data *data);
void merge_a_insert_select_sort(t_data *data);
void selection_sort_a(t_data *data);
void	merge_sort_2(t_data *data);
void divition_sort1(t_data *data);
void divition_sort2(t_data *data);
#endif