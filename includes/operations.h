/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-d <lgomez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 20:38:31 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/06/03 20:38:42 by lgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H
# include "push_swap.h"

void		delete_list(t_lst_st **list);
void		add_element_front(t_stack *stack, t_lst_st *element);
void		add_element_back(t_stack *stack, t_lst_st *element);
void		remove_element(t_stack *stack, t_lst_st *element);
void		swap_stack(t_stack *stack);
void		move_of_stack(t_stack *src, t_stack *dest);
void		rotate_stack(t_stack *stack);
void		rotate_reverse_stack(t_stack *stack);
#endif