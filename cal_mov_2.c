/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_mov_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 06:27:00 by yuliano           #+#    #+#             */
/*   Updated: 2025/02/09 21:00:06 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// Ambas pilas hacia arriba
int	ft_aup_bup(t_stack *stack_A, t_stack *stack_B, int a, int b)
{
	int	a_moves;
	int	b_moves;

	a_moves = ft_moves_up(stack_A, a);
	b_moves = ft_moves_up(stack_B, b);
	if (a_moves > b_moves)
		return (a_moves);
	else
		return (b_moves);
}

// Amabas pilas hacia abajo
int	ft_adown_bdown(t_stack *stack_A, t_stack *stack_B, int a, int b)
{
	int	a_moves;
	int	b_moves;

	a_moves = ft_moves_down(stack_A, a);
	b_moves = ft_moves_down(stack_B, b);
	if (a_moves > b_moves)
		return (a_moves);
	else
		return (b_moves);
}

// movimentos hacia arriba de la pila A y movientos hacia abajo de la pila B
int	ft_aup_bdown(t_stack *stack_A, t_stack *stack_B, int a, int b)
{
	int	moves;

	moves = ft_moves_up(stack_A, a);
	moves += ft_moves_down(stack_B, b);
	return (moves);
}

// movimientos hacia abajo de la pila A y movimientos hacia arriba de la pila b
int	ft_adown_bup(t_stack *stack_A, t_stack *stack_B, int a, int b)
{
	int	moves;

	moves = ft_moves_down(stack_A, a);
	moves += ft_moves_up(stack_B, b);
	return (moves);
}
