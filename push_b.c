/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 06:21:27 by yuliano           #+#    #+#             */
/*   Updated: 2025/02/09 21:21:23 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_place_up(t_stack *stack, int number)
{
	int	max;
	int	min;

	max = ft_stack_max(stack);
	min = ft_stack_min(stack);
	if (number > max)
		return (min);
	else
		return (max);
}

int	ft_find_place_up(t_stack *stack_A, int number_B)
{
	t_node	*aux;
	int		number_below;

	number_below = ft_check_place_up(stack_A, number_B);
	if (number_below == ft_stack_min(stack_A))
		return (number_below);
	aux = stack_A -> head;
	while (aux != NULL)
	{
		if (aux->value > number_B && aux->value < number_below)
			number_below = aux->value;
		aux = aux->next;
	}
	return (number_below);
}

//Coloca el numero mas bajo de A en el top
void	ft_num_at_top(t_stack *stack, int number)
{
	if (ft_moves_up(stack, number) < ft_moves_down(stack, number))
	{
		while (stack -> head -> value != number)
		{
			ft_rotate(stack);
			ft_printf("ra\n");
		}
	}
	else
	{
		while (stack -> head -> value != number)
		{
			ft_rev_rotate(stack);
			ft_printf("rra\n");
		}
	}
}

//Checkea si la posicion a la que va a pushear el numero de B es correcta
//Sino, rota A hasta que lo sea
void	ft_push_b(t_stack *stack_A, t_stack *stack_B)
{
	int	i;
	int	number_below;
	int	len;

	i = 0;
	len = stack_B -> size;
	while (i < len)
	{
		number_below = ft_find_place_up(stack_A, stack_B -> head -> value);
		if (stack_A -> head -> value == number_below)
		{
			ft_push(stack_A, stack_B);
			ft_printf("pa\n");
			i++;
		}
		else
			ft_num_at_top(stack_A, number_below);
	}
}
