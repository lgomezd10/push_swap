#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
#include "../libft/libft.h"
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
} t_stack;


void show_error();
t_lst_st *add_new_back(t_stack *stack, int nbr);
void    add_element_front(t_stack *stack, t_lst_st *element);
void    add_element_back(t_stack *stack, t_lst_st *element);
void	remove_element(t_stack *stack, t_lst_st *element);

#endif