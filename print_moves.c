/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:59:44 by ypacileo          #+#    #+#             */
/*   Updated: 2025/02/09 21:19:02 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Imprime la combinacion de movimientos indicada 
//hasta que ambos numeros queden en la cabeza de sus respectivas listas
void	ft_print_move(t_stack *stack_A, t_stack *stack_B, int a, int b)
{
	int	move;

	move = ft_get_move(stack_A, stack_B, a, b);
	if (move == 0)
		ft_print_upup(stack_A, stack_B, a, b);
	if (move == 1)
		ft_print_downdown(stack_A, stack_B, a, b);
	if (move == 2)
		ft_print_updown(stack_A, stack_B, a, b);
	if (move == 3)
		ft_print_downup(stack_A, stack_B, a, b);
}

void	ft_print_upup(t_stack *stack_A, t_stack *stack_B, int a, int b)
{
	int	i;
	int	a_moves;
	int	b_moves;

	i = 0;
	a_moves = ft_moves_up(stack_A, a);
	b_moves = ft_moves_up(stack_B, b);
	if (a_moves >= b_moves)
	{
		while (i++ < b_moves)
			ft_printf("rr\n");
		while (i++ < a_moves + 1)
			ft_printf("ra\n");
	}
	else
	{
		while (i++ < a_moves)
			ft_printf("rr\n");
		while (i++ < b_moves + 1)
			ft_printf("rb\n");
	}
}

void	ft_print_downdown(t_stack *stack_A, t_stack *stack_B, int a, int b)
{
	int	i;
	int	a_moves;
	int	b_moves;

	i = 0;
	a_moves = ft_moves_down(stack_A, a);
	b_moves = ft_moves_down(stack_B, b);
	if (a_moves >= b_moves)
	{
		while (i++ < b_moves)
			ft_printf("rrr\n");
		while (i++ < a_moves + 1)
			ft_printf("rra\n");
	}
	else
	{
		while (i++ < a_moves)
			ft_printf("rrr\n");
		while (i++ < b_moves + 1)
			ft_printf("rrb\n");
	}
}

void	ft_print_updown(t_stack *stack_A, t_stack *stack_B, int a, int b)
{
	int	i;
	int	moves;

	i = 0;
	moves = ft_moves_up(stack_A, a);
	while (i++ < moves)
		ft_printf("ra\n");
	moves += ft_moves_down(stack_B, b);
	while (i++ < moves + 1)
		ft_printf("rrb\n");
}

void	ft_print_downup(t_stack *stack_A, t_stack *stack_B, int a, int b)
{
	int	i;
	int	moves;

	i = 0;
	moves = ft_moves_down(stack_A, a);
	while (i++ < moves)
		ft_printf("rra\n");
	moves += ft_moves_up(stack_B, b);
	while (i++ < moves + 1)
		ft_printf("rb\n");
}
