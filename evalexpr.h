/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evalexpr.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthur- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 15:31:30 by marthur-          #+#    #+#             */
/*   Updated: 2018/09/08 15:31:31 by marthur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVALEXPR_H
# define EVALEXPR_H

# include <unistd.h>
# include <stdlib.h>

typedef struct		s_stack
{
	struct s_stack	*next;
	char			*data;
}					t_stack;

int					ft_atoi(char *str);
int					eval_expr(char *str);
void				ft_putchar(char c);
void				ft_putnbr(int nb);
int					ft_strlen(char *str);
t_stack				*create_stack_elem(char *data);
void				stack_push(t_stack **begin_list, char *data);
char				*stack_pop(t_stack **begin_list);
char				*stack_last_elem(t_stack *begin_list);
char				*ft_strdup(char *src);
char				*ft_itoa_base(int value);
int					prior(char c);
int					check_is_oper(char c);
int					check_is_num(char c);
char				*get_num(char *str);
int					do_op(int n, int m, char op);
void				make_oper(t_stack **numbers, t_stack **oper);
int					size_nbr(int n);
void				str_walk(t_stack **numbers, t_stack **oper, char *str);

#endif
