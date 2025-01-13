/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:48:01 by badal-la          #+#    #+#             */
/*   Updated: 2025/01/12 13:09:33 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lstsize_ps(t_node *lst)
{
	int		i;
	t_node	*temp_lst;

	if (!lst)
		return (0);
	i = 1;
	temp_lst = lst;
	while (lst->next != temp_lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	free_args(char **tab)
{
	int	i;

	if (!tab)
		return;
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	free_list(t_node *list)
{
	t_node	*current;
	t_node	*next;

	if (!list)
		return;
	current = list;
	while (1)
	{
		next = current->next;
		free(current);
		if (next == list)
			break;
		current = next;
	}
}

char **fill_split_argv(int argc, char **argv)
{
	if (argc == 2)
		parse_args(argc, argv);
	return (argv + 1);
}
