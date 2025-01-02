/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_and_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:17:30 by badal-la          #+#    #+#             */
/*   Updated: 2025/01/02 15:26:44 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	if(argc == 1)
		return (1);
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
	while(str[i])
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

int	check_stack(t_node **a)
{
	if (a_is_sorted(a))
		exit (-1);
	if (a_contain_doubles(a))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	a_is_sorted(t_node **a)
{
	t_node	*temp;
	
	temp = *a;
	while (temp->next)
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
	
	temp = *a;
	while (temp)
	{
		temp2 = temp->next;
		while (temp2)
		{
			if (temp->content == temp2->content)
				return (1);
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
	return (0);
}