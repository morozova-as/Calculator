/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evalexpr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthur- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 13:13:18 by marthur-          #+#    #+#             */
/*   Updated: 2018/09/08 13:13:20 by marthur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../evalexpr.h"

void	do_with_nbr(t_stack **numbers, t_stack **oper, char c, int *fl)
{
	char op[2];

	if (*fl == 1 && c == '-')
		*fl = -1;
	if (*oper == NULL || prior(stack_last_elem(*oper)[0]) < prior(c))
	{
		op[0] = c;
		op[1] = '\0';
		stack_push(oper, op);
	}
	else if (prior(stack_last_elem(*oper)[0]) >= prior(c))
	{
		while (prior(stack_last_elem(*oper)[0]) >= prior(c))
			make_oper(numbers, oper);
		op[0] = c;
		op[1] = '\0';
		stack_push(oper, op);
	}
}

void	do_with_bracket_close(t_stack **num, t_stack **oper, int *fl)
{
	while (stack_last_elem(*oper)[0] != '(')
		make_oper(num, oper);
	stack_pop(oper);
	*fl = 1;
}

void	do_with_bracket_open(int *fl, int *num_br, char c, t_stack **oper)
{
	char op[2];

	*fl = 1;
	*num_br = 0;
	op[0] = c;
	op[1] = '\0';
	stack_push(oper, op);
}

int		do_nbr(char *str, t_stack **numbers, int fl, int *num_br)
{
	int n;
	int diff;

	*num_br = *num_br + 1;
	stack_push(numbers, str);
	diff = ft_strlen(str);
	if (fl == -1 && (*num_br == 1))
	{
		n = ft_atoi(stack_pop(numbers));
		stack_push(numbers, ft_itoa_base(n * fl));
	}
	return (diff);
}

void	str_walk(t_stack **numbers, t_stack **oper, char *str)
{
	int		i;
	int		diff;
	int		num_br;
	int		fl;

	i = 0;
	while (str[i])
	{
		diff = 1;
		if (str[i] == ' ')
			i++;
		if (check_is_oper(str[i]))
			do_with_nbr(numbers, oper, str[i], &fl);
		else if (str[i] == '(')
			do_with_bracket_open(&fl, &num_br, str[i], oper);
		else if (str[i] == ')')
			do_with_bracket_close(numbers, oper, &fl);
		else if (check_is_num(str[i]))
		{
			diff = do_nbr(get_num(str + i), numbers, fl, &num_br);
			if (fl == -1 && num_br == 1)
				stack_pop(oper);
		}
		i += diff;
	}
}
