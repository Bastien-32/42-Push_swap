/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:44:23 by badal-la          #+#    #+#             */
/*   Updated: 2025/01/13 10:57:52 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h> 
# include <stdio.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_node
{
	int				content;
	int				lenght;
	int				pos_number;
	int				sub_sequence;
	int				index;
	int				in_lis;
	int				compt_a;
	int				compt_b;
	int				cheapest;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

/* ****************************************************************************
								sorts
**************************************************************************** */

void	sort(t_node **a, t_node **b, int size);
void	sort3(t_node **a, int size);

/* ****************************************************************************
								check_args_and_stack
**************************************************************************** */

int		check_args(int argc, char **argv);
int		is_number(const char *str);
int		check_stack(t_node **a, int size_a);
int		a_is_sorted(t_node **a, int size_a);
int		a_contain_doubles(t_node **a);

/* ****************************************************************************
								init_stack
**************************************************************************** */

void	init_stack(int argc, char **argv, t_node **a);
char	**parse_args(int argc, char **argv);
t_node	*ft_lstnew_ps(int content);
void	ft_lstadd_back_ps(t_node **lst, t_node *new);
int		ft_atoi_ps(const char *str);

/* ****************************************************************************
								commands
**************************************************************************** */

void	rotate(t_node **stack);
void	ra(t_node **a, int print);
void	rb(t_node **b, int print);
void	rr(t_node **a, t_node **b, int print);

void	reverse_rotate(t_node **stack);
void	rra(t_node **a, int print);
void	rrb(t_node **b, int print);
void	rrr(t_node **a, t_node **b, int print);

void	swap(t_node **stack);
void	sa(t_node **a, int print);
void	sb(t_node **b, int print);
void	ss(t_node **a, t_node **b, int print);

void	push(t_node **src, t_node **dest);
void	pa(t_node **a, t_node **b, int print);
void	pb(t_node **a, t_node **b, int print);

/* ****************************************************************************
								ft_split_ps
**************************************************************************** */

char	**ft_split_ps(char *str, char separator);
int		nwords_ps(char *str, char reject);
int		lenword_ps(char *str, int i, char separator);
char	*ft_substr_ps(char *str, int start, int len);
char	**ft_free_tab_ps(char **tab, size_t j);

/* ****************************************************************************
								utils
**************************************************************************** */

int		lstsize_ps(t_node *lst);
void	free_args(char **tab);
void	free_list(t_node *list);
char	**fill_split_argv(int argc, char **argv);

/* ****************************************************************************
								sort
**************************************************************************** */

void	sort(t_node **a, t_node **b, int size);
void	sort3(t_node **a, int size);
void	big_sorts(t_node **a, t_node **b, int size);

/* ****************************************************************************
								big_sorts
**************************************************************************** */

void	lis(t_node **a);
void	is_in_lis(t_node **a);
void	pos_number(t_node **a);
void	first_sort(t_node **a, t_node **b, int size);
void	second_sort(t_node **a, t_node **b);

/* ****************************************************************************
								utils_sort
**************************************************************************** */

void	update_lenghts(t_node *temp_i, t_node *temp_j, int i);
int		find_max_sub_sequence(t_node **a);
void	fill_lis(int next_subsequence, t_node **temp_a);
void	move_first_num_on_top(t_node **a);

/* ****************************************************************************
								second_sort
**************************************************************************** */

void	actualize_index(t_node **b);
void	fill_num_moves_b(t_node *b, int size_b);
t_node	*search_pos_b_in_a(t_node *a, t_node *temp_b);
void	fill_num_moves_a(t_node *a, t_node *b, int size_a);
void	sort_b_to_a(t_node **a, t_node **b);

/* ****************************************************************************
									sort_b_to_a
**************************************************************************** */

void	cheapest(t_node *b);
int		cheapest_cond(int cheapest);
int		search_cheapest(t_node **b);
void	move_number(t_node **a, t_node **b, int compt_a, int compt_b);

/* ****************************************************************************
									move_number
**************************************************************************** */

void	move_ab_neg(t_node **a, t_node **b, int compt_a, int compt_b);
void	move_ab_pos(t_node **a, t_node **b, int compt_a, int compt_b);
void	move_ab_sign_diff(t_node **a, t_node **b, int compt_a, int compt_b);

#endif