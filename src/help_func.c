/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthur- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 10:52:29 by marthur-          #+#    #+#             */
/*   Updated: 2018/08/28 11:42:27 by marthur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../evalexpr.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	*make_str(int len, int value, int fl)
{
	char	*rez;
	int		i;

	rez = (char*)malloc(sizeof(char) * (len + 1));
	i = len - 1;
	while (i >= 0)
	{
		rez[i--] = value % 10 + '0';
		value /= 10;
	}
	if (fl == -1)
		rez[0] = '-';
	rez[len] = '\0';
	return (rez);
}

char	*ft_itoa_base(int value)
{
	int		fl;
	int		n_val;
	int		len;
	char	*rez;

	fl = 1;
	if (value == -2147483648)
		return ("-2147483648");
	if (value == 0)
		return ("0");
	n_val = value;
	len = size_nbr(n_val) + 1;
	if (value < 0)
	{
		len++;
		fl = -1;
		value *= -1;
	}
	rez = make_str(len, value, fl);
	return (rez);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		if (nb == -2147483648)
		{
			ft_putchar('2');
			ft_putnbr(147483648);
			return ;
		}
		nb *= -1;
	}
	if (nb / 10 > 0)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

int		ft_atoi(char *str)
{
	int fl;
	int i;
	int ch;

	fl = 1;
	i = 0;
	while (str[i] == '\n' || str[i] == ' ' || str[i] == '\t' ||\
			str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
	{
		fl = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	ch = 0;
	while (str[i] >= '0' && str[i] <= '9' && str[i])
		ch = ch * 10 + (str[i++] - '0');
	return (ch * fl);
}
