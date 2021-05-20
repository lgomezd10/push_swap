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

typedef struct s_lst_st
{
	int             nbr;
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
} t_stack;

typedef struct s_data
{
	t_stack stack_a;
	t_stack stack_b;
	int		min_sorted;
	int		pos_min_sorted;
	int		min_sorted_b;
	int		pos_min_sorted_b;
	t_stack operations;
	int			*sorted;
	int size;
	int			*sorted_b;
	int size_b;
} t_data;



void show_error();
t_lst_st *add_new_back(t_stack *stack, int nbr);
void    add_element_front(t_stack *stack, t_lst_st *element);
void    add_element_back(t_stack *stack, t_lst_st *element);
void	remove_element(t_stack *stack, t_lst_st *element);
int is_sort_increasing(t_lst_st *list);
int is_sort_decreasing(t_lst_st *list);
void swap_stack(t_stack *stack);
void move_of_stack(t_stack *src, t_stack *dest);
void rotate_stack(t_stack *stack);
void rotate_reverse_stack(t_stack *stack);
void bubble_sort_a(t_data *data);
void bubble_sort_b(t_data *data);
void print_stack(t_stack *stack, char name);
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
void move_up(t_data *data, int nbr);
void selection_sort(t_data *data);
void insertion_sort(t_data *data);
void merge_short(t_data *data);
int get_middle(t_data *data);
void sort_array(t_data *data);
void move_down(t_data *data, int nbr);
void swap_both(t_data *data);
void sort_top(t_data *data);
void merge_select_short(t_data *data);
void sort_array_b(t_data *data);
void move_down_b(t_data *data, int nbr);

#endif