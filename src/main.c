/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthur- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 15:31:00 by marthur-          #+#    #+#             */
/*   Updated: 2018/09/08 15:31:02 by marthur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../evalexpr.h"

int		eval_expr(char *str)
{
	t_stack	*numbers;
	t_stack	*oper;
	int		i;

	i = 0;
	numbers = NULL;
	oper = NULL;
	str_walk(&numbers, &oper, str);
	while (oper)
		make_oper(&numbers, &oper);
	return (ft_atoi(stack_pop(&numbers)));
}

int		main(int argc, char **argv)
{
	if (argc > 1)
	{
		ft_putnbr(eval_expr(argv[1]));
		ft_putchar('\n');
	}
	return (0);
}
