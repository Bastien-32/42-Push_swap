/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:48:01 by badal-la          #+#    #+#             */
/*   Updated: 2025/01/14 18:56:10 by badal-la         ###   ########.fr       */
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
		return ;
	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void	free_list(t_node **list)
{
	t_node	*next;
	int		size;
	int		i;

	if (!list || ! *list)
		return ;
	next = *list;
	i = 0;
	size = lstsize_ps(next);
	while (i < size)
	{
		next = (*list)->next;
		free(*list);
		*list = next;
		i++;
	}
	*list = NULL;
}

int	ft_strcmp_ps(char *s1, char *s2)
{
	int	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}