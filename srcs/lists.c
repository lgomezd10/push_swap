#include "../includes/push_swap.h"

t_lst_st *add_new_back(t_stack *stack, int nbr)
{
	t_lst_st    *new;

	new = (t_lst_st *)ft_calloc(sizeof(t_lst_st), 1);
	if (!new)
		show_error();
	new->nbr = nbr;
	if (nbr < stack->smaller)
		stack->smaller = nbr;
	if (nbr > stack->bigger)
		stack->bigger = nbr;
	if (!stack->start)
	{
		stack->smaller = nbr;
		stack->bigger = nbr;
		stack->start = new;
		stack->end = new;
		stack->size = 1;
		return (new);
	}
	stack->end->next = new;
	new->prev = stack->end;
	stack->end = new;
	stack->size++;
	return (new);
}

void    add_element_front(t_stack *stack, t_lst_st *element)
{

	element->prev = 0;
	element->next = 0;
	if (!stack->start)
	{
		stack->smaller = element->nbr;
		stack->bigger = element->nbr;
		stack->start = element;
		stack->end = element;
		stack->size = 1;
	}
	else
	{
		stack->start->prev = element;
		element->next = stack->start;
		stack->start = element;
		stack->size++;
	}
	if (element->nbr < stack->smaller)
		stack->smaller = element->nbr;
	if (element->nbr > stack->bigger)
		stack->bigger = element->nbr;
}

void    add_element_back(t_stack *stack, t_lst_st *element)
{
	element->prev = 0;
	element->next = 0;
	if (!stack->start)
	{
		stack->smaller = element->nbr;
		stack->bigger = element->nbr;
		stack->start = element;
		stack->end = element;
		stack->size = 1;
	}
	else
	{
		stack->end->next = element;
		element->prev = stack->end;
		stack->end = element;
		stack->size++;
	}
	if (element->nbr < stack->smaller)
		stack->smaller = element->nbr;
	if (element->nbr > stack->bigger)
		stack->bigger = element->nbr;
}

int find_element(t_lst_st *list, int smaller)
{
	int nbr;

	if (list)
	{
		nbr = list->nbr;
		while (list)
		{
			if (smaller && list->nbr < nbr)
				nbr = list->nbr;
			if (!smaller && list->nbr > nbr)
				nbr = list->nbr;
			list = list->next;
		}
		return (nbr);
	}
	else
		return (0);
	
}

void remove_element(t_stack *stack, t_lst_st *element)
{
	if (stack && element)
	{
		if (!element->prev)
			stack->start = element->next;
		else
			element->prev->next = element->next;
		if (!element->next)
			stack->end = element->prev;
		else        
			element->next->prev = element->prev;
		stack->size--;
		if (element->nbr == stack->bigger)
			stack->bigger = find_element(stack->start, 0);
		if (element->nbr == stack->smaller)
			stack->smaller = find_element(stack->start, 1);
	}
	
}