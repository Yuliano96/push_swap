/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:00:40 by yuliano           #+#    #+#             */
/*   Updated: 2025/02/09 22:27:34 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//El primer elemento se convierte en el último.
//Desplaza hacia arriba todos los elementos del stack
void	ft_rotate(t_stack *stack)
{
	t_node	*aux;
	t_node	*last;

	if (!stack || !stack->head || !stack->head->next)
		return ;
	aux = stack -> head;
	stack -> head = stack->head->next;
	aux -> next = NULL;
	last = stack -> head;
	while (last -> next != NULL)
		last = last -> next;
	last -> next = aux;
}

//El último elemento se convierte en el primero.
// Desplaza hacia abajo todos los elementos del stack
void	ft_rev_rotate(t_stack *stack)
{
	t_node	*last;
	t_node	*second_last;

	if (!stack || !stack -> head || !stack -> head -> next)
		return ;
	last = stack -> head;
	second_last = NULL;
	while (last -> next != NULL)
	{
		second_last = last;
		last = last -> next;
	}
	second_last -> next = NULL;
	last -> next = stack -> head;
	stack -> head = last;
}

void	ft_ss_swap(t_stack *stack_X, t_stack *stack_y)
{
	ft_swap(stack_X);
	ft_swap(stack_y);
}

void	ft_rr_rotate(t_stack *stack_X, t_stack *stack_Y)
{
	ft_rotate(stack_X);
	ft_rotate(stack_Y);
}

void	ft_rr_rev_rotate(t_stack *stack_X, t_stack *stack_Y)
{
	ft_rev_rotate(stack_X);
	ft_rev_rotate(stack_Y);
}
