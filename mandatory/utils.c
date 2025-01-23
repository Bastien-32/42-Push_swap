/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:48:01 by badal-la          #+#    #+#             */
/*   Updated: 2025/01/22 16:43:54 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	lstsize_ps(t_node *lst)
{
	int		i;
	t_node	*temp_lst;

	if (!lst)
		return (0);
	i = 1;
	if (lst && !lst->next)
		return (i);
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
	if (!list || !*list)
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
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	number_is_int(t_node **a, char *nbr)
{
	int	i;
	int compt;

	compt = 0;
	i = 0;
	while (nbr[i])
		i++;
	if ((nbr[0] == '-' && i > 11) || (nbr[0] != '-' && i > 10))
		compt = 1;
	if (nbr[0] == '-')
	{
		if (i == 11 && ft_strcmp_ps("-2147483648", nbr) < 0)
			compt = 1;
	}
	else
	{
		if (i == 10 && ft_strcmp_ps("2147483647", nbr) < 0)
			compt = 1;
	}
	if (compt == 1)
	{
		write(2, "Error\n", 6);
		free_list(a);
		exit (1);
	}
}
