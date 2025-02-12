/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_mov_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 06:14:09 by yuliano           #+#    #+#             */
/*   Updated: 2025/02/09 21:19:10 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Calcula el n de rotaciones hacia arriba para colocar un numero en top
int	ft_moves_up(t_stack *stack, int number)
{
	t_node	*aux;
	int		moves;

	aux = stack -> head;
	moves = 0;
	while (aux -> value != number && aux != NULL)
	{
		moves++;
		aux = aux -> next;
	}
	if (aux == NULL)
		return (-1);
	return (moves);
}

//Calcula el n de rotaciones hacia abajo para colocar un numero en top
int	ft_moves_down(t_stack *stack, int number)
{
	t_node	*aux;
	int		moves;

	aux = stack -> head;
	moves = 0;
	while (aux -> value != number && aux != NULL)
	{
		moves++;
		aux = aux -> next;
	}
	if (aux == NULL)
		return (-1);
	return (stack -> size - moves);
}

int	ft_moves(t_stack *stack_A, t_stack *stack_B, int number_A)
{
	int	a;
	int	b;
	int	moves[4];
	int	min_moves;
	int	i;

	a = number_A;
	b = ft_find_place_des(stack_B, a);
	moves[0] = ft_aup_bup(stack_A, stack_B, a, b);
	moves[1] = ft_adown_bdown(stack_A, stack_B, a, b);
	moves[2] = ft_aup_bdown(stack_A, stack_B, a, b);
	moves[3] = ft_adown_bup(stack_A, stack_B, a, b);
	min_moves = moves[0];
	i = 0;
	while (i < 4)
	{
		if (moves[i] < min_moves)
			min_moves = moves[i];
		i++;
	}
	return (min_moves);
}
