/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 17:29:39 by badal-la          #+#    #+#             */
/*   Updated: 2024/12/25 17:53:47 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"

# include <stdlib.h>
# include <unistd.h>

typedef struct s_pslist
{
	int				content;
	struct s_pslist	*next;
}					t_pslist;

t_pslist	*sa_ps(t_pslist *stack);
t_pslist	*rra_ps(t_pslist **stack);
void	ra_ps(t_pslist **stack);
void	pb_ps(t_pslist **stack_a, t_pslist **stack_b);
void	printlist(t_pslist *temp_a, t_pslist *temp_b);

#endif