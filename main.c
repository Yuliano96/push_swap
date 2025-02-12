/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 12:40:27 by yuliano           #+#    #+#             */
/*   Updated: 2025/02/12 22:38:22 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_stack **stack_a, t_stack **stack_b, char **input, int argc)
{
	if (argc == 2)
		ft_free_input(&input, count_char(input));
	free_stack(stack_a);
	free_stack(stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**input;

	if (argc == 1)
		return (EXIT_SUCCESS);
	if (argc == 2)
		input = ft_split(argv[1], ' ');
	else
		input = &argv[1];
	stack_b = init_stack();
	stack_a = init_stack();
	if (ft_check_wrong(input, stack_a) == 0)
	{
		ft_free(&stack_a, &stack_b, input, argc);
		return (EXIT_FAILURE);
	}
	mecanical_turk(stack_a, stack_b);
	ft_free(&stack_a, &stack_b, input, argc);
	return (EXIT_SUCCESS);
}
