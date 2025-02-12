/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 06:44:54 by yuliano           #+#    #+#             */
/*   Updated: 2025/02/09 21:19:04 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Ejecuta la combinacion de movimientos indicada 
//hasta que ambos numeros queden en la cabeza de sus respectivas listas
void	ft_apply_move(t_stack *stack_A, t_stack *stack_B, int a, int b)
{
	int	move;

	move = ft_get_move(stack_A, stack_B, a, b);
	if (move == 0)
		ft_apply_upup(stack_A, stack_B, a, b);
	if (move == 1)
		ft_apply_downdown(stack_A, stack_B, a, b);
	if (move == 2)
		ft_apply_updown(stack_A, stack_B, a, b);
	if (move == 3)
		ft_apply_downup(stack_A, stack_B, a, b);
}

void	ft_apply_upup(t_stack *stack_A, t_stack *stack_B, int a, int b)
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
			ft_rr_rotate(stack_A, stack_B);
		while (i++ < a_moves + 1)
			ft_rotate(stack_A);
	}
	else
	{
		while (i++ < a_moves)
			ft_rr_rotate(stack_A, stack_B);
		while (i++ < b_moves + 1)
			ft_rotate(stack_B);
	}
}

void	ft_apply_downdown(t_stack *stack_A, t_stack *stack_B, int a, int b)
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
			ft_rr_rev_rotate(stack_A, stack_B);
		while (i++ < a_moves + 1)
			ft_rev_rotate(stack_A);
	}
	else
	{
		while (i++ < a_moves)
			ft_rr_rev_rotate(stack_A, stack_B);
		while (i++ < b_moves + 1)
			ft_rev_rotate(stack_B);
	}
}

void	ft_apply_updown(t_stack *stack_A, t_stack *stack_B, int a, int b)
{
	int	i;
	int	moves;

	i = 0;
	moves = ft_moves_up(stack_A, a);
	while (i++ < moves)
		ft_rotate(stack_A);
	moves += ft_moves_down(stack_B, b);
	while (i++ < moves + 1)
		ft_rev_rotate(stack_B);
}

void	ft_apply_downup(t_stack *stack_A, t_stack *stack_B, int a, int b)
{
	int	i;
	int	moves;

	i = 0;
	moves = ft_moves_down(stack_A, a);
	while (i++ < moves)
		ft_rev_rotate(stack_A);
	moves += ft_moves_up(stack_B, b);
	while (i++ < moves + 1)
		ft_rotate(stack_B);
}
