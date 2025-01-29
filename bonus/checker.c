/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 17:30:28 by badal-la          #+#    #+#             */
/*   Updated: 2025/01/29 16:14:31 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../get_next_line/get_next_line_bonus.h"

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

int	execute_command(char *cmd, t_node **a, t_node **b)
{
	if (ft_strcmp_ps(cmd, "sa\n") == 0)
		sa(a, 0);
	else if (ft_strcmp_ps(cmd, "sb\n") == 0)
		sb(b, 0);
	else if (ft_strcmp_ps(cmd, "ss\n") == 0)
		ss(a, b, 0);
	else if (ft_strcmp_ps(cmd, "pa\n") == 0)
		pa(a, b, 0);
	else if (ft_strcmp_ps(cmd, "pb\n") == 0)
		pb(a, b, 0);
	else if (ft_strcmp_ps(cmd, "ra\n") == 0)
		ra(a, 0);
	else if (ft_strcmp_ps(cmd, "rb\n") == 0)
		rb(b, 0);
	else if (ft_strcmp_ps(cmd, "rr\n") == 0)
		rr(a, b, 0);
	else if (ft_strcmp_ps(cmd, "rra\n") == 0)
		rra(a, 0);
	else if (ft_strcmp_ps(cmd, "rrb\n") == 0)
		rrb(b, 0);
	else if (ft_strcmp_ps(cmd, "rrr\n") == 0)
		rrr(a, b, 0);
	else
		return (1);
	return (0);
}

void	read_command(t_node **a, t_node **b, int size_a)
{
	char	*cmd;

	cmd = get_next_line(STDIN_FILENO);
	while (cmd != NULL)
	{
		if (execute_command(cmd, a, b) == 1)
		{
			free(cmd);
			write (2, "Error\n", 6);
			free_list(a);
			free_list(b);
			exit (1);
		}
		free(cmd);
		cmd = get_next_line(STDIN_FILENO);
	}
	if (a_is_sorted(a, size_a) && (!b || *b == NULL))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	check_stack_bonus(t_node **a)
{
	if (a_contain_doubles(a))
	{
		write(2, "Error\n", 6);
		free_list(a);
		exit (1);
	}
	return (0);
}
int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	int		size_a;
	int		i;

	i = 1;
	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	else
	{
		if (!check_args(argc, argv))
		{
			init_stack(argc, argv, &a, i);
			size_a = lstsize_ps(a);
			check_stack_bonus(&a);
			read_command(&a, &b, size_a);
			free_list(&a);
			free_list(&b);
		}
		else
			write(2, "Error\n", 6);
	}
	return (0);
}
