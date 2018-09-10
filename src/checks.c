/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthur- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 18:13:08 by marthur-          #+#    #+#             */
/*   Updated: 2018/09/09 18:13:09 by marthur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../evalexpr.h"

int		check_is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		check_is_oper(char c)
{
	if (c == '+' || c == '-' || c == '/' || c == '*' || c == '%')
		return (1);
	return (0);
}

int		prior(char c)
{
	if (c == '(' || c == ')')
		return (0);
	if (c == '+' || c == '-')
		return (1);
	if (c == '*' || c == '/' || c == '%')
		return (2);
	return (-1);
}

int		size_nbr(int n)
{
	int i;

	if (n < 0)
		n *= -1;
	i = 0;
	while ((n = n / 10))
		i++;
	return (i);
}

int		ft_strlen(char *str)
{
	int s;

	s = 0;
	while (*str)
	{
		s++;
		str++;
	}
	return (s);
}
