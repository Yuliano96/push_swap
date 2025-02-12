/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 12:14:53 by yuliano           #+#    #+#             */
/*   Updated: 2025/02/12 21:29:55 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack -> head = NULL;
	stack -> size = 0;
	return (stack);
}

void	push(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node -> value = value;
	new_node -> next = stack -> head;
	stack -> head = new_node;
	stack -> size++;
}

// Mover el tope de stack_Y a stack_X
void	ft_push(t_stack *stack_X, t_stack *stack_Y)
{
	t_node	*aux_node;

	if (!stack_Y || !stack_X || stack_Y-> head == NULL)
		return ;
	aux_node = stack_Y -> head;
	stack_Y -> head = aux_node -> next;
	aux_node -> next = stack_X -> head;
	stack_X -> head = aux_node;
	stack_X -> size++;
	stack_Y -> size--;
}

// Intercambia los primeros elementos de la pila
void	ft_swap(t_stack *stack)
{
	int	aux;

	if (stack && stack -> head && stack -> head -> next)
	{
		aux = stack -> head -> value;
		stack -> head -> value = stack -> head -> next -> value;
		stack -> head -> next -> value = aux;
	}
}

void	free_stack(t_stack	**stack)
{
	t_node	*aux;
	t_node	*other_aux;

	if (stack == NULL || *stack == NULL)
		return ;
	aux = (*stack)->head;
	while (aux != NULL)
	{
		other_aux = aux -> next;
		free(aux);
		aux = other_aux;
	}
	free(*stack);
	*stack = NULL;
}
