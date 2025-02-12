/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 12:30:56 by yuliano           #+#    #+#             */
/*   Updated: 2025/02/09 21:18:58 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_place_des(t_stack *stack, int number)
{
	int	max;
	int	min;

	max = ft_stack_max(stack);
	min = ft_stack_min(stack);
	if (number < min)
		return (max);
	else
		return (min);
}

//Busca el numero que tiene que quedar debajo del numero que se quiere pushear
int	ft_find_place_des(t_stack *stack_B, int number_A)
{
	int		number_below;
	t_node	*aux;

	number_below = ft_check_place_des(stack_B, number_A);
	if (number_below == ft_stack_max(stack_B))
		return (number_below);
	aux = stack_B -> head;
	while (aux != NULL)
	{
		if (aux -> value < number_A && aux -> value > number_below)
			number_below = aux -> value;
		aux = aux->next;
	}
	return (number_below);
}

int	ft_fastest_number(t_stack *stack_A, t_stack *stack_B)
{
	t_node	*aux;
	int		number;
	int		fastest;
	int		moves;
	int		min_moves;

	aux = stack_A -> head;
	fastest = aux -> value;
	min_moves = INT_MAX;
	while (aux != NULL)
	{
		number = aux -> value;
		moves = ft_moves(stack_A, stack_B, number);
		if (moves < min_moves)
		{
			min_moves = moves;
			fastest = number;
		}
		aux = aux -> next;
		if (moves == 0)
			return (fastest);
	}
	return (fastest);
}

//Busca la combinacion de movimientos idonea para pasar un numero especifico
//Imprime los movimientos, los ejecuta, imprimer el push y lo ejecuta
void	ft_sort_num(t_stack *stack_A, t_stack *stack_B, int fastest_number)
{
	int	a;
	int	b;

	a = fastest_number;
	b = ft_find_place_des(stack_B, a);
	ft_print_move(stack_A, stack_B, a, b);
	ft_apply_move(stack_A, stack_B, a, b);
}

//Pushea los numeros de A a B de forma ordenada
void	ft_sort_b(t_stack *stack_A, t_stack *stack_B)
{
	int	i;
	int	len;
	int	fastest_number;

	i = 0;
	len = stack_A -> size;
	while (i < len - 3)
	{
		fastest_number = ft_fastest_number(stack_A, stack_B);
		ft_sort_num(stack_A, stack_B, fastest_number);
		ft_push(stack_B, stack_A);
		ft_printf("pb\n");
		i++;
	}
}
