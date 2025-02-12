/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mecanical_turk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 06:35:27 by yuliano           #+#    #+#             */
/*   Updated: 2025/02/09 21:18:53 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mecanical_turk(t_stack *stack_A, t_stack *stack_B)
{
	int	i;

	i = 0;
	if (ft_sorted(stack_A))
		return ;
	if (stack_A -> size == 2 && ft_sorted(stack_A) == 0)
	{
		ft_swap(stack_A);
		ft_printf("sa\n");
		return ;
	}
	while (stack_A -> size > 3 && i++ < 2)
	{
		ft_push(stack_B, stack_A);
		ft_printf("pb\n");
	}
	if (stack_B -> head != NULL && stack_A -> size > 3)
		ft_sort_b(stack_A, stack_B);
	if (stack_A -> size == 3)
		sort_three(stack_A);
	if (stack_B -> head != NULL && stack_A -> size == 3)
		ft_push_b(stack_A, stack_B);
	if (ft_sorted(stack_A) == 0)
		ft_lowest_at_top(stack_A);
}

//Coloca el numero mas bajo de A en el top
void	ft_lowest_at_top(t_stack *stack_A)
{
	int	min;

	min = ft_stack_min(stack_A);
	if (ft_moves_up(stack_A, min) < ft_moves_down(stack_A, min))
	{
		while (stack_A -> head -> value != min)
		{
			ft_rotate(stack_A);
			ft_printf("ra\n");
		}
	}
	else
	{
		while (stack_A -> head -> value != min)
		{
			ft_rev_rotate(stack_A);
			ft_printf("rra\n");
		}
	}
}
