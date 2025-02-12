/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 19:52:21 by yuliano           #+#    #+#             */
/*   Updated: 2025/02/09 21:19:00 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Devuelve el numero mas pequeño de una pila
int	ft_stack_min(t_stack *stack)
{
	int		min;
	t_node	*aux;

	if (stack -> head == NULL)
		return (INT_MAX);
	min = stack -> head -> value;
	aux = stack -> head;
	while (aux != NULL)
	{
		if (aux -> value < min)
			min = aux -> value;
		aux = aux -> next;
	}
	return (min);
}

//Devuelve el numero mas grande de una pila
int	ft_stack_max(t_stack *stack)
{
	int		max;
	t_node	*aux;

	if (stack -> head == NULL)
		return (INT_MIN);
	max = stack-> head -> value;
	aux = stack -> head;
	while (aux != NULL)
	{
		if (aux -> value > max)
			max = aux -> value;
		aux = aux -> next;
	}
	return (max);
}

int	ft_sorted(t_stack *stack)
{
	t_node	*aux;

	aux = stack -> head;
	while (aux -> next != NULL)
	{
		if (aux -> value < aux -> next -> value)
			aux = aux -> next;
		else
			return (0);
	}
	return (1);
}
