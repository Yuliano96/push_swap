/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 11:54:09 by yuliano           #+#    #+#             */
/*   Updated: 2025/02/12 22:01:46 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "ft_printf/libftprintf.h"
# include "libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	int		size;
}	t_stack;

t_stack	*init_stack(void);
void	push(t_stack *stack, int value);
void	ft_push(t_stack *stack_X, t_stack *stack_Y);
void	free_stack(t_stack **stack);
void	ft_swap(t_stack *t_stack);
void	ft_rotate(t_stack *stack);
void	ft_rev_rotate(t_stack *stack);
void	ft_ss_swap(t_stack *stack_X, t_stack *stack_y);
void	ft_rr_rotate(t_stack *stack_X, t_stack *stack_Y);
void	ft_rr_rev_rotate(t_stack *stack_X, t_stack *stack_Y);
int		ft_sorted(t_stack *stack);
void	mecanical_turk(t_stack *stack_A, t_stack *stack_B);
int		ft_min_index(int move[]);
int		ft_get_move(t_stack *stack_A, t_stack *stack_B, int a, int b);
int		ft_stack_min(t_stack *stack);
int		ft_stack_max(t_stack *stack);
int		ft_sorted(t_stack *stack);
int		ft_moves(t_stack *stack_A, t_stack *stack_B, int number);
int		ft_moves_up(t_stack *stack, int number);
int		ft_moves_down(t_stack *stack, int number);
int		ft_aup_bup(t_stack *stack_A, t_stack *stack_B, int a, int b);
int		ft_adown_bdown(t_stack *stack_A, t_stack *stack_B, int a, int b);
int		ft_aup_bdown(t_stack *stack_A, t_stack *stack_B, int a, int b);
int		ft_adown_bup(t_stack *stack_A, t_stack *stack_B, int a, int b);
void	ft_apply_upup(t_stack *stack_A, t_stack *stack_B, int a, int b);
void	ft_apply_downdown(t_stack *stack_A, t_stack *stack_B, int a, int b);
void	ft_apply_updown(t_stack *stack_A, t_stack *stack_B, int a, int b);
void	ft_apply_downup(t_stack *stack_A, t_stack *stack_B, int a, int b);
void	ft_apply_move(t_stack *stack_A, t_stack *stack_B, int a, int b);
int		ft_check_place_des(t_stack *stack, int number);
int		ft_find_place_des(t_stack *stack, int number);
int		ft_fastest_number(t_stack *stack_A, t_stack *stack_B);
void	ft_sort_num(t_stack *stack_A, t_stack *stack_B, int fastest_number);
void	ft_sort_b(t_stack *stack_A, t_stack *stack_B);
void	ft_min_at_top(t_stack *stack_A);
void	ft_max_at_top(t_stack *stack_A);
void	sort_three(t_stack *stack_A);
int		ft_check_place_up(t_stack *stack, int number);
int		ft_find_place_des(t_stack *stack_B, int number_A);
void	ft_num_at_top(t_stack *stack, int number);
void	ft_push_b(t_stack *stack_A, t_stack *stack_B);
void	ft_lowest_at_top(t_stack *stack_A);
int		check_is_num(const char *s);
long	long_atoi(const char *s);
int		ft_validations(const char *s);
int		check_duplicates(t_stack *stack, int new_value);
int		ft_check_wrong(char **input, t_stack *stack);
void	ft_print_upup(t_stack *stack_A, t_stack *stack_B, int a, int b);
void	ft_print_downdown(t_stack *stack_A, t_stack *stack_B, int a, int b);
void	ft_print_updown(t_stack *stack_A, t_stack *stack_B, int a, int b);
void	ft_print_downup(t_stack *stack_A, t_stack *stack_B, int a, int b);
void	ft_print_move(t_stack *stack_A, t_stack *stack_B, int a, int b);
int		count_char(char **str);
void	ft_free_input( char ***m, int i);
void	ft_free(t_stack **stack_a, t_stack **stack_b, char **input, int argc);

#endif
