/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:37:03 by badal-la          #+#    #+#             */
/*   Updated: 2025/01/12 11:35:23 by badal-la         ###   ########.fr       */
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
	*a = ft_lstnew_ps(ft_atoi_ps(split_argv[0]));
	(*a)->index = 0;
	i = 1;
	while (split_argv[i])
		ft_lstadd_back_ps(a, ft_lstnew_ps(ft_atoi_ps(split_argv[i++])));
}

char	**parse_args(int argc, char **argv)
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

	if (!*lst && new)
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