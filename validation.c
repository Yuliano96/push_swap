/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypacileo <ypacileo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 19:24:47 by yuliano           #+#    #+#             */
/*   Updated: 2025/02/08 21:08:38 by ypacileo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_is_num(const char *s)
{
	int	i;
	int	check;

	if (!s)
		return (0);
	i = 0;
	check = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'
		|| s[i] == '\r' || s[i] == '\v' || s[i] == '\f')
		i++;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (ft_isdigit(s[i]))
	{
		check = 1;
		i++;
	}
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'
		|| s[i] == '\r' || s[i] == '\v' || s[i] == '\f')
		i++;
	if (s[i] != '\0')
		return (0);
	return (check);
}

long	long_atoi(const char *s)
{
	int		i;
	long	number;
	int		sign;

	i = 0;
	sign = 1;
	number = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'
		|| s[i] == '\r' || s[i] == '\v' || s[i] == '\f' )
		i++;
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (s[i] == '+')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		number = number * 10 + s[i] - 48;
		i++;
	}
	return (number * sign);
}

int	ft_validations(const char *s)
{
	long	num;

	if (!check_is_num(s))
		return (0);
	num = long_atoi(s);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	return (1);
}

int	check_duplicates(t_stack *stack, int new_value)
{
	t_node	*aux;

	aux = stack->head;
	while (aux != NULL)
	{
		if (aux -> value == new_value)
			return (0);
		aux = aux -> next;
	}
	return (1);
}

int	ft_check_wrong(char **input, t_stack *stack)
{
	int	num;
	int	i;

	i = count_char(input) - 1;
	while (i >= 0)
	{
		if (!ft_validations(input[i]))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		num = long_atoi(input[i]);
		if (!check_duplicates(stack, num))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		push(stack, num);
		i--;
	}
	return (1);
}
