/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:37:03 by badal-la          #+#    #+#             */
/*   Updated: 2025/01/23 19:48:50 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	if_only_one_number(char **split_argv)
{
	if (!split_argv[1])
	{
		free_args(split_argv);
		exit (0);
	}
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

int	ft_atoi_ps(t_node **a, char *str)
{
	int		i;
	int		sign;
	long	result;

	number_is_int(a, str);
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
