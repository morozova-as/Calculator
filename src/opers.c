/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opers.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthur- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 18:14:53 by marthur-          #+#    #+#             */
/*   Updated: 2018/09/09 18:14:55 by marthur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../evalexpr.h"

char	*get_num(char *str)
{
	int		i;
	char	*num;

	i = 0;
	num = (char*)malloc(sizeof(char) * 20);
	while (str[i] >= '0' && str[i] <= '9')
	{
		num[i] = str[i];
		i++;
	}
	num[i] = '\0';
	return (num);
}

int		do_op(int n, int m, char op)
{
	if (op == '+')
		return (n + m);
	if (op == '-')
		return (n - m);
	if (op == '/')
		return (n / m);
	if (op == '*')
		return (n * m);
	if (op == '%')
		return (n % m);
	return (0);
}

void	make_oper(t_stack **numbers, t_stack **oper)
{
	int num1;
	int num2;
	int n;

	num1 = ft_atoi(stack_pop(numbers));
	num2 = ft_atoi(stack_pop(numbers));
	n = do_op(num2, num1, stack_pop(oper)[0]);
	stack_push(numbers, ft_itoa_base(n));
}

char	*ft_strdup(char *src)
{
	int		l_s;
	int		i;
	char	*dup;

	l_s = 0;
	while (src[l_s])
		l_s++;
	dup = (char*)malloc(sizeof(*src) * l_s);
	i = 0;
	while (i < l_s)
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
