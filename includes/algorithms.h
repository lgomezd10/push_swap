/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-d <lgomez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 20:39:26 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/06/07 15:58:03 by lgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHMS_H
# define ALGORITHMS_H
# include "push_swap.h"

void		move_up_a(t_data *data, int nbr);
void		move_up_b(t_data *data, int nbr);
void		move_down_a(t_data *data, int nbr);
void		move_down_b(t_data *data, int nbr);
int			get_middle(t_data *data);
int			get_middle_temp(t_stack *stack);
t_array		*get_array_sorted(t_stack stack, int firts_time);
int			find_prev_a(t_stack stack, int nbr);
int			find_prev_b(t_stack stack, int nbr);
void		insertion_one_in_a(t_data *data);
void		insertion_one_in_b(t_data *data);
void		selection_sort_a(t_data *data);
void		selection_sort_b(t_data *data);
void		merge_sort_a(t_data *data);
void		merge_sort_b(t_data *data);
int			a_is_sorted(t_data *data);
int			b_is_sorted(t_data *data);
void		divide_a(t_data *data);
int			find_min_sort(t_data *data);
int			get_middle_of_chunk(int chunk, int size);
int			get_max_of_chunk(int chunk, int size);
int			has_elements_of_chunk(t_data *data, int chunk, int size);
int			needed_swap_a(t_data *data);
int			needed_swap_b(t_data *data);
#endif