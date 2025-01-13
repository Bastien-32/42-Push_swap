/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_ps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:39:01 by badal-la          #+#    #+#             */
/*   Updated: 2025/01/08 18:18:36 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nwords_ps(char *str, char separator)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] != separator && (i == 0 || str[i - 1] == separator))
			count++;
		i++;
	}
	return (count);
}

int	lenword_ps(char *str, int i, char separator)
{
	int	count;

	count = 0;
	while (str[i + count] && str[i + count] != separator)
		count++;
	return (count);
}

static char	**free_split_ps(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}

char	*ft_substr_ps(char *str, int start, int len)
{
	int		i;
	char	*dup;

	i = 0;
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	while (i < len)
	{
		dup[i] = str[start + i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	**ft_split_ps(char *str, char separator)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	j = 0;
	tab = (char **)malloc(sizeof(char *) * (nwords_ps(str, separator) + 1));
	if (!tab)
		return (NULL);
	while (str[i])
	{
		if (str[i] != separator)
		{
			tab[j] = ft_substr_ps(str, i, lenword_ps(str, i, separator));
			if (!tab[j])
				return (free_split_ps(tab));
			j++;
			i += lenword_ps(str, i, separator);
		}
		else
			i++;
	}
	tab[j] = NULL;
	return (tab);
}