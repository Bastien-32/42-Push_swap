/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 17:30:28 by badal-la          #+#    #+#             */
/*   Updated: 2025/01/22 17:17:17 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_stack(int argc, char **argv, t_node **a, int i)
{
	char	**split_argv;
	t_node	*newnode;

	split_argv = fill_split_argv(argc, argv);
	if_only_one_number(split_argv);
	*a = ft_lstnew_ps(ft_atoi_ps(a, split_argv[0]));
	if (!*a)
	{
		free_args(split_argv);
		return ;
	}
	(*a)->index = 0;
	while (split_argv[i])
	{
		newnode = ft_lstnew_ps(ft_atoi_ps(a, split_argv[i++]));
		if (!newnode)
		{
			free_list(a);
			free_args(split_argv);
			return ;
		}
		ft_lstadd_back_ps(a, newnode);
	}
	if (argc == 2)
		free_args(split_argv);
}

int	main(int argc, char *argv[])
{
	t_node	*a;
	t_node	*b;
	int		size_a;
	int		i;

	a = NULL;
	b = NULL;
	i = 1;
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
			write(2, "Error\n", 6);
	}
	return (0);
}
