/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkki <hyeonkki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:42:58 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/07/05 14:42:59 by hyeonkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
#include <stdio.h>//꼭지우기
//input1
void	vaild_input(char *argv, int *fg);
void	check_valid_argv(int ac, char **argv);
char	*merge_input(int ac, char **av);
unsigned int	absol(int n);
void	ps_atoi(int *idx, int sign, char *str, t_deque *deq);
//input2
t_deque	*insert_data(char *str);
t_deque	*check_duplicated_num(char *str);
t_deque	*check_all_input(int ac, char **av);
t_deque	*make_stack(int ac, char **av, t_deque **deq_A);

//command
void	sa(t_deque *deq_A, t_cmd_deq *cmd_list);
void	sb(t_deque *deq_B, t_cmd_deq *cmd_list);
void	ss(t_deque *deq_A, t_deque *deq_B, t_cmd_deq *cmd_list);
int		pa(t_deque *deq_A, t_deque *deq_B, t_cmd_deq *cmd_list);
int		pb(t_deque *deq_A, t_deque *deq_B, t_cmd_deq *cmd_list);
int		ra(t_deque *deq_A, t_cmd_deq *cmd_list);
int		rb(t_deque *deq_B, t_cmd_deq *cmd_list);
void	rr(t_deque *deq_A, t_deque *deq_B, t_cmd_deq *cmd_list);
void	rra(t_deque *deq_A, t_cmd_deq *cmd_list);
void	rrb(t_deque *deq_B, t_cmd_deq *cmd_list);
void	rrr(t_deque *deq_A, t_deque *deq_B, t_cmd_deq *cmd_list);

//pre_sort1
void	search_stack(t_deque *deq, int base, int *max, int *min);
t_sort	*make_repository(int len);
int		find_digit_len(t_ll num);
int		last_digit_num(long long n, int dg);
void	make_queue(t_queue *queue[10], int idx);
//pre_sort2
void	push_queue(t_ll num, t_queue *queue[10], int q_num);
void	clear_queue(t_queue *queue[10]);
void	putin_data_in_array(t_deque *deq, t_sort *repo, t_ll bios);
void	pull_queue(t_sort *repo, t_queue *queue[10]);
void	pre_sorting(t_sort *repo, int dg);
//pre_sort3
void	before_bios(t_sort *repo, t_ll bios);
void	radix_sort(t_deque *deq, t_sort *repo, t_ll bios, int max);
void	pre_sort(t_deque *deq, int len, t_pivot *piv);

//pre_sort_utgils
t_sort	*make_repository(int len);

//sort1
int		reverse_sort(t_deque *deq_A, t_deque *deq_B, t_cmd_deq *cmd);
void	print_deq(t_deque *deq_A, t_deque *deq_B);//지우기
void	except_sort(t_deque *deq_A, t_deque *deq_B, int len, t_cmd_deq *cmd);
void	reverse_stack(t_deque *deq_A, t_deque *deq_B, t_info *info);
void	divide_B(t_deque *deq_A, t_deque *deq_B, t_info *info, int len);
void	divide_A(t_deque *deq_A, t_deque *deq_B, t_info *info, int len);

//sort2
void	B_to_A(t_deque *deq_A, t_deque *deq_B, t_info *info, int len);
void	A_to_B(t_deque *deq_A, t_deque *deq_B, t_info *info, int len);
t_info	*q_sort(t_deque *deq_A, t_deque *deq_B);

//sort_utils
int		small_num(int n1, int n2);
int		find_max(int len, int *arr);
int		find_min(int len, int *arr);

//sort_check_status
int		check_already_sorted(t_deque *deq);
int		check_reverse_sorted(t_deque *deq, int len);
//sort_optimize
void	real_three_number_sort(t_deque *deq_A, t_cmd_deq *cmd_list);
void	other_three_number_sort(t_deque *deq_A, t_cmd_deq *cmd_list);
void	insert_four_number(t_deque *deq_A, int *arr, int *max, int *min);
void	real_four_number_sort(t_deque *deq_A, t_deque *deq_B, t_cmd_deq *cmd);
void	other_four_number_sort(t_deque *deq_A, t_deque *deq_B, t_cmd_deq *cmd);


//optimize
void	print_cmd(t_info *info);
int		optimize_command(t_cmd_deq *cmd);
#endif
