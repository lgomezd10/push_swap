/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divition_versions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-d <lgomez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 20:50:29 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/06/03 20:50:40 by lgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/algorithms.h"

void	divition_sort1(t_data *data)
{
	divition_sort(data, get_size1);
}

void	divition_sort2(t_data *data)
{
	divition_sort(data, get_size2);
}

void	divition_sort3(t_data *data)
{
	divition_sort(data, get_size3);
}
