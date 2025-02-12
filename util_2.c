/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 06:32:47 by yuliano           #+#    #+#             */
/*   Updated: 2025/02/12 22:06:00 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min_index(int move[])
{
	int	i;
	int	min;
	int	index;

	min = move[0];
	index = 0;
	i = 1;
	while (i < 4)
	{
		if (min > move[i])
		{
			min = move[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	ft_get_move(t_stack *stack_A, t_stack *stack_B, int a, int b)
{
	int	moves[4];
	int	index_move;

	moves[0] = ft_aup_bup(stack_A, stack_B, a, b);
	moves[1] = ft_adown_bdown(stack_A, stack_B, a, b);
	moves[2] = ft_aup_bdown(stack_A, stack_B, a, b);
	moves[3] = ft_adown_bup(stack_A, stack_B, a, b);
	index_move = ft_min_index(moves);
	return (index_move);
}

int	count_char(char **str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

void	ft_free_input( char ***m, int count_char)
{
	int	index;

	if (m == NULL || *m == NULL)
		return ;
	index = 0;
	while (index < count_char)
	{
		free((*m)[index]);
		index ++;
	}
	free(*m);
	*m = NULL;
}
