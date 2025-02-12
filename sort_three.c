/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 06:53:21 by yuliano           #+#    #+#             */
/*   Updated: 2025/02/02 18:08:18 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *stack_A)
{
	if (ft_sorted(stack_A))
		return ;
	else if (ft_stack_min(stack_A) == stack_A -> head -> value)
		ft_min_at_top(stack_A);
	else if (ft_stack_max(stack_A) == stack_A -> head -> value)
		ft_max_at_top(stack_A);
	else if (stack_A -> head -> value > stack_A -> head -> next -> value)
	{
		ft_swap(stack_A);
		ft_printf("sa\n");
	}
	else
	{
		ft_rev_rotate(stack_A);
		ft_printf("rra\n");
	}
}

void	ft_min_at_top(t_stack *stack_A)
{
	ft_swap(stack_A);
	ft_printf("sa\n");
	ft_rotate(stack_A);
	ft_printf("ra\n");
}

void	ft_max_at_top(t_stack *stack_A)
{
	ft_rotate(stack_A);
	ft_printf("ra\n");
	if (ft_sorted(stack_A) == 0)
	{
		ft_swap(stack_A);
		ft_printf("sa\n");
	}
}
