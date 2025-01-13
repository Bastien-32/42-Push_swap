/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:48:01 by badal-la          #+#    #+#             */
/*   Updated: 2025/01/12 11:35:34 by badal-la         ###   ########.fr       */
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

