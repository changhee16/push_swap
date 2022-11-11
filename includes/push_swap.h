/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccho <ccho@student.42.kr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:30:00 by ccho              #+#    #+#             */
/*   Updated: 2022/11/10 22:08:14 by ccho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	int				data;
}	t_node;

typedef struct s_info
{
	int		a_size;
	int		b_size;
	t_node	*top_a;
	t_node	*bot_a;
	t_node	*top_b;
	t_node	*bot_b;
	int		*arr;
	int		arr_num;
	int		min_a;
	int		min_b;
}	t_info;

void	int_to_stack(t_info	*info);
int		*char_to_int(char	**argv, t_info	*info, int flag);
void	error_print(int flag, t_info	*info);
void	check_argv(char	**argv, int flag, t_info	*info);
int		ft_push_atoi(const char *str, t_info	*info);
char	**ft_split(char const *s, char c);
char	**ft_free(char **split);
size_t	ft_strlen(const char *s);
int		is_renew_min_a(int a_data, int data, int min);
int		get_rot_a(t_info	*info, int data);
void	get_min_a_b(t_info	*info);
void	get_max_and_min_data(t_info	*info);
void	hard_coding_three(t_info *info);
void	hard_coding_two(t_info	*info);
void	hard_coding_five(t_info *info);
t_node	*ft_nodenew(int data);
t_node	*ft_nodelast(t_node *node);
void	ft_nodeadd_back(t_node **node, t_node *new);
void	ft_nodeclear(t_node **node);
void	pa(t_info	*info);
void	pb(t_info	*info);
void	sa(t_info	*info, int flag);
void	sb(t_info	*info, int flag);
void	ss(t_info	*info);
void	ra(t_info	*info, int flag);
void	rb(t_info	*info, int flag);
void	rr(t_info	*info);
void	rra(t_info	*info, int flag);
void	rrb(t_info	*info, int flag);
void	rrr(t_info	*info);
void	init_stack(t_info	*info);
int		get_argc(char	**argv);
void	free_info(t_info	*info);
void	divide_three(t_info	*info);
void	greedy(t_info	*info);
void	push_swap(t_info	*info);
int		is_renew_min_a(int a_data, int data, int min);
void	rotate_rr(t_info	*info);
void	rotate_ra(t_info	*info);
void	rotate_rb(t_info	*info);
void	rotate_sort(t_info	*info);
int		*argc_two_set(char	*argv, t_info	*info);
int		*argc_more_set(char	**argv, int argc, t_info	*info);
void	set_four(t_info	*info);
void	sort_int_arr(t_info *info);
int		abs(int num);
#endif
