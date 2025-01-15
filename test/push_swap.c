/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 17:30:28 by badal-la          #+#    #+#             */
/*   Updated: 2025/01/15 13:31:44 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	*a;
	t_node	*b;
	int		size_a;
	int		i;

	a = NULL;
	b = NULL;
	i = 0;
	if (argc == 1)
		return (0);
	else
	{
		if (!check_args(argc, argv))
		{
			init_stack(argc, argv, &a, i);
			size_a = lstsize_ps(a);
			check_stack(&a, size_a);
			sort(&a, &b, size_a);
			free_list(&a);
			free_list(&b);
		}
		else
			write(1, "Error\n", 6);
	}
	return (0);
}
