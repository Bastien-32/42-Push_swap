/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:37:03 by badal-la          #+#    #+#             */
/*   Updated: 2025/01/14 17:24:49 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(int argc, char **argv, t_node **a)
{
	int		i;
	char	**split_argv;
	t_node	*newnode;

	split_argv = fill_split_argv(argc, argv);
	*a = ft_lstnew_ps(ft_atoi_ps(split_argv[0]));
	if (!*a)
	{
		free_args(split_argv);
		return ;
	}
	(*a)->index = 0;
	i = 1;
	while (split_argv[i])
	{
		newnode = ft_lstnew_ps(ft_atoi_ps(split_argv[i++]));
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

char	**fill_split_argv(int argc, char **argv)
{
	char	**split_argv;

	if (argc == 2)
	{
		split_argv = ft_split_ps(argv[1], ' ');
		if (!split_argv)
			return (NULL);
		return (split_argv);
	}
	return (argv + 1);
}

t_node	*ft_lstnew_ps(int content)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->content = content;
	node->lenght = 1;
	node->sub_sequence = 0;
	node->in_lis = 0;
	node->compt_b = 0;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_back_ps(t_node **lst, t_node *new)
{
	t_node	*last;

	if (!new)
	{
		free_list(lst);
		*lst = NULL;
		return ;
	}
	if (!*lst)
	{
		*lst = new;
		new->next = *lst;
		new->prev = new;
		return ;
	}
	last = *lst;
	while (last->next && last->next != *lst)
		last = last->next;
	last->next = new;
	new->prev = last;
	new->next = *lst;
	(*lst)->prev = new;
	new->index = last->index + 1;
}

int	ft_atoi_ps(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ' )
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + str[i++] - '0';
	result *= sign;
	return ((int)result);
}
