/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_and_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:30:43 by badal-la          #+#    #+#             */
/*   Updated: 2025/01/23 15:16:34 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

int	check_args(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		return (0);
	i = 1;
	while (argv[i])
	{
		if (!is_number(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

int	is_number(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
			i++;
		if (str[i] == '+' || str[i] == '-')
			i++;
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		if (str[i] && !((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
			return (0);
	}
	return (1);
}

int	check_stack(t_node **a, int size_a)
{
	if (a_contain_doubles(a))
	{
		write(2, "Error\n", 6);
		free_list(a);
		exit (1);
	}
	if (a_is_sorted(a, size_a))
	{
		free_list(a);
		exit (0);
	}
	return (0);
}

int	a_is_sorted(t_node **a, int size_a)
{
	t_node	*temp;

	temp = *a;
	while (size_a-- > 1)
	{
		if (temp->content > temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	a_contain_doubles(t_node **a)
{
	t_node	*temp;
	t_node	*temp2;

	if (!*a)
		return (0);
	temp = *a;	
	while (temp)
	{
		temp2 = temp->next;
		while (temp2 && temp2 != *a)
		{
			if (temp->content == temp2->content)
				return (1);
			temp2 = temp2->next;
		}
		temp = temp->next;
		if (temp == *a)
			break ;
	}
	return (0);
}
