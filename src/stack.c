/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthur- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 16:49:11 by marthur-          #+#    #+#             */
/*   Updated: 2018/09/08 16:49:13 by marthur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../evalexpr.h"

t_stack	*create_stack_elem(char *data)
{
	t_stack *node;

	node = (t_stack*)malloc(sizeof(*node));
	if (node)
	{
		node->data = data;
		node->next = 0;
	}
	return (node);
}

void	stack_push(t_stack **begin_list, char *data)
{
	t_stack *node;

	node = create_stack_elem(ft_strdup(data));
	if (node != 0)
	{
		node->next = *begin_list;
		*begin_list = node;
	}
}

char	*stack_pop(t_stack **begin_list)
{
	t_stack	*node;
	char	*data;

	data = "";
	if ((node = *begin_list))
	{
		data = node->data;
		*begin_list = node->next;
	}
	return (data);
}

char	*stack_last_elem(t_stack *begin_list)
{
	if (begin_list)
		return (begin_list->data);
	return ("");
}
