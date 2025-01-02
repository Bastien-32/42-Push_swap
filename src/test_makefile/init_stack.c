/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:11:07 by badal-la          #+#    #+#             */
/*   Updated: 2025/01/02 16:12:07 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(int argc, char **argv, t_node **a)
{
	int		i;
	char	**split_argv;

	if (argc == 2)
		split_argv = parse_args(argc, argv);
	else
		split_argv = argv + 1;
	*a = ft_lstnew(ft_atoi(split_argv[0]));
	i = 1;
	while (split_argv[i])
		ft_lstadd_back(a, ft_lstnew(ft_atoi(split_argv[i++])));
}

char	**parse_args(int argc, char **argv)
{
	char		**split_argv;

	if (argc == 2)
	{
		split_argv = ft_split(argv[1], ' ');
		if (!split_argv)
			return (NULL);
		return (split_argv);
	}
		return (argv + 1);
}