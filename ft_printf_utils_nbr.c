/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_nbr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosta-a <acosta-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 08:57:39 by acosta-a          #+#    #+#             */
/*   Updated: 2022/05/19 13:57:56 by acosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_nbr(char *s, int fd, int len, int flag)
{
	int	i;

	if (s[0] == 0)
	{
		ft_putchar_fd('0', fd);
		return (1);
	}
	i = len - 1;
	if (flag == 1)
		len = len + 1;
	if (s == NULL)
	{
		write (fd, "(null)", 6);
		return (6);
	}
	while (i >= 0 && s[i])
	{
		ft_putchar_fd(s[i], fd);
		i--;
	}
	return (len);
}

int	ft_putnbr_len(int n, int fd)
{
	unsigned int	nb;
	int				len;
	char			c[12];
	int				flag;

	len = 0;
	flag = 0;
	nb = (unsigned int)(n);
	{
		if (n == 0)
			c[0] = 0;
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			nb = (n * (-1));
			flag = 1;
		}
		while (nb > 0)
		{
			c[len++] = nb % 10 + '0';
			nb = nb / 10;
		}
	}
	return (ft_putstr_nbr (c, fd, len, flag));
}

int	ft_uputnbr_len(unsigned int n, int fd)
{
	int				len;
	char			c[11];
	unsigned int	nb;

	nb = n;
	len = 0;
	{
		if (nb == 0)
		{
			ft_putchar_fd('0', fd);
			return (1);
		}
		while (nb > 0)
		{
			c[len++] = nb % 10 + '0';
			nb = nb / 10;
		}
	}
	return (ft_putstr_nbr (c, fd, len, 0));
}
