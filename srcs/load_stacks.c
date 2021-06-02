/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-d <lgomez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 15:58:14 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/06/02 16:00:58 by lgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	load_stack(t_data *data, int argc, char **argv)
{
	t_list	*list;
	int		nbr;
	int		i;

	i = 1;
	if (argc == 2)
	{
		argc = 0;
		while (argv[argc])
			argc++;
		i = 0;
	}
	while (i < argc)
	{
		if (ft_str_is_nbr(argv[i]))
		{
			nbr = ft_atoi(argv[i]);
			add_new_back(&data->stack_a, nbr);
		}
		else
			show_error();
		i++;
	}
	sort_array(data);
}
