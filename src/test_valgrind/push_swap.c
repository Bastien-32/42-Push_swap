/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 17:30:28 by badal-la          #+#    #+#             */
/*   Updated: 2025/01/12 12:54:06 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	*a;
	t_node	*b;
	int		size_a;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	else
	{
		if (!check_args(argc, argv))
		{
			init_stack(argc, argv, &a);
			size_a = lstsize_ps(a);
			check_stack(&a, size_a);
			sort(&a, &b, size_a);
			free_list(a);
			free_list(b);
		}
		else
			write(1, "Error\n", 6);
	}
	return (0);
}
