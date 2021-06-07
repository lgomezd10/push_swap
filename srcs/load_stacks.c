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

void	load_stack(t_data *data, t_solution sol)
{
	int		i;
	char	**argv;

	argv = sol.argv;
	i = 1;
	if (sol.argc == 2)
	{
		sol.argc = 0;
		while (argv[sol.argc])
			sol.argc++;
		i = 0;
	}
	while (i < sol.argc)
	{
		if (ft_str_is_nbr(argv[i]))
			add_new_back(&data->stack_a, ft_atoi(argv[i]));
		else
			show_error();
		i++;
	}
	sort_array(data);
}
