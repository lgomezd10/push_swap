/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-d <lgomez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 20:38:56 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/06/03 20:39:06 by lgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include  <stdio.h>

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
	int	size;
	int	*array;
}	t_array;

typedef struct s_lst_st
{
	int				nbr;
	int				pos_ord;
	struct s_lst_st	*next;
	struct s_lst_st	*prev;
}	t_lst_st;

typedef struct s_stack
{
	t_lst_st	*start;
	t_lst_st	*end;
	int			size;
	int			smaller;
	int			bigger;
	int			pos_smaller;
	int			pos_bigger;
	int			func;
}	t_stack;

typedef struct s_data
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		min_sorted;
	int		pos_min_sorted;
	t_stack	operations;
	t_array	*sorted;
	int		size;
	int		func;
}	t_data;

typedef struct s_solution
{
	t_stack solution;
	int		argc;
	char	**argv;
} t_solution;

typedef void (*t_function)(t_data *);

void		print_stack(t_stack *stack, char name);
void		print_array(t_data *data);
t_lst_st	*add_new_back(t_stack *stack, int nbr);
void		load_stack(t_data *data, t_solution sol);
void		show_error(void);
void		save_and_restart(t_data *data, t_solution *sol, int func);
int			is_all_sorted(t_data *data);
void		swap_a(t_data *data);
void		push_a(t_data *data);
void		rotate_a(t_data *data);
void		reverse_rotate_a(t_data *data);
void		swap_b(t_data *data);
void		push_b(t_data *data);
void		rotate_b(t_data *data);
void		reverse_rotate_b(t_data *data);
void		rotate_both(t_data *data);
void		reverse_rotate_both(t_data *data);
void		sort_array(t_data *data);
void		swap_both(t_data *data);
void		sort_top(t_data *data);
void		selection_sort(t_data *data);
void		insertion_sort(t_data *data);
void		merge_sort(t_data *data);
void		randix_sort(t_data *data);
void		merge_a_insert_sort(t_data *data);
void		merge_a_select_sort(t_data *data);
void		merge_a_insert_select_sort(t_data *data);
void		bubble_sort(t_data *data);
void		bubble_sort_div(t_data *data);
void		divition_sort1(t_data *data);
void		divition_sort2(t_data *data);
void		divition_sort3(t_data *data);
void		divition_func(t_data *data, t_solution *solution, int i);
#endif